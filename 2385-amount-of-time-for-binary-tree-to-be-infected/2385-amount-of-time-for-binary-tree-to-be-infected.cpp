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
    bool flag = false;
    int solve(TreeNode* root, int start) {
        if(root==NULL) return 0;
        int left = solve(root->left, start);
        if(flag){
            flag = false;
            int right = solve(root->right, start);
            flag = true;
            ans = max(ans, left+right+1);
            return left+1;
        }
        int right = solve(root->right, start);
        if(root->val==start){
            flag = true;
            ans = max(left, right);
            return 0;
        }
        if(flag){
            ans = max(ans, left+right+1);
            return right+1;
        }
        return 1 + max(left, right);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);
        return ans;
    }
};