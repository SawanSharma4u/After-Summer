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
    int ans = 0;
    pair<int, int> solve(TreeNode* root){
        pair<int, int> p = {0, 0}, r, l;
        if(root==NULL) return p;
        l = solve(root->left);
        r = solve(root->right);
        int sum = root->val + l.first + r.first;
        int n = l.second + r.second + 1;
        
        if(root->val == sum/n) ans++;
        p.first = sum;
        p.second = n;
        return p;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};