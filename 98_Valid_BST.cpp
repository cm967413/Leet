#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> v;
public:
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i = 0; i < v.size()-1; i++)
        {
            if(v[i] >= v[i+1])
                return false;
        }
        return true;
    }
};



class Solution2 {
public:
    bool recursive(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if(!root) return true;
        if((minNode && root->val <= minNode->val) || maxNode && root->val >= maxNode->val)
            return false;
        return recursive(root->left, minNode, root) && recursive(root->right, root, maxNode);
    }
    bool isValidBST(TreeNode* root) {
        return recursive(root, NULL, NULL);
    }
};



class Solution3 {
public:
    bool recursive(TreeNode* root, long min, long max)
    {
        if(!root) return true;
        if((root->val <= min) || root->val >= max)
            return false;
        return recursive(root->left, min, root->val) && recursive(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return recursive(root, LONG_MIN, LONG_MAX);
    }
};