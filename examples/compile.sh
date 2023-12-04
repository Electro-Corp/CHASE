# Create library
cd ..
cd src
rm *.o
rm *.so
make
cd ..
cp src/chase.so examples

cd examples

g++ ex1.cpp chase.so -I ../src -I ../src/include -o test.dll

LD_LIBRARY_PATH="." ./test.dll
