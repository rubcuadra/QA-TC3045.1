#!/bin/bash
cd googletest/googletest/make
make
cp gtest_main.a ../../../1erParcial/Unitarias
g++ -isystem ../../googletest/googletest/include/ -pthread recursive/first.cc  recursive/first_unit.cc gtest_main.a  -o prueba