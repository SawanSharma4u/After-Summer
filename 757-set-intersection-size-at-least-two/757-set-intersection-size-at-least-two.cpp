class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1]!=b[1]){
            return a[1] < b[1];
        }
        else return a[0] > b[0];
    }
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int a = intervals[0][1]-1, b = intervals[0][1];
        int cnt = 2;
        for(auto i : intervals){
            if(i[0] <= a){
                continue;
            }
            else if(i[0] <= b){
                cnt++;
                a = b;
                b = i[1];
            }
            else{
                cnt+=2;
                a = i[1]-1;
                b = i[1];
            }
        }
        return cnt;
    }
};