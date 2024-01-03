#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include "mutex"

std::mutex coutMutex;

void task(int threadId) {
    std::lock_guard<std::mutex> guard(coutMutex);
    // Perform some work in the thread
    std::cout << "Thread " << threadId << " is running" << std::endl;
}

int main() {
    std::vector<std::thread> threads;

    // Creating and adding threads to the vector
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(task, i));
    }

    // Joining all threads with the main thread
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
