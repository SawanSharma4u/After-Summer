class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++){
            vector<int> temp;
            temp.push_back(intervals[i][0]);
            int t = intervals[i][1];
            while(i+1 < intervals.size() && t >= intervals[i+1][0]){
                t = max(t, intervals[i+1][1]);
                i++;
            }
            temp.push_back(t);
            ans.push_back(temp);
        }
        return ans;
    }
};