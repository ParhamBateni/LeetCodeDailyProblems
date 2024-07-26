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
        src/RelativeSortArray_1122.cpp
        src/SortColors_75.cpp
        src/MinimumNumberOfMovesToSeatEveryone_2037.cpp
        src/MinimumIncrementToMakeArrayUnique_945.cpp
        src/IPO_502.cpp
        src/PatchingArray_330.cpp
        src/SumOfSquareNumbers_633.cpp
        src/MostProfitAssigningWork_826.cpp
        src/MinimumNumberOfDaysToMakemBouquets_1482.cpp
        src/MagneticForceBetweenTwoBalls_1552.cpp
        src/GrumpyBookstoreOwner_1052.cpp
        src/CountNumberOfNiceSubarrays_1248.cpp
        src/LongestContinuousSubarrayWithAbsoluteDiffLessThanOrEqualToLimit_1438.cpp
        src/MinimumNumberOfKConsecutiveBitFlips_995.cpp
        src/BinarySearchTreeToGreaterSumTree_1038.cpp
        src/BalanceBinarySearchTree_1382.cpp
        src/FindCenterOfStarGraph_1791.cpp
        src/AllAncestorsOfNodeInDirectedAcyclicGraph_2192.cpp
        src/RemoveMaxNumberOfEdgesToKeepGraphFullyTraversable_1579.cpp
        src/ThreeConsecutiveOdds_1550.cpp
        src/IntersectionOfTwoArraysII_350.cpp
        src/MinimumDifferenceBetweenLargestAndSmallestValueInThreeMoves_1509.cpp
        src/MergeNodesInBetweenZeros_2181.cpp
        src/FindMinimumAndMaximumNumberOfNodesBetweenCriticalPoints_2058.cpp
        src/PassThePillow_2582.cpp
        src/WaterBottles_1518.cpp
        src/FindTheWinnerOfTheCircularGame_1823.cpp
        src/AverageWaitingTime_1701.cpp
        src/CrawlerLogFolder_1598.cpp
        src/ReverseSubstringsBetweenEachPairOfParentheses_1190.cpp
        src/MaximumScoreFromRemovingSubstrings_1717.cpp
        src/RobotCollisions_2751.cpp
        src/NumberOfAtoms_726.cpp
        src/CreateBinaryTreeFromDescriptions_2196.cpp
        src/StepByStepDirectionsFromBinaryTreeNodeToAnother_2096.cpp
        src/DeleteNodesAndReturnForest_1110.cpp
        src/NumberOfGoodLeafNodesPairs_1530.cpp
        src/LuckyNumbersInMatrix_1380.cpp
        src/FindValidMatrixGivenRowAndColumnSums_1605.cpp
        src/BuildMatrixWithConditions_2392.cpp
        src/SortThePeople_2418.cpp
        src/SortArrayByIncreasingFrequency_1636.cpp
        src/SortJumbledNumbers_2191.cpp
        src/SortAnArray_912.cpp
        src/FindCityWithSmallestNumberOfNeighboursAtThresholdDistance_1334.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
#add_subdirectory(Google_tests)

