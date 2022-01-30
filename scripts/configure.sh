#!/bin/bash

mkdir -p build
cd build
cmake "-DCMAKE_CXX_CPPLINT=cpplint" ..