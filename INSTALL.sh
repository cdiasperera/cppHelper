set -e

mkdir -p .build
cd .build
cmake ../ -DCMAKE_BUILD_TYPE=Release
make
mv cppHelper /usr/loca/bin