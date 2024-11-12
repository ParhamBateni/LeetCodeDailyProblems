/*
 You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.

You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.

Return an array answer of the same length as queries where answer[j] is the answer to the jth query.

 

Example 1:

Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
Output: [2,4,5,5,6,6]
Explanation:
- For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the answer for this query is 2.
- For queries[1]=2, the items which can be considered are [1,2] and [2,4]. 
  The maximum beauty among them is 4.
- For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
  The maximum beauty among them is 5.
- For queries[4]=5 and queries[5]=6, all items can be considered.
  Hence, the answer for them is the maximum beauty of all items, i.e., 6.

Example 2:

Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
Output: [4]
Explanation: 
The price of every item is equal to 1, so we choose the item with the maximum beauty 4. 
Note that multiple items can have the same price and/or beauty.  

Example 3:

Input: items = [[10,1000]], queries = [5]
Output: [0]
Explanation:
No item has a price less than or equal to 5, so no item can be chosen.
Hence, the answer to the query is 0.

 

Constraints:

    1 <= items.length, queries.length <= 105
    items[i].length == 2
    1 <= pricei, beautyi, queries[j] <= 109


 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution2070 : public ::testing::Test {
private:
    static int findMaxBeauty(const vector<vector<int>>& items, int price) {
        int left = 0, right = items.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= price) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }

public:
    static vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(items.begin(), items.end());


        vector<int> maxBeauty(items.size());
        maxBeauty[0] = items[0][1];
        for (int i = 1; i < items.size(); i++) {
            maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
        }

        vector<int> results;
        results.reserve(queries.size());

        for (int price : queries) {
            int index = findMaxBeauty(items, price);
            if (index == -1) results.push_back(0);
            else results.push_back(maxBeauty[index]);
        }

        return results;
    }
};

TEST(Solution2070, T1) {
    vector<vector<int>> items {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> queries {1,2,3,4,5,6};
    vector<int> expected{2,4,5,5,6,6};
    ASSERT_TRUE(expected == Solution2070::maximumBeauty(items, queries));
}