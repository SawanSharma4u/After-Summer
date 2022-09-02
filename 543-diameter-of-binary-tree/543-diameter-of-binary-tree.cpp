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
        pair<int, int> ans = make_pair(0, 0);
        if(root==NULL) return ans;
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        ans.first = max(left.second + right.second +1, max(left.first, right.first));
        ans.second = max(left.second, right.second)+1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0; 
        pair<int, int> ans = solve(root);
        return ans.first-1;
    }
};