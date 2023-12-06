# cpp-client
C++ client for Enigma Showdown

## Installation Steps

Install vcpkg (https://vcpkg.io/en/getting-started)

```shell
# go to your directory of choice
cd ~/Documents/Clones
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
```

Install cppzmq

```shell
./vcpkg integrate install
./vcpkg install cppzmq
# run this one just in case
./vcpkg integrate install
```

The `./vcpkg integrate install` command should give you a `"-DCMAKE_TOOL..."` argument.
Copy this and include the quotes when you copy it.

```shell
cd /this/cpp-client/folder
cmake -B ./ -S . "-DCMAKE_TOOLCHAIN_FILE=/home/lavender/Documents/Clones/vcpkg/scripts/buildsystems/vcpkg.cmake"
make
./CppClient
```


