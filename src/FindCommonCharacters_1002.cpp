/*
 Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution1002 : public ::testing::Test {
public:
    static vector<string> commonChars(vector<string>& words) {
        int occurences[26]={0};
        if (words.size()==0) return vector<string>();
        for (char c : words[0]){
            occurences[c-'a']++;
        }
        for (int i = 1;i<words.size();i++){
            int newOccurences[26]={0};
            for (char c: words[i]){
                newOccurences[c-'a']++;
            }
            for (int i =0;i<26;i++){
                occurences[i] = min(occurences[i],newOccurences[i]);
            }
        }
        vector<string> res;
        for (int i=0;i<26;i++){
            for (int j =0;j<occurences[i];j++) res.push_back(string(1,'a'+i));
        }
        return res;
    }
};

TEST(Solution1002, T1) {
    vector<string> v {"bella","label","roller"};
    vector<string> expected {"e","l","l"};
    ASSERT_TRUE(expected==Solution1002::commonChars(v));
}

TEST(Solution1002, T2) {
    vector<string> v {"cool","lock","cook"};
    vector<string> expected {"c","o"};
    ASSERT_TRUE(expected==Solution1002::commonChars(v));
}