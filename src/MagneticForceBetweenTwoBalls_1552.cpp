/*
n the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.



Example 1:

Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.

Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.



Constraints:

    n == position.length
    2 <= n <= 105
    1 <= position[i] <= 109
    All integers in position are distinct.
    2 <= m <= position.length
*/

#include "../utils.h"
#include "gtest/gtest.h"

class Solution1552 : public ::testing::Test {
public:
    static int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = (position.back() - position[0]) / (m - 1);
        int ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canWePlace(position, mid, m)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    static bool canWePlace(const vector<int>& arr, int dist, int balls) {
        int countBalls = 1;
        int lastPlaced = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastPlaced >= dist) {
                countBalls++;
                lastPlaced = arr[i];
            }
            if (countBalls >= balls) {
                return true;
            }
        }
        return false;
    }
};


TEST(Solution1552, T1) {
    vector<int> position{1,2,3,4,7};
    int m = 3;
    int expected = 3;
    ASSERT_EQ(expected, Solution1552::maxDistance(position,m));
}

TEST(Solution1552, T2) {
    vector<int> position{5,4,3,2,1,1000000000};
    int m = 2;
    int expected = 999999999;
    ASSERT_EQ(expected, Solution1552::maxDistance(position,m));
}