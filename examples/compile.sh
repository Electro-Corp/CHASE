# Create library
cd ..
cd src
rm *.o
rm *.so
make
cd ..
cp src/chase.so examples

cd examples

g++ ex1.cpp chase.so -I ../src -I ../src/include -o ex1
g++ ex2.cpp chase.so -I ../src -I ../src/include -o ex2


LD_LIBRARY_PATH="." ./ex1

echo "NEXT"

LD_LIBRARY_PATH="." ./ex2