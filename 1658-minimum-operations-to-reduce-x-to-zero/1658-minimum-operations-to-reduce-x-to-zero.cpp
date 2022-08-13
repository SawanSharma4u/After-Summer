class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len = INT_MAX;
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        for(; i < nums.size(); i++){
            cnt += nums[i];
            if(cnt==x){
                len = i+1;
                break;
            }
            else if(cnt > x) break;
        }
        if(i==n) {
            if(cnt!=x) return -1;
            i--;
        }
        for(int j = nums.size()-1; j >= 0; j--){
            cnt += nums[j];
            while(i >= 0 && cnt > x){
                cnt -= nums[i];
                i--;
            }
            if(cnt==x) len = min(len, i+1+n-j);
            if(i==0) break;
        }
        return len==INT_MAX?-1:len;
    }
};