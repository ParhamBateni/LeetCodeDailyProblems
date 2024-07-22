/*
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.



Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.



Constraints:

    n == names.length == heights.length
    1 <= n <= 103
    1 <= names[i].length <= 20
    1 <= heights[i] <= 105
    names[i] consists of lower and upper case English letters.
    All the values of heights are distinct.


 */

#include "../utils.h"
#include "gtest/gtest.h"


class Solution2418 : public ::testing::Test {
public:
    static vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = names.size();
        vector<pair<int, string>> info(n);
        for (int i = 0; i < names.size(); i++)
            info[i] = {heights[i], names[i]};
        sort(info.begin(), info.end(), [](auto &p1, auto &p2) {
            return p1.first < p2.first;
        });
        vector<string> res(n);
        for (auto &p: info)
            res[--n] = p.second;
        return res;
    }
};

TEST(Solution2418, T1) {
    vector<string> names{"Mary", "John", "Emma"};
    vector<int> heights{180, 165, 170};
    vector<string> expected{"Mary", "Emma", "John"};
    ASSERT_TRUE(expected == Solution2418::sortPeople(names, heights));
}


TEST(Solution2418, T2) {
    vector<string> names{"Alice", "Bob", "Bob"};
    vector<int> heights{155, 185, 150};
    vector<string> expected{"Bob", "Alice", "Bob"};
    ASSERT_TRUE(expected == Solution2418::sortPeople(names, heights));
}
