cmake_minimum_required(VERSION 3.27)
project(LeetCode)
set(CMAKE_CXX_STANDARD 17)

add_executable(LeetCode
        src/MaximizeHappinessOfSelectedChildren_3075.cpp src/RelativeRanks_506.cpp
        src/K-thSmallestPrimeFraction_786.cpp
        src/ValidWord_3136.cpp)

#project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run src/MaximizeHappinessOfSelectedChildren_3075.cpp src/RelativeRanks_506.cpp
        src/ValidWord_3136.cpp
        src/K-thSmallestPrimeFraction_786.cpp
        src/MinimumCostToHireKWorkers_857.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
#add_subdirectory(Google_tests)

