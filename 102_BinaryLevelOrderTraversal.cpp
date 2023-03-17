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
    void DFS(TreeNode* root, int depth, vector<vector<int>>& ans)
    {
        if(root == NULL)    return;
        if(depth == ans.size())
        {
            ans.resize(depth+1);
        }
        ans[depth].push_back(root->val);
        DFS(root->left, depth+1, ans);
        DFS(root->right, depth+1, ans);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        DFS(root, 0, ans);
        return ans;
    }
};

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

//Using BFS and queue
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> crtLevel; //crtLevel.reserve(n);
            for (int i = 0; i < n; i++)
            {
                TreeNode* p = q.front(); q.pop();
                if (p != nullptr)
                {
                    crtLevel.push_back(p->val);
                    q.push(p->left);
                    q.push(p->right);
                }
            }
            
            if (crtLevel.size() > 0)
            {
                //move = copy and clear
                //result.push_back(move(crtLevel));
                result.push_back(crtLevel);
                crtLevel.clear();
            }
            
        }
        
        return result;
    }
};