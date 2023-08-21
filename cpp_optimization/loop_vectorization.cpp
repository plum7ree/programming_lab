
// https://www.youtube.com/watch?v=BP6NxVxDQIs&list=PLZ1tBrvKvYpvEViZswBrgqhcBLjd571_S&index=2&t=3121s
// https://www.incredibuild.com/blog/tutorial-video-a-deeper-dive-into-the-c-compiler-optimization

// compiler generate SIMD, sse instruction for me if I correctly write code to be loop vectorization.
// xmm registers : https://en.wikipedia.org/wiki/Streaming_SIMD_Extensions
// The following simple example demonstrates the advantage of using SSE. Consider an operation like vector addition, which is used very often in computer graphics applications. To add two single precision, four-component vectors together using x86 requires four floating-point addition instructions.

//  vec_res.x = v1.x + v2.x;
//  vec_res.y = v1.y + v2.y;
//  vec_res.z = v1.z + v2.z;
//  vec_res.w = v1.w + v2.w;
// This corresponds to four x86 FADD instructions in the object code. On the other hand, as the following pseudo-code shows, a single 128-bit 'packed-add' instruction can replace the four scalar addition instructions.

//  movaps xmm0, [v1] ;xmm0 = v1.w | v1.z | v1.y | v1.x 
//  addps xmm0, [v2]  ;xmm0 = v1.w+v2.w | v1.z+v2.z | v1.y+v2.y | v1.x+v2.x
//  movaps [vec_res], xmm0  ;xmm0

// ARM's SIMD is called NEON.
// Data Types: NEON supports a variety of data types, from 8-bit integers to 64-bit floating-point numbers. It can operate on vectors of 8, 16, 32, or 64-bit elements.

// Parallelism: NEON instructions can process multiple data elements in parallel, which is the essence of SIMD. For example, it can add together four pairs of 32-bit integers in a single instruction.

// Intrinsics: Like other architectures, ARM provides NEON intrinsics, which are function calls that get replaced with one or more NEON instructions during compilation. This allows developers to write NEON-optimized code in C or C++ without resorting to assembly language.

// Auto-vectorization: Modern compilers like GCC and Clang can auto-vectorize code to use NEON instructions when targeting ARM platforms that support it. However, as with other architectures, the effectiveness of auto-vectorization depends on the code structure and the optimization flags used during compilation.

// Architecture Versions: Not all ARM architectures have NEON. It's primarily found in ARM Cortex-A series processors, starting from ARMv7-A architecture. ARMv8-A architecture, which introduces the 64-bit ARM instruction set (AArch64), also includes an enhanced version of NEON that supports both 64-bit and 128-bit vector data.

// Checking Support: If you're writing code for ARM and want to leverage NEON, ensure that the target processor supports NEON. When compiling, you might need to use specific flags (e.g., -mfpu=neon for GCC) to enable NEON optimizations.

// Performance: As with any optimization, it's essential to profile and test the performance of NEON-optimized code. In some cases, manual optimization using intrinsics or assembly might yield better results than relying solely on compiler auto-vectorization.

