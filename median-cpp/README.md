median (C++)
============

This project contains an implementation of finding the median of a set of integers in C++,
with the very simple API in `median.hpp`:

```c++
double median(const std::vector<int>& numbers);
```

The implementation is in `median.cpp`.

The task is to optimise the runtime of the implementation whilst not breaking the
unit tests.

To generate a build system, one can use `cmake .`, then to build use `cmake --build .`
from this directory. It is recommended however to use instead:

```
mkdir bin
cd bin
cmake -G Ninja --DCMAKE_CXX_COMPILER=clang++ ..
ninja
```

That will build two executables: `ut` and `app`. The `ut` binary runs the tests,
while the `app` binary times the implementation.


### Improvements

- Cached ```halfsize``` to avoid repeated calls to ```/2``` or shift. IMprovement neglibable.
- Big improvement using introselect instead of introsort (only continue the recursion for what we need - don't sort everything to save time)

With these two optimizations, unit tests still pass and runtime of app goes from 1650 ms to 513 ms on my machine - over 3 times faster.

I cannot see any further optimization (without breaking unit tests) since quickselect on average is O(n) compared to quicksort which is O(n logn).

To compare the difference use:
```bash
# without improvements
cmake -DSLOW_WAY=ON ..
make
./app
```

and 
```bash
# with improvements
cmake -DSLOW_WAY=OFF ..
make
./app
```
