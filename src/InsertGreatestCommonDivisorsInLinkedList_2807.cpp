/*
 Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.



Example 1:

Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.

Example 2:

Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.



Constraints:

    The number of nodes in the list is in the range [1, 5000].
    1 <= Node.val <= 1000

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2807 : public ::testing::Test {
private:
    static int gcd(int a, int b) {
        int mn, mx;
        if (a > b) {
            mx = a;
            mn = b;
        } else {
            mx = b;
            mn = a;
        }
        if (mx % mn == 0)
            return mn;
        for (int i = mn / 2; i >= 1; i--) {
            if (mn % i == 0 && mx % i == 0)
                return i;
        }
        return 1;
    }

public:
    static ListNode *insertGreatestCommonDivisors(ListNode *head) {
        ListNode *start = head;
        ListNode *nxt;
        while (head->next) {
            nxt = head->next;
            ListNode *l = new ListNode(gcd(nxt->val, head->val));
            head->next = l;
            l->next = nxt;
            head = nxt;
        }
        return start;
    }
};

TEST(Solution2807, T1) {
    ListNode *head = ListNode::vectorToList({18, 6, 10, 3});
    vector<int> expected{18, 6, 6, 2, 10, 1, 3};
    ASSERT_TRUE(expected == ListNode::listToVector(Solution2807::insertGreatestCommonDivisors(head)));
}

TEST(Solution2807, T2) {
    ListNode *head = ListNode::vectorToList({7});
    vector<int> expected{7};
    ASSERT_TRUE(expected == ListNode::listToVector(Solution2807::insertGreatestCommonDivisors(head)));
}