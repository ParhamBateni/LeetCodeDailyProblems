/*
Convert a non-negative integer num to its English words representation.



Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"



Constraints:

    0 <= num <= 231 - 1


 */
#include "../utils.h"
#include "gtest/gtest.h"

map<int, string> digitsI{{1, "One"},
                         {2, "Two"},
                         {3, "Three"},
                         {4, "Four"},
                         {5, "Five"},
                         {6, "Six"},
                         {7, "Seven"},
                         {8, "Eight"},
                         {9, "Nine"}};
map<int, string> digitsII{
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {1,  "Ten"},
        {2,  "Twenty"},
        {3,  "Thirty"},
        {4,  "Forty"},
        {5,  "Fifty"},
        {6,  "Sixty"},
        {7,  "Seventy"},
        {8,  "Eighty"},
        {9,  "Ninety"}};

class Solution273 : public ::testing::Test {
private:
    static string numberToWords3Digits(int num) {
        if (num < 10)
            return digitsI[num] + " ";
        if (num >= 10 && num < 20)
            return digitsII[num] + " ";
        string s;
        int n = num / 100;
        if (n != 0)
            s += digitsI[n] + " Hundred ";
        n = num % 100;
        if (n != 0) {
            if (n < 10) {
                s += digitsI[n] + " ";
                return s;
            }
            if (n >= 10 && n < 20) {
                s += digitsII[n] + " ";
                return s;
            }
            n /= 10;
            s += digitsII[n] + " ";
        }
        n = num % 10;
        if (n != 0)
            s += digitsI[n] + " ";
        return s;
    }

public:
    static string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string s;
        int n1 = num / 1e9, n2 = (int) (num / 1e6) % (int) 1e3,
                n3 = (int) (num / 1e3) % (int) 1e3, n4 = num % (int) 1e3;
        if (n1 != 0)
            s += numberToWords3Digits(n1) + "Billion ";
        if (n2 != 0)
            s += numberToWords3Digits(n2) + "Million ";
        if (n3 != 0)
            s += numberToWords3Digits(n3) + "Thousand ";
        if (n4 != 0)
            s += numberToWords3Digits(n4);
        return s.substr(0, s.size() - 1);
    }
};

TEST(Solution273, T1) {
    int num = 123;
    string expected = "One Hundred Twenty Three";
    ASSERT_TRUE(expected == Solution273::numberToWords(num));
}

TEST(Solution273, T2) {
    int num = 12345;
    string expected = "Twelve Thousand Three Hundred Forty Five";
    ASSERT_TRUE(expected == Solution273::numberToWords(num));
}

TEST(Solution273, T3) {
    int num = 1234567;
    string expected = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";
    ASSERT_TRUE(expected == Solution273::numberToWords(num));
}