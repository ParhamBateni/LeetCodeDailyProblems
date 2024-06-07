/*
 You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 */
#include "../utils.h"
#include "gtest/gtest.h"
class trie {
public:
    bool terminal;
    trie* next[26];
    trie() {
        terminal = false;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};
trie* base;
class Solution648 : public ::testing::Test {
    static void insert(string word) {
        int len = word.size();
        trie* iter = base;
        for (int i = 0; i < len; i++) {
            if (!iter->next[word[i] - 97]) {
                iter->next[word[i] - 97] = new trie();
            }
            iter = iter->next[word[i] - 97];
        }
        iter->terminal = true;
    }
    static string search(string &word) {
        int len = word.size();
        string cu;
        trie* iter = base;
        for (int i = 0; i < len; i++) {
            if (!iter->next[word[i] - 97]) {
                if (iter->terminal) return cu;
                return word;
            }
            cu += word[i];
            iter = iter->next[word[i] - 97];
            if (iter->terminal) return cu;
        }
        return cu;
    }
public:
    static string replaceWords(vector<string>& dictionary, string sentence) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        base = new trie();
        string ret, t;
        for (string i: dictionary) insert(i);
        for (char i: sentence) {
            if (i == ' ') {
                ret += search(t);
                ret += ' ';
                t.clear();
            } else {
                t += i;
            }
        }
        ret += search(t);
        return ret;
    }
};

TEST(Solution648, T1) {
    vector<string> dictionary{"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    string expected = "the cat was rat by the bat";
    ASSERT_TRUE(expected==Solution648::replaceWords(dictionary,sentence));
}

TEST(Solution648, T2) {
    vector<string> dictionary{"a","b","c"};
    string sentence = "aadsfasf absbs bbab cadsfafs";
    string expected = "a a b c";
    ASSERT_TRUE(expected==Solution648::replaceWords(dictionary,sentence));
}