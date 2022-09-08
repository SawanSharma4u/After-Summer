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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        vector<int> Left = inorderTraversal(root->left);
        vector<int> Right = inorderTraversal(root->right);
        
        vector<int> ans;
        for(int i=0;i<Left.size();i++){
            ans.push_back(Left[i]);
            }
        ans.push_back(root->val);
        for(int i = 0; i<Right.size();i++){
            ans.push_back(Right[i]);
            }
        return ans;
    }
};