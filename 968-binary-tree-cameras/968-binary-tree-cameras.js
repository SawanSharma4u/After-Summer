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
    int cnt = 0;
    int solve(TreeNode* root, int p){
        if(root==NULL) return 0;
        int left = solve(root->left, p-1);
        int right = solve(root->right, p-1);
        if(left==-1 || right==-1){
            cnt++;
            return 1;
        }
        else if(left == 0 && right == 0){
            return -1;
        }
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        int r = solve(root, -1);
        if(r==-1) cnt++;
        return cnt;
    }
};