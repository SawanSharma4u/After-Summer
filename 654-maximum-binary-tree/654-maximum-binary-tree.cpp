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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int st = 0, int end = -2) {
        if(end==-2) end = nums.size()-1;
        if(st > end) return nullptr;
        int maxIdx;
        int mxi = INT_MIN;
        for(int i = st; i <= end; i++){
            if(mxi < nums[i]){
                mxi = nums[i];
                maxIdx = i;
            }
        }
        TreeNode* root = new TreeNode(mxi);
        root->left = constructMaximumBinaryTree(nums, st, maxIdx-1);
        root->right = constructMaximumBinaryTree(nums, maxIdx+1, end);
        return root;
    }
};