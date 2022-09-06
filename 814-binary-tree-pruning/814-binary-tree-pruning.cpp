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
    bool solve(TreeNode* root){
        if(root==nullptr) return false;
        bool left = solve(root->left);
        bool right = solve(root->right);
        if(!left){
            root->left = nullptr;
        }
        if(!right){
            root->right = nullptr;
        }
        if(root->val==1 || left || right) return true;
        return false;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool ans=solve(root);
        if(ans) return root;
        return nullptr;
    }
};