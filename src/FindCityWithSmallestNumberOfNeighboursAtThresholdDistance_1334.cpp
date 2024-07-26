/*
 There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.



Example 1:

Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph.
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

Example 2:

Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph.
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1]
City 1 -> [City 0, City 4]
City 2 -> [City 3, City 4]
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3]
The city 0 has 1 neighboring city at a distanceThreshold = 2.



Constraints:

    2 <= n <= 100
    1 <= edges.length <= n * (n - 1) / 2
    edges[i].length == 3
    0 <= fromi < toi < n
    1 <= weighti, distanceThreshold <= 10^4
    All pairs (fromi, toi) are distinct.


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1334 : public ::testing::Test {
    struct CompareEdge {
        bool operator()(const pair<int, int> &e1, const pair<int, int> &e2) {
            return e1.second > e2.second;
        }
    };

public:
    static int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        vector<int> reaches(n, 0);
        vector<vector<pair<int, int>>> neighbours(n);
        for (auto &e: edges) {
            neighbours[e[0]].push_back({e[1], e[2]});
            neighbours[e[1]].push_back({e[0], e[2]});
        }
        pair<int, int> node;
        vector<bool> seen(n);
        int min_reaches = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < n; i++) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, CompareEdge> queue;
            queue.push({i, 0});
            seen = vector<bool>(n, false);
            while (!queue.empty()) {
                node = queue.top();
                queue.pop();
                if (seen[node.first]) continue;
                reaches[i]++;
                if (reaches[i] > min_reaches) break;
                seen[node.first] = true;
                for (auto &neighbour: neighbours[node.first]) {
                    if (!seen[neighbour.first] && neighbour.second + node.second <= distanceThreshold) {
                        queue.push({neighbour.first, neighbour.second + node.second});
                    }
                }
            }
            if (min_reaches >= reaches[i]) {
                min_reaches = reaches[i];
                min_index = i;
            }
        }
        return min_index;
    }
};

TEST(Solution1334, T1) {
    vector<vector<int>> edges{{0, 1, 3},
                              {1, 2, 1},
                              {1, 3, 4},
                              {2, 3, 1}};
    int n = 4;
    int distanceThreshold = 4;
    int expected = 3;
    ASSERT_TRUE(expected == Solution1334::findTheCity(n, edges, distanceThreshold));
}

TEST(Solution1334, T2) {
    vector<vector<int>> edges{{0, 1, 2},
                              {0, 4, 8},
                              {1, 2, 3},
                              {1, 4, 2},
                              {2, 3, 1},
                              {3, 4, 1}};
    int n = 5;
    int distanceThreshold = 2;
    int expected = 0;
    ASSERT_TRUE(expected == Solution1334::findTheCity(n, edges, distanceThreshold));
}
