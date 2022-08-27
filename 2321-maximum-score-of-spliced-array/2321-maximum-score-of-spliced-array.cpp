class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 =0 , sum2 = 0;
        int runningSum1 = 0, runningSum2 = 0;
        int max1 = INT_MIN, max2 = INT_MIN;
        //My base array is num1;
        for(int i = 0; i < nums1.size(); i++){
            sum1 += nums1[i];
            sum2 += nums2[i];
            runningSum1 += nums2[i]-nums1[i];
            if(runningSum1 < 0) runningSum1 = 0;
            max1 = max(max1, runningSum1);
            runningSum2 += nums1[i]-nums2[i];
            if(runningSum2 < 0) runningSum2 = 0;
            max2 = max(max2, runningSum2);
        }
        return max(sum1 + max1, sum2 + max2);
    }
};