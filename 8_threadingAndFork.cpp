// #include <iostream>
// #include <thread>
// #include <unistd.h>

// using namespace std;

// // Function to be executed by a thread
// void threadFunction() {
//     cout << "Thread ID: " << this_thread::get_id() << endl;
// }

// int main() {
//     // Threading
//     thread t1(threadFunction);
//     thread t2(threadFunction);

//     // Forking
//     pid_t pid = fork();

//     if (pid == -1) {
//         // Fork failed
//         cerr << "Fork failed." << endl;
//         return 1;
//     } else if (pid == 0) {
//         // Child process
//         cout << "Child Process ID: " << getpid() << endl;
//     } else {
//         // Parent process
//         cout << "Parent Process ID: " << getpid() << endl;
//     }

//     // Join threads
//     t1.join();
//     t2.join();

//     return 0;
// }


