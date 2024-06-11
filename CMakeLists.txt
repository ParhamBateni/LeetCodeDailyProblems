cmake_minimum_required(VERSION 3.27)
project(LeetCode)
set(CMAKE_CXX_STANDARD 17)

add_executable(LeetCode
                src/PalindromePartitioning_131.cpp)

#project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run src/MaximizeHappinessOfSelectedChildren_3075.cpp src/RelativeRanks_506.cpp
        src/ValidWord_3136.cpp
        src/K-thSmallestPrimeFraction_786.cpp
        src/MinimumCostToHireKWorkers_857.cpp
        src/LargestLocalValuesInMatrix_2373.cpp
        src/ScoreAfterFlippingMatrix_861.cpp
        src/PathWithMaximumGold_1219.cpp
        src/EvaluateBooleanBinaryTree_2331.cpp
        src/DeleteLeavesWithGivenValue_1325.cpp
        src/DistributeCoinsInBinaryTree_979.cpp
        src/FindMaximumSumOfNodeValues_3068.cpp
        src/SumOfAllSubsetXORTotals_1863.cpp
        src/Subsets_78.cpp
        src/PalindromePartitioning_131.cpp
        src/NumberOfBeautifulSubsets_2597.cpp
        src/MaximumScoreWordsFormedByLetters_1255.cpp
        src/WordBreakII_140.cpp
        src/StudentAttendanceRecordII_552.cpp
        src/SpecialArrayWithXElementsGreaterThanOrEqualX_1608.cpp
        src/GetEqualSubstringsWithinBudget_1208.cpp
        src/NumberOfStepsToReduceANumberInBinaryRepresentationToOne_1404.cpp
        src/CountTripletsThatCanFormTwoArraysOfEqualXOR_1442.cpp
        src/SingleNumberIII_260.cpp
        src/ScoreOfAString_3110.cpp
        src/ReverseString_344.cpp
        src/AppendCharactersToStringToMakeSubsequence_2486.cpp
        src/LongestPalindrome_409.cpp
        src/FindCommonCharacters_1002.cpp
        src/HandOfStraights_846.cpp
        src/ReplaceWords_648.cpp
        src/ContinuousSubarraySum_523.cpp
        src/SubarraySumsDivisibleByK_974.cpp
        src/HeightChecker_1051.cpp
        src/RelativeSortArray_1122.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
#add_subdirectory(Google_tests)

