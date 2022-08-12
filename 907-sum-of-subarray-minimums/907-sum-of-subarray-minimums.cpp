class Solution {
    vector<int> findNext(vector<int> & arr){
        stack<int> s;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && arr[i] < arr[s.top()]){
                s.pop();
            }
            ans[i] = !s.empty() ? s.top() : n;
            s.push(i);
        }
        return ans;
    }
    vector<int> findPrev(vector<int> & arr){
        stack<int> s;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[i] <= arr[s.top()]){
                s.pop();
            }
            ans[i] = !s.empty() ? s.top() : -1;
            s.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        vector<int> prev = findPrev(arr);
        vector<int> next = findNext(arr);
        for(int i = 0; i < arr.size(); i++){
            ans  = (ans + (long)arr[i]*(i-prev[i])*(next[i]-i))%1000000007;
        }
        return ans;
    }
};