#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H
#include <ios>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
using namespace std;
#endif //LEETCODE_UTILS_H



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
