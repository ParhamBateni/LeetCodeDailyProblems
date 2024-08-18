/*
 An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.



Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.



Constraints:

    1 <= n <= 1690


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution264 : public ::testing::Test {
public:
    static int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> uglyHeap;
        unordered_set<long> visited;

        uglyHeap.push(1);
        visited.insert(1);

        long curr;
        for (int i = 0; i < n; ++i) {
            curr = uglyHeap.top();
            uglyHeap.pop();
            for (int prime: primes) {
                long new_ugly = curr * prime;
                if (visited.find(new_ugly) == visited.end()) {
                    uglyHeap.push(new_ugly);
                    visited.insert(new_ugly);
                }
            }
        }
        return (int) curr;
    }
};

TEST(Solution264, T1) {
    int n = 10;
    int expected = 12;
    ASSERT_TRUE(expected == Solution264::nthUglyNumber(n));
}


TEST(Solution264, T2) {
    int n = 1;
    int expected = 1;
    ASSERT_TRUE(expected == Solution264::nthUglyNumber(n));
}