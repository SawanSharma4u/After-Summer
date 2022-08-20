class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> range(s.length()+2, 0);
        int n = shifts.size();
    	for(int i = 0; i < n; i++){
            if(shifts[i][2]==0){
                range[shifts[i][0]] -= 1;
                range[shifts[i][1]+1] += 1;
            }
    	    else{
                range[shifts[i][0]] += 1;
                range[shifts[i][1]+1] -= 1;
            }
    	}
    	int cnt = 0;
    	for(int i = 0; i < s.length(); i++){
    	    cnt += range[i];
            cnt = cnt%26;
            int temp = int(s[i])+cnt;
            if(temp > 'z'){
                s[i] = 'a' + (temp-'z'-1);
            }
            else if(temp < 'a'){
                s[i] = 'z' - ('a'-temp-1);
            }
            else s[i] = temp;
    	}
    	return s;
    }
};