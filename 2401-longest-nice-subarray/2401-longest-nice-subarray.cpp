class Solution {
    int find(int i, int j, vector<int>& arr, int num){
        while(i <= j){
            int mid = (i+j)/2;
            if((arr[i]&num)==0){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return i;
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int sum = nums[0];
        int st = 0;
        int cnt = 1;
        vector<int> arr(nums.size());
        arr[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if((sum&nums[i])==0){
                sum = sum | nums[i];
                arr[i] = sum;
                cnt++;
                ans = max(ans, cnt);
            }
            else{
                st = find(st, i-1, arr, nums[i]);
                cnt = 1;
                i = ++st;
                sum = nums[i];
                arr[i] = nums[i];
            }
        }
        return ans;
    }
};