/*
 Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.



Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"

Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"

Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"



Constraints:

    The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
    Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
    The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
    The number of given fractions will be in the range [1, 10].
    The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

 */
#include "../utils.h"
#include "gtest/gtest.h"

class Solution592 : public ::testing::Test {
private:
    static int gcd(int a, int b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        int mn = min(a, b);
        int mx = max(a, b);
        for (int i = mn; i >= 1; i--) {
            if (mn % i == 0 && mx % i == 0)
                return i;
        }
        return 1;
    }

public:
    static string fractionAddition(string expression) {
        int resNumerator = 0, resDenominator = 1, numerator, denominator,
                sign = 1, tmp;
        int i = 0;
        while (i < expression.size()) {
            numerator = 0;
            denominator = 0;
            if (expression[i] == '-') {
                sign = -1;
                i++;
            } else if (expression[i] == '+') {
                sign = 1;
                i++;
            }
            while (expression[i] != '/') {
                numerator = numerator * 10 + (expression[i++] - '0');
            }
            i++;
            while (i < expression.size() && expression[i] != '-' &&
                   expression[i] != '+') {
                denominator = denominator * 10 + (expression[i++] - '0');
            }
            tmp = (resDenominator * denominator) /
                  gcd(resDenominator, denominator);
            resNumerator = resNumerator * tmp / resDenominator +
                           sign * numerator * tmp / denominator;
            resDenominator = tmp;
        }
        tmp = gcd(abs(resNumerator), resDenominator);
        resNumerator /= tmp;
        resDenominator /= tmp;
        return to_string(resNumerator) + "/" + to_string(resDenominator);
    }
};

TEST(Solution592, T1) {
    string expression = "-1/2+1/2";
    string expected = "0/1";
    ASSERT_TRUE(expected == Solution592::fractionAddition(expression));
}

TEST(Solution592, T2) {
    string expression = "-1/2+1/2+1/3";
    string expected = "1/3";
    ASSERT_TRUE(expected == Solution592::fractionAddition(expression));
}

TEST(Solution592, T3) {
    string expression = "1/3-1/2";
    string expected = "-1/6";
    ASSERT_TRUE(expected == Solution592::fractionAddition(expression));
}