//
//  Runner.cpp
//  magic_proof
//
//  Created by Ramsey Hage on 2022-01-29.
//

#include "Runner.hpp"

#include <iostream>
#include <future>
#include <thread>
#include <list>
#include <barrier>
#include <unistd.h>

static std::barrier<> syncpoint(std::thread::hardware_concurrency());
static std::barrier syncpoint_2(std::thread::hardware_concurrency(), []() noexcept {
    std::cout << "completion function called" << std::endl;
});

static void run(std::shared_future<int>& runner_future)
{
    static std::mutex mutex;
    runner_future.wait();
    
    int const sec = rand() % 10;
    sleep(sec);
    
    syncpoint.arrive_and_wait();
    
    // -fsanitize=thread listed the cout as a potential race between threads
    mutex.lock();
    std::cout << "Thread " << pthread_self() << " done\n";
    mutex.unlock();

    syncpoint_2.arrive_and_wait();
}

int do_runners(void)
{
    unsigned const num_cpu = std::thread::hardware_concurrency();

    std::promise<int> runner_promise;
    std::shared_future<int> runner_future = runner_promise.get_future();
    std::list<std::thread*> thread_list;
    for(unsigned nextIdx=0; nextIdx < num_cpu; nextIdx++) {
        thread_list.push_back(new std::thread( run, std::ref(runner_future) ));
    }
    
    runner_promise.set_value(1);
    
    std::thread* nextThr;
    for( auto iter = thread_list.begin(); iter != thread_list.end(); iter++) {
        nextThr = *iter;
        nextThr->join();
        delete nextThr;
    }
    thread_list.clear();
    
    return 0;
}
