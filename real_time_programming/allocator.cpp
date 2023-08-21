// C++ Weekly - Ep 222 - 3.5x Faster Standard Containers With PMR!
// https://www.youtube.com/watch?v=q6A7cKFXjY0
// https://www.youtube.com/watch?v=vXJ1dwJ9QkI 

// std::pmr::polymorphic_allocator : https://en.cppreference.com/w/cpp/memory/polymorphic_allocator
// std::pmr::memory_resource : https://en.cppreference.com/w/cpp/memory/memory_resource

// std::pmr stands for "polymorphic memory resources" and is a part of the C++17 standard library. The std::pmr library provides facilities for generalized memory allocation, allowing developers to decouple memory allocation strategies from the containers and other objects that use them.

// Here are some key points about std::pmr:

// Memory Resources: At the heart of std::pmr are the memory resources. A memory resource is an object that encapsulates a memory allocation strategy. The base class for all memory resources is std::pmr::memory_resource.

// Polymorphic: The term "polymorphic" in std::pmr refers to the fact that memory resources are used polymorphically. That is, you can provide your custom memory allocation strategy by deriving from std::pmr::memory_resource and overriding its virtual functions.

// Standard Memory Resources: The library provides several standard memory resources, such as std::pmr::new_delete_resource() (which uses global new and delete) and std::pmr::null_memory_resource() (which doesn't allocate and is useful as a fallback).

// PMR Containers: std::pmr provides aliases for standard containers that use polymorphic allocators, like std::pmr::vector, std::pmr::string, and so on. These containers can be given a memory resource to control their allocation behavior.

// Monotonic Memory Resource: One of the commonly used memory resources in std::pmr is the monotonic_buffer_resource. It allocates memory in large chunks and then provides storage from these chunks in a fast, stack-like manner. This can be much faster than the default allocation strategy for certain use cases, especially when many small allocations are made.

// Custom Memory Resources: Developers can create custom memory resources by inheriting from std::pmr::memory_resource and implementing the required allocation and deallocation methods. This allows for highly specialized and optimized allocation strategies tailored to specific use cases.

// Use Cases: std::pmr is particularly useful in scenarios where:

// You want to use custom allocation strategies without rewriting or adapting container classes.
// You're dealing with libraries or components that should not be tied to a specific memory allocation strategy.
// You need to optimize memory allocation for specific scenarios, like real-time systems, embedded systems, or high-performance computing.
// In summary, std::pmr provides a flexible and general mechanism for controlling memory allocation in C++ programs, allowing developers to optimize memory usage and performance without making significant changes to the data structures and algorithms that use the memory.


// https://www.youtube.com/watch?v=Tof5pRedskI&t=358s

// std::array<float, 1024> stack_memory;

// std::pmr::monotonic_buffer_resource monotonic_buffer(
//   stack_memory.data(),
//   stack_memory.size(),
//   std::pmr::null_memory_resource());

// using allocator_t std::pmr::polymorphic_allocator<float>;
// allocator_t allocator(&monotonic_buffer);
// std::pmr::vector<float> my_vector(b.size(), 0.0f, allocator);

// std::pmr::unsynchronised_pool_resource

// std::pmr::unsynchronized_pool_resource pool (
//   std::pmr::pool_options(...),
//   &monotonic_buffer);



// TLSF allocator : http://www.gii.upv.es/tlsf/files/ecrts04_tlsf.pdf
// https://github.com/mattconte/tlsf