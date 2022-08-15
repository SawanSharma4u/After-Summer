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
    int solve(TreeNode* root, int fromP){
        if(root==NULL) return fromP;
        int right = solve(root->right, fromP);
        root->val += right;
        int left = solve(root->left, root->val);
        return left;
        
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        solve(root, 0);
        return root;
    }
};