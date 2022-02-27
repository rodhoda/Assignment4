cmake_minimum_required(VERSION 3.21)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment4 LedgerDriver.cpp Transaction.cpp Node.cpp State.cpp Ledger.cpp)
