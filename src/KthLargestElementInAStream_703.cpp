/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
    int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.



Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8



Constraints:

    1 <= k <= 104
    0 <= nums.length <= 104
    -104 <= nums[i] <= 104
    -104 <= val <= 104
    At most 104 calls will be made to add.
    It is guaranteed that there will be at least k elements in the array when you search for the kth element.


 */
#include "../utils.h"
#include "gtest/gtest.h"

class KthLargest {
private:
    vector<int> nums;
    int k;

    int binSearch(int val) {
        int start = 0, end = nums.size() - 1, mid;
        while (start <= end) {
            mid = (end + start) / 2;
            if (nums[mid] > val) {
                end = mid - 1;
            } else if (nums[mid] < val) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return start;
    }

public:
    KthLargest(int k, vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        this->nums = nums;
        this->k = k;
    }

    int add(int val) {
        nums.insert(nums.begin() + binSearch(val), val);
        return nums[nums.size() - k];
    }
};

class Solution703 : public ::testing::Test {
public:
    static vector<int> kthLargest(int k, vector<int> &nums, vector<int> &add) {
        KthLargest kt = KthLargest(k, nums);
        vector<int> res;
        for (int num: add) {
            res.push_back(kt.add(num));
        }
        return res;
    }
};


TEST(Solution703, T1) {
    vector<int> nums{4, 5, 8, 2};
    int k = 3;
    vector<int> add{3, 5, 10, 9, 4};
    vector<int> expected{4, 5, 5, 8, 8};
    EXPECT_TRUE(expected == Solution703::kthLargest(k, nums, add));
}

TEST(Solution703, T2) {
    vector<int> nums{4, 5, 8, 2};
    int k = 3;
    vector<int> add{3, 5, 10, 9, 4};
    vector<int> expected{4, 5, 5, 8, 8};
    EXPECT_TRUE(expected == Solution703::kthLargest(k, nums, add));
}