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
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->left!=NULL){
                if(front->val%2==0){
                    if(front->left->left) ans += front->left->left->val;
                    if(front->left->right) ans += front->left->right->val;
                }
                q.push(front->left);
            }
            if(front->right!=NULL){
                if(front->val%2==0){
                    if(front->right->left) ans += front->right->left->val;
                    if(front->right->right) ans += front->right->right->val;
                }
                q.push(front->right);
            }
        }
        return ans;
    }
};