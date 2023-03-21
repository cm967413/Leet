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
public:
bool flag = false;
    void DFS(TreeNode* root, int targetSum, int cur)
    {
        if(root)
        {
            cur += root->val;
            if(cur == targetSum && !root->left && !root->right)
            {
                flag = true;
                return;
            }
            DFS(root->left, targetSum, cur);
            DFS(root->right, targetSum, cur);
        }
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        DFS(root, targetSum, 0);
        return flag;
    }
};


//Clean
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(root->val == targetSum && !root->left && !root->right) return true;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};