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
    map<int, vector<pair<int, int>>> ans;
    void solve(TreeNode* root, int col, int row){
        if(root==NULL){
            return;
        }
        solve(root->left, col-1, row+1);
        ans[col].push_back({row, root->val});
        solve(root->right, col+1, row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);
        vector<vector<int>> result;
        for(auto st : ans){
            vector<int> temp;
            sort(st.second.begin(), st.second.end());
            for(auto i : st.second){
                temp.push_back(i.second);
            }
            result.push_back(temp);
        }
        return result;
    }
};