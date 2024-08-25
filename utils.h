#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <ios>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include "stack"
#include <numeric>
#include <unordered_set>

using namespace std;
#endif


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    static TreeNode* vectorToTree(vector<int> l) {
        if (l.empty() || l[0] == 0) return nullptr;  // Edge case: empty tree or root is NULL

        // Create the root node
        TreeNode* root = new TreeNode(l[0]);
        std::queue<TreeNode*> q;
        q.push(root);

        int i = 1;  // Start from the second element in the vector

        while (!q.empty() && i < l.size()) {
            TreeNode* current = q.front();
            q.pop();

            // Process the left child
            if (i < l.size() && l[i] != 0) {
                current->left = new TreeNode(l[i]);
                q.push(current->left);
            }
            i++;  // Move to the next element

            // Process the right child
            if (i < l.size() && l[i] != 0) {
                current->right = new TreeNode(l[i]);
                q.push(current->right);
            }
            i++;  // Move to the next element
        }

        return root;
    }

    static vector<int> treeToVector(TreeNode *root) {
        vector<int> res;
        queue<TreeNode *> st;
        st.push(root);
        TreeNode *node;
        while (st.size()) {
            node = st.front();
            st.pop();
            if (node == nullptr) res.push_back(0);
            else {
                res.push_back(node->val);
                if (node->right || node->left) {
                    st.push(node->left);
                    st.push(node->right);
                }
            }
        }
        int i = res.size()-1;
        while (res[i]==0) res.erase(res.begin()+i--);
        return res;
    }
};

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode *vectorToList(vector<int> l) {
        ListNode *prev = nullptr;
        for (int i = l.size() - 1; i >= 0; i--) {
            ListNode *root = new ListNode(l[i]);
            root->next = prev;
            prev = root;
        }
        return prev;
    }

    static vector<int> listToVector(ListNode *node) {
        vector<int> res;
        while (node != nullptr) {
            res.push_back(node->val);
            node = node->next;
        }
        return res;
    }
};



