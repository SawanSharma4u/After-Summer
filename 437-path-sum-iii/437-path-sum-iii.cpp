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
    unordered_map<long long, list<int>> mp;
    int solve(TreeNode* root, int t, long long sum, int depth){
        if(root==NULL) return 0;
        sum += root->val;
        int ans = 0;
        if(mp.count(sum-t)==1){
            ans += mp[sum-t].size();
        }
        mp[sum].push_back(depth);
        ans += solve(root->right, t, sum, depth+1) + solve(root->left, t, sum, depth+1);
        mp[sum].pop_back();
        if(mp[sum].size()==0){
            mp.erase(sum);
        }
        sum -= root->val;
        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        mp[0].push_back(0);
        return solve(root, targetSum, 0, 1);
    }
};