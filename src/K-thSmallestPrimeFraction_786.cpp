/*
 * You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution786 : public ::testing::Test {
    struct Comp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.first * b.second < b.first * a.second;
        }
    };

public:
    static vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq = priority_queue<pair<int, int>, vector<pair<int, int>>, Comp>();
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                pq.push(pair(arr[i], arr[j]));
                if (pq.size() > k)pq.pop();
            }
        }
        return vector<int>{pq.top().first, pq.top().second};
    }
};

TEST(Solution786, T1) {
    vector<int> v = vector<int>{1, 2, 3, 5};
    vector<int> expected = vector<int>{2, 5};
    ASSERT_TRUE(expected == Solution786::kthSmallestPrimeFraction(v, 3));
}

TEST(Solution786, T2) {
    vector<int> v = vector<int>{1, 7};
    vector<int> expected = vector<int>{1, 7};
    ASSERT_TRUE(expected == Solution786::kthSmallestPrimeFraction(v, 1));
}