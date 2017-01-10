# QA-TC3045.1

make  googletest/googletest/make
cp googletest/googletest/make/gtest_main.a 1erParcial/Unitarias

cd 1erParcial/Unitarias
g++ -isystem ../../googletest/googletest/include/ -pthread recursive/first.cc  recursive/first_unit.cc gtest_main.a  -o prueba
