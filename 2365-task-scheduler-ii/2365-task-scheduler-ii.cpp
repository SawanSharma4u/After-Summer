class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> mp;
        long long day = 0;
        for(int i = 0; i < tasks.size(); i++){
            if(mp.count(tasks[i])==0){
                day++;
            }
            else{
                if(day-mp[tasks[i]] >= space){
                    day++;
                }
                else{
                    day += space-(day-mp[tasks[i]])+1;
                }
            }
            mp[tasks[i]] = day;
        }
        return day;
    }
};