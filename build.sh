#bash

conan install . --output-folder=build --build=missing
mkdir -p build
cd build
clear
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
make
mv r-type_* ..
cd ..
