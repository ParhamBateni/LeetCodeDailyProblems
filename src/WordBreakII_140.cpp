/*
 * Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.*/

#include "../utils.h"
#include "gtest/gtest.h"

class Solution140 : public ::testing::Test {
public:
    static vector<string> wordBreak(string s, vector<string> &wordDict, int index = 0) {
        if (index >= s.size())return vector<string>{""};
        vector<string> ans{};
        for (string word: wordDict) {
            if (s.substr(index, word.size()) == word) {
                vector<string> r = wordBreak(s, wordDict, index + word.size());
                for (string s2: r) {
                    ans.push_back(s2 != "" ? word + " " + s2 : word);
                }
            }
        }
        return ans;
    }
};

TEST(Solution140, T1) {
    string s = "catsanddog";
    vector<string> wordDict{"cat", "cats", "and", "sand", "dog"};
    vector<string> expected{"cat sand dog", "cats and dog"};
    ASSERT_TRUE(expected == Solution140::wordBreak(s, wordDict));
}

TEST(Solution140, T2) {
    string s = "pineapplepenapple";
    vector<string> wordDict{"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> expected{"pine apple pen apple", "pine applepen apple", "pineapple pen apple"};
    ASSERT_TRUE(expected == Solution140::wordBreak(s, wordDict));
}

TEST(Solution140, T3) {
    string s = "catsandog";
    vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
    vector<string> expected{};
    ASSERT_TRUE(expected == Solution140::wordBreak(s, wordDict));
}