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
    bool DFS(TreeNode* leftSub, TreeNode* rightSub)
    {
        if(leftSub == NULL && rightSub == NULL) return true;
        else if(leftSub == NULL || rightSub == NULL) return false;
        else if(leftSub->val != rightSub->val) return false;
        else //(leftSub->val == rightSub->val)
        {   
            return DFS(leftSub->left, rightSub->right) && DFS(leftSub->right, rightSub->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* leftSub = root->left;
        TreeNode* rightSub = root->right;
        return DFS(leftSub, rightSub);
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode *leftSub = q.front(); q.pop();
            TreeNode *rightSub = q.front(); q.pop();
            
            if(!leftSub && !rightSub)   continue;
            else if(!leftSub || !rightSub) return false;
            else if(leftSub->val != rightSub->val) return false;
            else
            {
                q.push(leftSub->left);
                q.push(rightSub->right);
                q.push(leftSub->right);
                q.push(rightSub->left);
            }
        }
        return true;
    }
};