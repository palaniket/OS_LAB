// //  reader and writer problem using semaphore
// #include <bits/stdc++.h>
// using namespace std;
// // Define a shared resource
// int sharedResource = 0;

// // Mutex and condition variables for synchronization
// mutex mtx;
// condition_variable readCV, writeCV;
// int readersCount = 0;

// // Reader function
// void reader(int id) {
//     while (true) {
//         // Lock the mutex
//         unique_lock<mutex> lock(mtx);

//         // Increment the number of active readers
//         readersCount++;

//         // Wait for the writer to finish if any
//         writeCV.wait(lock, []{ return readersCount == 1; });

//         // Critical section: reading from the shared resource
//         cout << "Reader " << id << " reads: " << sharedResource << endl;

//         // Decrement the number of active readers
//         readersCount--;

//         // Notify the writer if no readers left
//         if (readersCount == 0) {
//             writeCV.notify_one();
//         }

//         // Unlock the mutex
//         lock.unlock();

//         // Simulate some delay
//         this_thread::sleep_for(chrono::milliseconds(1000));
//     }
// }

// // Writer function
// void writer(int id) {
//     while (true) {
//         // Lock the mutex
//         unique_lock<mutex> lock(mtx);

//         // Wait for the readers to finish
//         writeCV.wait(lock, []{ return readersCount == 0; });

//         // Critical section: writing to the shared resource
//         sharedResource++;
//         cout << "Writer " << id << " writes: " << sharedResource << endl;

//         // Notify all readers
//         readCV.notify_all();

//         // Unlock the mutex
//         lock.unlock();

//         // Simulate some delay
//         this_thread::sleep_for(chrono::milliseconds(2000));
//     }
// }

// int main() {
//     // Create reader and writer threads
//     vector<thread> readers, writers;
//     for (int i = 1; i <= 3; ++i) {
//         readers.emplace_back(reader, i);
//         writers.emplace_back(writer, i);
//     }

//     // Join threads
//     for (auto& readerThread : readers) {
//         readerThread.join();
//     }
//     for (auto& writerThread : writers) {
//         writerThread.join();
//     }

//     return 0;
// }