class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        int lastPos = 0;
        int i = 0;
        int jump = 0;
        while(lastPos < n-1){
            maxReach = max(maxReach, nums[i] + i);
            if(i==lastPos){
                lastPos = maxReach;
                jump++;
            }
            i++;
        }
        return jump;
    }
};