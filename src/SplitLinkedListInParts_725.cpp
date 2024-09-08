/*
 Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.



Example 1:

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.



Constraints:

    The number of nodes in the list is in the range [0, 1000].
    0 <= Node.val <= 1000
    1 <= k <= 50

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution725 : public ::testing::Test {
public:
    static vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> res;
        int s = 0;
        ListNode *start = head;
        while (start) {
            s++;
            start = start->next;
        }
        int p = s / k;
        start = head;
        for (int i = 0; i < k; i++) {
            head = start;
            res.push_back(head);
            if (!head)
                continue;
            for (int j = 0; j < p - (i >= s % k); j++) {
                head = head->next;
            }
            start = head->next;
            head->next = nullptr;
        }
        return res;
    }
};

TEST(Solution725, T1) {
    ListNode *head = ListNode::vectorToList({1, 2, 3});
    int k = 5;
    vector<vector<int>> expected = {{1},
                                    {2},
                                    {3},
                                    {},
                                    {}};
    vector<vector<int>> res;
    for (auto &l: Solution725::splitListToParts(head, k)) {
        res.push_back(ListNode::listToVector(l));
    }
    ASSERT_TRUE(expected == res);
}

TEST(Solution725, T2) {
    ListNode *head = ListNode::vectorToList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    int k = 3;
    vector<vector<int>> expected = {{1, 2, 3, 4},
                                    {5, 6, 7},
                                    {8, 9, 10}};
    vector<vector<int>> res;
    for (auto &l: Solution725::splitListToParts(head, k)) {
        res.push_back(ListNode::listToVector(l));
    }
    ASSERT_TRUE(expected == res);
}