# Create library
cd ..
cd src
rm *.o
rm *.so
make
cd ..
cp src/chase.so examples

cd examples

g++ main.cpp chase.so -I ../src -I ../src/include -o test

LD_LIBRARY_PATH="." ./test.exe