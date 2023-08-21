// std::memory_order is a set of enumerator values 
// provided by the C++11 (and later) Standard Library to specify 
// memory ordering constraints on atomic operations. 
// When you perform atomic operations using C++'s <atomic> header, 
// the memory ordering dictates how reads and writes to different memory locations c
// an be reordered with respect to that atomic operation.

// Understanding memory ordering is crucial in lock-free programming, 
// as modern architectures and compilers can reorder instructions for optimization purposes, 
// which can lead to subtle and hard-to-debug concurrency issues.

// Here's a brief rundown of the different memory orderings:

// memory_order_relaxed: This imposes no ordering constraints on reads/writes. Only atomicity and visibility are guaranteed.

// memory_order_consume: Data-dependent ordering. It's designed to ensure that writes that are visible to an atomic variable using a read-modify-write operation are also visible to subsequent reads that are data-dependent on that atomic variable. This memory order is rarely used and can be difficult to employ correctly.

// memory_order_acquire: Prevents reads/writes that appear before the operation in the program's order from being reordered after the operation.

// memory_order_release: Prevents reads/writes that appear after the operation in the program's order from being reordered before the operation.

// memory_order_acq_rel: A combination of both acquire and release constraints.

// memory_order_seq_cst: Sequentially consistent ordering. This is the strongest ordering and ensures a single total order of all sequentially consistent operations. By default, operations on std::atomic types use this ordering if no other is specified.

// Here's an illustrative example:

// cpp
// Copy code
// #include <atomic>
// #include <thread>
// #include <iostream>

// std::atomic<int> data[2];
// std::atomic<bool> sync1(false), sync2(false);

// void thread_1() {
//     data[0].store(42, std::memory_order_relaxed);
//     data[1].store(97, std::memory_order_relaxed);
//     sync1.store(true, std::memory_order_release);
// }

// void thread_2() {
//     while (!sync1.load(std::memory_order_acquire));
//     if (data[1].load(std::memory_order_relaxed) == 97) {
//         std::cout << "data[0] = " << data[0].load(std::memory_order_relaxed) << std::endl;
//     }
// }

// int main() {
//     std::thread t1(thread_1);
//     std::thread t2(thread_2);
//     t1.join();
//     t2.join();
//     return 0;
// }
// In the above example, the release-acquire ordering guarantees that data[0] and data[1] writes in thread_1 happen before their reads in thread_2.

// It's essential to understand that using weaker memory orders 
// (like memory_order_relaxed) can lead to better performance, 
// but they also require a deeper understanding of the memory model 
// to avoid concurrency issues. Always test and validate the behavior 
// of your program thoroughly when using memory orderings other 
// than the default memory_order_seq_cst.



// can you explain more about memory_order_seq_cst
// ChatGPT
// Certainly! memory_order_seq_cst (Sequentially Consistent memory order) is the default memory order for atomic operations in C++. It provides the strongest ordering guarantees, ensuring that all operations with this memory order on different threads appear to be executed in the same order for all threads.

// To understand memory_order_seq_cst, let's break down its essence:

// Sequentially Consistent:

// In a sequentially consistent execution, the result of any execution is the same as if the operations of all the processors were executed in some sequential order, and the operations of each individual processor appear in this sequence in the order defined by its program.
// Simply put, imagine all the atomic operations of all threads being merged into a single sequence. The operations in this sequence respect the order of atomic operations within each thread.
// Total Order:

// For operations that are memory_order_seq_cst, there exists a single total order. This means that for any two such operations A and B from any threads, either A is before B or B is before A in this total order.
// Relationship with Other Memory Orders:

// When a memory_order_seq_cst operation sees a particular value (say, of an atomic variable), it also sees all the operations that happened-before that value was written.
// Here's a simple example to illustrate the concept:

// cpp
// Copy code
// #include <atomic>
// #include <thread>
// #include <iostream>

// std::atomic<bool> x(false), y(false);
// std::atomic<int> z(0);

// void write_x() {
//     x.store(true, std::memory_order_seq_cst);
// }

// void write_y() {
//     y.store(true, std::memory_order_seq_cst);
// }

// void read_x_then_y() {
//     while (!x.load(std::memory_order_seq_cst));
//     if (y.load(std::memory_order_seq_cst)) {
//         z++;
//     }
// }

// void read_y_then_x() {
//     while (!y.load(std::memory_order_seq_cst));
//     if (x.load(std::memory_order_seq_cst)) {
//         z++;
//     }
// }

// int main() {
//     std::thread t1(write_x);
//     std::thread t2(write_y);
//     std::thread t3(read_x_then_y);
//     std::thread t4(read_y_then_x);
//     t1.join(); t2.join(); t3.join(); t4.join();
//     std::cout << "z = " << z.load() << std::endl;  // Always prints 2
//     return 0;
// }
// In the above example, due to memory_order_seq_cst, the operations have a total order. Regardless of the inter-thread interleavings, z will always be 2 at the end of the program.

// The beauty of memory_order_seq_cst is that it provides an intuitive memory ordering that behaves in a way you'd naturally expect in a multithreaded environment. However, this guarantee often comes at a performance cost, especially on architectures where enforcing such a strict order requires additional synchronization.

// That's why C++ provides weaker memory orders as well. They can offer better performance if used correctly but require a deeper understanding of the program's memory semantics to avoid concurrency issues.