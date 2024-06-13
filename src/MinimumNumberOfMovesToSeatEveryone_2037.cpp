/*
 There are n seats and n students in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. You are also given the array students of length n, where students[j] is the position of the jth student.

You may perform the following move any number of times:

    Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1)

Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

Note that there may be multiple seats or students in the same position at the beginning.

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2037 : public ::testing::Test {
public:
    static int minMovesToSeat(vector<int>& a, vector<int>& b) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int s = 0;
        for (int i = 0; i < a.size(); i++)
            s += abs(a[i] - b[i]);
        return s;
    }
};

TEST(Solution2037, T1) {
    vector<int> v1{3,1,5};
    vector<int> v2{2,7,4};
    int expected  = 4;
    ASSERT_EQ(expected,Solution2037::minMovesToSeat(v1,v2));
}
TEST(Solution2037, T2) {
    vector<int> v1{4,1,5,9};
    vector<int> v2{1,3,2,6};
    int expected  = 7;
    ASSERT_EQ(expected,Solution2037::minMovesToSeat(v1,v2));
}
TEST(Solution2037, T3) {
    vector<int> v1{2,2,6,6};
    vector<int> v2{1,3,2,6};
    int expected  = 4;
    ASSERT_EQ(expected,Solution2037::minMovesToSeat(v1,v2));
}