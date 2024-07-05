/*
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].



Example 1:

Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].

Example 2:

Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

Example 3:

Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.



Constraints:

    The number of nodes in the list is in the range [2, 105].
    1 <= Node.val <= 105


 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution2058 : public ::testing::Test {
public:
    static vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(false);
        int inf = 1e8;
        vector<int> res{inf, -1};
        int prev = head->val, prevCritical = -inf, mnCritical = inf;
        head = head->next;
        int i = 1;
        while (head != nullptr && head->next != nullptr) {
            if (head->val > prev && head->val > head->next->val ||
                head->val < prev && head->val < head->next->val) {
                res[0] = min(i - prevCritical, res[0]);
                res[1] = max(i - mnCritical, res[1]);
                mnCritical = min(mnCritical, i);
                prevCritical = i;
            }
            prev = head->val;
            head = head->next;
            i++;
        }
        if (res[0] == inf)
            res[0] = -1;
        return res;
    }
};

TEST(Solution2058, T1) {
    vector<int> head{3, 1};
    vector<int> expected{-1, -1};
    ASSERT_TRUE(expected == Solution2058::nodesBetweenCriticalPoints(ListNode::vectorToList(head)));
}

TEST(Solution2058, T2) {
    vector<int> head{5, 3, 1, 2, 5, 1, 2};
    vector<int> expected{1, 3};
    ASSERT_TRUE(expected == Solution2058::nodesBetweenCriticalPoints(ListNode::vectorToList(head)));
}


TEST(Solution2058, T3) {
    vector<int> head{1, 3, 2, 2, 3, 2, 2, 2, 7};
    vector<int> expected{3, 3};
    ASSERT_TRUE(expected == Solution2058::nodesBetweenCriticalPoints(ListNode::vectorToList(head)));
}