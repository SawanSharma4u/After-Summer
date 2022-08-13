class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]%k;
            sum = sum%k;
            int need = (k+sum)%k;
            if(mp.find(need)!=mp.end()) cnt += mp[need];
            mp[need]++;
        }
        return cnt;
    }
};