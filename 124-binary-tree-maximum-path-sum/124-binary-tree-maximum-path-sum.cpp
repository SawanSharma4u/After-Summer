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
    pair<int, int> solve(TreeNode* root){
        pair<int, int> p;
        if(root==NULL){
            p = {0, INT_MIN};
            return p;
        }
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        int lh = left.first;
        int rh = right.first;
        p.first = max(lh, max(rh, 0)) + root->val;
        int sum = max(max(lh, rh), max(lh + rh, 0)) + root->val;
        p.second = max(max(left.second, right.second), sum);
        return p;
    }
public:
    int maxPathSum(TreeNode* root) {
        pair<int, int> p;
        p = solve(root);
        return p.second;
    }
};