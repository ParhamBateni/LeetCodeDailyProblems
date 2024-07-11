/*
The Leetcode file system keeps a log each time some user performs a change folder operation.

The operations are described below:

    "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
    "./" : Remain in the same folder.
    "x/" : Move to the child folder named x (This folder is guaranteed to always exist).

You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

The file system starts in the main folder, then the operations in logs are performed.

Return the minimum number of operations needed to go back to the main folder after the change folder operations.



Example 1:

Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.

Example 2:

Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3

Example 3:

Input: logs = ["d1/","../","../","../"]
Output: 0



Constraints:

    1 <= logs.length <= 103
    2 <= logs[i].length <= 10
    logs[i] contains lowercase English letters, digits, '.', and '/'.
    logs[i] follows the format described in the statement.
    Folder names consist of lowercase English letters and digits.

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1598 : public ::testing::Test {
public:
    static int minOperations(vector<string> &logs) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int c = 0;
        for (auto &l: logs) {
            if (l == "../")
                c = max(c - 1, 0);
            else if (l != "./")
                c += 1;
        }
        return c;
    }
};

TEST(Solution1598, T1) {
    vector<string> logs{"d1/", "d2/", "../", "d21/", "./"};
    int expected = 2;
    ASSERT_EQ(expected, Solution1598::minOperations(logs));
}

TEST(Solution1598, T2) {
    vector<string> logs{"d1/", "d2/", "./", "d3/", "../", "d31/"};
    int expected = 3;
    ASSERT_EQ(expected, Solution1598::minOperations(logs));
}

TEST(Solution1598, T3) {
    vector<string> logs{"d1/", "../", "../", "../"};
    int expected = 0;
    ASSERT_EQ(expected, Solution1598::minOperations(logs));
}
