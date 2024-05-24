/*
 Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.
 */
#include "../utils.h"
#include "gtest/gtest.h"
vector<int> Scores;
vector<string> Words;
class Solution1255:public::testing::Test{
public:
    static int traverse(vector<int>& occ, int index = 0) {
        if (index == Words.size())
            return 0;
        vector<int> occCopy = occ;
        bool possible = true;
        int score = 0;
        for (char c : Words[index]) {
            if (occCopy[c - 'a'] > 0) {
                occCopy[c - 'a']--;
                score += Scores[c - 'a'];
            } else {
                possible = false;
                break;
            }
        }
        return possible ? max(score + traverse(occCopy, index + 1),
                              traverse(occ, index + 1))
                        : traverse(occ, index + 1);
    }

    static int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        Scores = score;
        Words = words;
        vector<int> occ(26, 0);
        for (char c : letters)
            occ[c - 'a']++;
        return traverse(occ);
    }
};

TEST(Solution1255,T1){
    vector<string> words{"dog","cat","dad","good"};
    vector<char> letters{'a','a','c','d','d','d','g','o','o'};
    vector<int> score{1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    ASSERT_EQ(23,Solution1255::maxScoreWords(words,letters,score));
}
TEST(Solution1255,T2){
    vector<string> words{"xxxz","ax","bx","cx"};
    vector<char> letters{'z','a','b','c','x','x','x'};
    vector<int> score{4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    ASSERT_EQ(27,Solution1255::maxScoreWords(words,letters,score));
}
TEST(Solution1255,T3){
    vector<string> words{"leetcode"};
    vector<char> letters{'l','e','t','c','o','d'};
    vector<int> score{0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
    ASSERT_EQ(0,Solution1255::maxScoreWords(words,letters,score));
}