class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> left;
        int cnt = -1, n = nums.size(), t = 0;
        for(int i = 0; i < n; i++){
            left.push_back(cnt);
            if(nums[i]%2==1){
                cnt = i;
                t++;
            }
        }
        if(cnt==-1 || t < k) return 0;
        cnt = n;
        vector<int> right(n);
        for(int j = n-1; j >= 0; j--){
            right[j] = cnt;
            if(nums[j]%2==1) cnt = j;
        }
        int ans = 0;
        int l = -1, r = 0, i = 0;
        cnt = 1;
        while(i < n && l==-1){
            if(nums[i]%2==1){
                l=i;
            }
            i++;
        }
        while(i < n && cnt < k){
            if(nums[i]%2==1) cnt++;
            i++;
        }
        r = i-1;
        while(r < n){
            ans += (l-left[l])*(right[r]-r);
            l++;
            r++;
            while(l < n && nums[l]%2==0){
                l++;
            }
            while(r < n && nums[r]%2==0){
                r++;
            }
        }
        return ans;
    }
};