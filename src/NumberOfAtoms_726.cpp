/*
Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

    For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.

Two formulas are concatenated together to produce another formula.

    For example, "H2O2He3Mg4" is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula.

    For example, "(H2O2)" and "(H2O2)3" are formulas.

Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.



Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.

Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.

Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.



Constraints:

    1 <= formula.length <= 1000
    formula consists of English letters, digits, '(', and ')'.
    formula is always valid.

*/
#include "../utils.h"
#include "gtest/gtest.h"


class Solution726 : public ::testing::Test {
private:
    static map<string, int> countAtoms(string formula) {
        map<string, int> mp, mp_tmp;
        int i = 0, c = 0, cnt, n = formula.size();
        string tmp, el;
        while (i < n) {
            if (c > 0)
                tmp += formula[i];
            if (formula[i] == '(')
                c++;
            else if (formula[i] == ')') {
                c--;
                if (c == 0) {
                    cnt = 0;
                    while (++i < n && formula[i] <= '9' && formula[i] >= '0')
                        cnt = cnt * 10 + (int)(formula[i] - '0');
                    i--;
                    cnt = max(1, cnt);
                    mp_tmp = countAtoms(tmp.substr(0, tmp.size() - 1));
                    for (auto& m : mp_tmp) {
                        mp[m.first] += m.second * cnt;
                    }
                    tmp = "";
                }
            } else {
                if (c == 0) {
                    el = formula[i];
                    while (++i < n && formula[i] >= 'a') {
                        el += formula[i];
                    }
                    i--;
                    cnt = 0;
                    while (++i < n && formula[i] <= '9' && formula[i] >= '0')
                        cnt = cnt * 10 + (int)(formula[i] - '0');
                    i--;
                    cnt = max(1, cnt);
                    mp[el] += cnt;
                }
            }
            i++;
        }
        return mp;
    }

public:
    static string countOfAtoms(string formula) {
        string res;
        for (auto& m : countAtoms(formula)) {
            res += m.first;
            if (m.second > 1)
                res += to_string(m.second);
        }
        return res;
    }
};

TEST(Solution726, T1) {
    string formula = "H2O";
    string expected  = "H2O";
    ASSERT_TRUE(expected == Solution726::countOfAtoms(formula));
}


TEST(Solution726, T2) {
    string formula = "Mg(OH)2";
    string expected  = "H2MgO2";
    ASSERT_TRUE(expected == Solution726::countOfAtoms(formula));
}

TEST(Solution726, T3) {
    string formula = "K4(ON(SO3)2)2";
    string expected  = "K4N2O14S4";
    ASSERT_TRUE(expected == Solution726::countOfAtoms(formula));
}
