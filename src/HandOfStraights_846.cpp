/*
 Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution846 : public ::testing::Test {
public:
    static bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = hand.size();
        if (n%groupSize!=0) return false;
        sort(hand.begin(),hand.end());
        map<int,int> occurences;
        for (int num:hand){
            if (occurences.count(num)){
                occurences[num]++;
            }
            else occurences[num] = 1;
        }
        for (int num: hand){
            if (occurences[num]==0) continue;
            occurences[num]--;
            for (int i=1;i<groupSize;i++){
                if (occurences.count(num+i) && occurences[num+i]>0) occurences[num+i]--;
                else return false;
            }
        }
        return true;
    }
};

TEST(Solution846, T1) {
    vector<int> v {1,2,3,4,5};
    int groupSize = 4;
    bool expected = false;
    ASSERT_EQ(expected, Solution846::isNStraightHand(v,groupSize));
}


TEST(Solution846, T2) {
    vector<int> v {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;
    bool expected = true;
    ASSERT_EQ(expected, Solution846::isNStraightHand(v,groupSize));
}