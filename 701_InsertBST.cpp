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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *ans = root;
        if(!root)
        {
            ans = new TreeNode(val);
            return ans;
        }
        while(true)
        {
            if(root -> val > val)
            {
                if(root -> left)
                    root = root -> left;
                else
                {
                    root -> left = new TreeNode(val);
                    return ans;
                }
            }
            else if (root -> val < val)
            {
                if(root -> right)
                    root = root-> right;
                else
                {
                    root -> right = new TreeNode(val);
                    return ans;
                }
            }
        }
    }
};