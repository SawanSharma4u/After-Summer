class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int, long long> mp;
        for(int i =0; i < n; i++){
            nums[i] -= i;
            ++mp[nums[i]];
        }
        long long ans = n*(n-1)/2;
        for(auto i = mp.begin(); i != mp.end(); i++){
            long long t = i->second;
            ans -= t*(t-1)/2;
        }
        return ans;
    }
};