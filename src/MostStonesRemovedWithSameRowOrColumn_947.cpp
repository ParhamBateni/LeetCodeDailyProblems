/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.



Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.



Constraints:

    1 <= stones.length <= 1000
    0 <= xi, yi <= 104
    No two stones are at the same coordinate point.

 */
#include "../utils.h"
#include "gtest/gtest.h"

vector<int> row[10001], col[10001];
int viz[1001];// bitset is good
class Solution947 : public ::testing::Test {
public:
    static void dfs(int idx, vector<vector<int>> &stones) {
        const int i = stones[idx][0], j = stones[idx][1];
        viz[idx] = 1;
        for (auto k: row[i]) {
            if (!viz[k]) dfs(k, stones);
        }
        for (auto k: col[j]) {
            if (!viz[k]) dfs(k, stones);
        }
    }

    static int removeStones(vector<vector<int>> &stones) {
        for (int i = 0; i < 1001; i++) viz[i] = 0;
        for (int i = 0; i < 10001; i++) {
            row[i] = {};
            col[i] = {};
        }
        const int n = stones.size();
        for (int idx = 0; idx < n; idx++) {
            const int i = stones[idx][0], j = stones[idx][1];
            row[i].push_back(idx);
            col[j].push_back(idx);
        }

        int component = 0;
        for (int idx = 0; idx < n; idx++) {
            const int i = stones[idx][0], j = stones[idx][1];
            if (!viz[idx]) {
                dfs(idx, stones);
                component++;
            }
        }
        return n - component;
    }
};

TEST(Solution947, T1) {
    vector<vector<int>> stones{{0, 0},
                               {0, 1},
                               {1, 0},
                               {1, 2},
                               {2, 1},
                               {2, 2}};
    int expected = 5;
    ASSERT_TRUE(expected == Solution947::removeStones(stones));
}

TEST(Solution947, T2) {
    vector<vector<int>> stones{{0, 0},
                               {0, 2},
                               {1, 1},
                               {2, 0},
                               {2, 2}};
    int expected = 3;
    ASSERT_TRUE(expected == Solution947::removeStones(stones));
}

TEST(Solution947, T3) {
    vector<vector<int>> stones{{0, 0}};
    int expected = 0;
    ASSERT_TRUE(expected == Solution947::removeStones(stones));
}
