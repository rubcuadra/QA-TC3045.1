#!/bin/bash
cd googletest/googletest/make
make
cp gtest_main.a ../../../1erParcial/Unitarias
echo 'recursive/'
g++ -isystem ../../googletest/googletest/include/ -pthread recursive/first.cc  recursive/first_unit.cc gtest_main.a  -o prueba
./prueba
echo 'almacen/'
g++ -isystem ../../googletest/googletest/include/ -pthread almacen/main.cc almacen/almacen_test.cc  gtest_main.a  -o prueba
./prueba
echo 'parametrized/'
g++ -isystem ../../googletest/googletest/include/ -pthread  parametrized/parametrized.cc   gtest_main.a  -o prueba