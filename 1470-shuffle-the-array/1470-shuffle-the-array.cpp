class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = n-1, j = nums.size()-1;
        for(; j >= n; j--, i--){
            nums[j] = nums[j] | (nums[i]<<10);
        }
        j = n;
        for(i = 0; i < 2*n; i=i+2,j++){
            nums[i] = nums[j]>>10;
            nums[i+1] = nums[j] ^ (nums[i]<<10);
        }
        return nums;
    }
};