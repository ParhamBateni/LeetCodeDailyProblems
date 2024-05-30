/*
 Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

    a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
    b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.
 */
#include "../utils.h"
#include "gtest/gtest.h"
class Solution1442:public::testing::Test{
public:
    static int countTriplets(vector<int>& arr) {
        // (i,j,k) <=> xors[j-1]^xors[i-1]^xors[k]^xors[j-1] =0  <=> xors[i-1] ^ xors[k] = 0 <=> xors[i-1] = xors[k]
        int n = arr.size();
        arr.insert(arr.begin(),0);
        int cnt =0;
        for (int i=1;i<=n;i++){
            arr[i] ^= arr[i-1];
        }
        for (int i=0;i<n;i++){
            for (int k=i+1;k<n;k++){
                if (arr[i]==arr[k+1]) cnt+=k-i;
            }
        }
        return cnt;
    }
};

TEST(Solution1442,T1){
    vector<int> v {2,3,6,1,7};
    ASSERT_EQ(4,Solution1442::countTriplets(v));
}
TEST(Solution1442,T2){
    vector<int> v {1,1,1,1,1};
    ASSERT_EQ(10,Solution1442::countTriplets(v));
}