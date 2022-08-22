class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                sum += nums[i];
            }
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        vector<long long> minHeap;
        minHeap.push_back(sum);
        priority_queue<pair<long, long>> maxHeap;
        maxHeap.push({sum-nums[0], 0});
        while(minHeap.size() < k){
            auto [value, index] = maxHeap.top();
            maxHeap.pop();
            minHeap.push_back(value);
            if(index+1 < nums.size()){
                maxHeap.push({value + nums[index] - nums[index+1], index+1});
                maxHeap.push({value-nums[index+1], index+1});
            }
        }
        return minHeap[k-1];
    }
};