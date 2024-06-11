/*
 Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1122 : public ::testing::Test {
public:
    static vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        map<int,int> occurences;
        int i;
        for (i=0;i<n;i++){
            if (occurences.count(arr1[i]))occurences[arr1[i]]++;
            else occurences[arr1[i]]= 1;
        }
        vector<int> res(n,0);
        i = 0;
        for (int num: arr2){
            fill(res.begin()+i,res.begin()+i+occurences[num],num);
            i+=occurences[num];
            occurences[num] = 0;
        }
        for (auto p: occurences){
            if (p.second!=0) {
                fill(res.begin()+i,res.begin()+i+p.second,p.first);
                i+=p.second;
            }
        }
        return res;
    }
};

TEST(Solution1122, T1) {
    vector<int> v1 {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> v2 {2,1,4,3,9,6};
    vector<int> expected {2,2,2,1,4,3,3,9,6,7,19};
    ASSERT_TRUE(expected==Solution1122::relativeSortArray(v1,v2));
}

TEST(Solution1122, T2) {
    vector<int> v1 {28,6,22,8,44,17};
    vector<int> v2 {22,28,8,6};
    vector<int> expected {22,28,8,6,17,44};
    ASSERT_TRUE(expected==Solution1122::relativeSortArray(v1,v2));
}
