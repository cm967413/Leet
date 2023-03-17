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
    int max_dep = 0;
public:
    void DFS(TreeNode* root, int depth)
    {
        if(root == NULL)    return;
        //cout << root->val << "  "<< depth << endl;
        max_dep = (depth>max_dep) ? depth : max_dep;
        DFS(root->left, depth + 1);
        DFS(root->right,depth + 1);
        return;
    }
    
    int DFS(TreeNode* root)
    {
        if(root == NULL)    return 0;
        int maxLeftSub = DFS(root->left);
        int maxRightSub = DFS(root->right);
        return max(maxLeftSub, maxRightSub) + 1;
    }
    int maxDepth(TreeNode* root) {
        return DFS(root);
    }
};