//
//  Runner.cpp
//  magic_proof
//
//  Created by Ramsey Hage on 2022-01-29.
//

#include "Runner.hpp"

#include <iostream>
#include <mutex>
#include <future>
#include <thread>
#include <list>
#include <barrier>
#include <unistd.h>
#include <stdlib.h>

static void run(std::shared_future<int>& runner_future,
                std::mutex& mut,
                std::barrier<>& syncpoint,
                std::barrier<std::function<void()>>& syncpoint_2)
{
    runner_future.wait();

    int const sec = arc4random() % 10;
    sleep(sec);

    syncpoint.arrive_and_wait();

    {// scoped_lock
        // -fsanitize=thread listed the cout as a potential race between threads
        std::scoped_lock lck(mut);
        std::cout << "Thread " << pthread_self() << " done\n";
    }

    syncpoint_2.arrive_and_wait();
}

int do_runners(void)
{
    unsigned num_cpu = std::thread::hardware_concurrency();
    if (num_cpu == 0) {
        // was not well defined or not able to compute
        num_cpu = 4;
    }

    std::mutex mut;
    std::barrier<> syncpoint(num_cpu);

    auto completion_func = []() noexcept {
        std::cout << "Completion function called\n";
    };
    std::barrier<std::function<void()>> syncpoint_2(num_cpu, completion_func);

    std::promise<int> runner_promise;
    std::shared_future<int> runner_future = runner_promise.get_future();
    std::list<std::thread> thread_list;
    for(unsigned nextIdx=0; nextIdx < num_cpu; nextIdx++) {
        thread_list.emplace_back(std::thread(
                                    run,
                                    std::ref(runner_future),
                                    std::ref(mut),
                                    std::ref(syncpoint),
                                    std::ref(syncpoint_2)
                                 ));
    }

    runner_promise.set_value(1);

    for(auto& nextThr : thread_list) {
        nextThr.join();
    }
    thread_list.clear();

    return 0;
}
