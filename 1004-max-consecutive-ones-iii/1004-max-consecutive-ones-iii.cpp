class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0;
        int l = 0, r = 0;
        int cnt = 0;
        bool flag = true;
        while(r < nums.size()){
            if(cnt==k+1){
                flag = false;
                cnt--;
                l++;
                while(l < nums.size() && nums[l-1]!=0){
                    l++;
                }
            }
            if(nums[r] == 0){
                cnt++;
                len = max(len, r-l);
            }
            else len = max(len, r-l+1);
            r++;
        }
        if(flag) return nums.size();
        return len;
    }
};