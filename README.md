# Melon
A library for C++23 designed for [RadishOS](https://github.com/wither16x/radish_os).
## Introduction
**Melon** is an alternative to the Standard Template Library for RadishOS userspace programs. However, it can also be used on GNU/Linux systems. \
Melon aims to provide a readable, intuitive and modern API. However, it has a lot less features than libc++ or libstdc++ and its code is certainly less powerful.
## Quick example
Here is a "Hello, world!" program written using Melon:
```cpp
#include <Melon/Print.hpp>

using namespace Melon;

int main()
{
        Print::println("Hello, world!");
}
```
If you wish to see more examples, have a look at the [Examples](Examples) directory.
## Building
**Step 1:** clone the repository
```sh
git clone https://github.com/wither16x/melon
```
**Step 2:** download dependencies
```sh
chmod +x Dependencies.sh
./Dependencies.sh
```
**Step 3:** build the sources
```sh
make # make clean if needed
```
## Installing
**Option 1:** local installation
```sh
make install-local
```
**Option 2:** global installation
```sh
sudo make install-global
```
## Building and running examples
If you wish to build and run some programs made with Melon, run the following command:
```sh
make -C Examples/ExampleName # e.g. HelloWorld
./Examples/ExampleName/Build/hello_world # e.g. HelloWorld/Build/hello_world
```
## Testing
You can also run unit tests:
```sh
make -C Test
./Test/Build/Test
```
Developpers can run:
```sh
./Dev.sh
```
directly. This script recompiles the sources, recompiles and run the tests and builds the documentation.
## Documentation
Online documentation can be found at https://wither16x.github.io/melon.