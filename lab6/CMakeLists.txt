cmake_minimum_required(VERSION 3.12)
project(Lab3)

set(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

add_executable(lab main.cpp base.h base.cpp base.h  container.h sort.h container.cpp sort.cpp )

add_executable(test unit_test.cpp base.cpp base.h)

add_executable(test_container  ContainerTest.cpp base.h base.cpp container.h container.cpp sort.h sort.cpp)

add_executable(test_decorator TestDecorator.cpp base.h base.cpp decorator.h decorator.cpp)

add_executable(test_abstract_factory base.h base.cpp AbstractFactory.h AbstractFactory.cpp TestAbstractFactory.cpp)

target_link_libraries(test gtest)
target_link_libraries(test_container gtest)
target_link_libraries(test_decorator gtest)
target_link_libraries(test_abstract_factory gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(test_container PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(test_decorator PRIVATE gtest_disable_pthreads=ON)
TARGET_COMPILE_DEFINITIONS(test_abstract_factory PRIVATE gtest_disable_pthreads=ON)