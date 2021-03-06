Tutorials {#tutorials}
=========

The general principles of **Boost.SIMD** are introduced in the following tutorials.

  + using the pack abstraction of a native _SIMD_ vector.
  + compiling a program written using **Boost.SIMD**.
  + using _SIMD_ specific idioms such as reduction, branching and shuffling
  + vectorizing code using the Standard Template Library(transform and accumulate)
  + _SIMD_ runtime dispatching

In the following tutorials, we will assume the use of a 128 bit wide _SIMD_ extensions (such as SSE or Altivec), however
all of the examples will work on any supported architecture. Depending on your actual architecture, the output of the
following tutorials applications may vary.

- [SIMD HelloWorld](@ref tutorial-hello)
- [A Basic SIMD Loop](@ref tutorial-simd-loop)
- [Reductions](@ref tutorial-reduction)
- [Processing Data the SIMD Way](@ref tutorial-data)
- [Runtime Extension Selection](@ref tutorial-runtime)

#TODO: General reduction operations, transforms

#TODO: Aligned memory

### Is it better practice to use a pack as an array?

The main element of **Boost.SIMD** is the boost::simd::pack class, accessible through the boost/simd/pack.hpp header file. `pack<T,N>` is an abstraction over a block of `N` elements of type `T`, quite similar to `std::array`. The main semantic difference is that boost::simd::pack is implemented as the best hardware specific type able to store this amount of data which may be a simple scalar array, a single _SIMD_ register or a tuple of _SIMD_ registers depending on `N` and `T`.

