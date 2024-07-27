/*
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].



Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.

Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.

Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.



Constraints:

    1 <= source.length == target.length <= 105
    source, target consist of lowercase English letters.
    1 <= cost.length == original.length == changed.length <= 2000
    original[i], changed[i] are lowercase English letters.
    1 <= cost[i] <= 106
    original[i] != changed[i]


*/

#include "../utils.h"
#include "gtest/gtest.h"

class Solution2976 : public ::testing::Test {
    struct PairCompare {
        bool operator()(pair<int, int> &p1, pair<int, int> &p2) { return p1.second > p2.second; }
    };

private:
    static long long findShortestDistance(int source, int target,
                                          const vector<vector<pair<int, int>>> &neighbours) {
        int n = neighbours.size();
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, PairCompare> queue;
        queue.push({source, 0});
        dist[source] = 0;

        while (!queue.empty()) {
            auto [node, distance] = queue.top();
            queue.pop();

            if (node == target) {
                return distance;
            }

            if (distance > dist[node]) {
                continue;
            }

            for (auto &neighbour: neighbours[node]) {
                int nextNode = neighbour.first;
                long long newDist = distance + neighbour.second;
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    queue.push({nextNode, newDist});
                }
            }
        }
        return -1;
    }

public:
    static long long minimumCost(string source, string target, vector<char> &original,
                                 vector<char> &changed, vector<int> &cost) {
        vector<vector<pair<int, int>>> neighbours(26);
        for (int i = 0; i < original.size(); i++) {
            neighbours[original[i] - 'a'].push_back(
                    {changed[i] - 'a', cost[i]});
        }
        vector<vector<long>> distances(26, vector<long>(26));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                distances[i][j] = findShortestDistance(i, j, neighbours);
            }
        }
        long long minCost = 0, c;
        for (int i = 0; i < source.size(); i++) {
            c = distances[source[i] - 'a'][target[i] - 'a'];
            if (c == -1)
                return -1;
            minCost += c;
        }
        return minCost;
    }
};


TEST(Solution2976, T1) {
    string source = "abcd";
    string target = "acbe";
    vector<char> original{'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed{'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost{2, 5, 5, 1, 2, 20};
    int expected = 28;
    ASSERT_TRUE(expected == Solution2976::minimumCost(source, target, original, changed, cost));
}

TEST(Solution2976, T2) {
    string source = "aaaa";
    string target = "bbbb";
    vector<char> original{'a', 'c'};
    vector<char> changed{'c', 'b'};
    vector<int> cost{1, 2};
    int expected = 12;
    ASSERT_TRUE(expected == Solution2976::minimumCost(source, target, original, changed, cost));
}

TEST(Solution2976, T3) {
    string source = "abcd";
    string target = "acbe";
    vector<char> original{'a'};
    vector<char> changed{'e'};
    vector<int> cost{1000};
    int expected = -1;
    ASSERT_TRUE(expected == Solution2976::minimumCost(source, target, original, changed, cost));
}