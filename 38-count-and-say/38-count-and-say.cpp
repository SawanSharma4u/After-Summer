class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++){
            string temp = "";
            char last = ans[0];
            int cnt = 1;
            for(int j = 1; j < ans.length(); j++){
                if(ans[j]==last){
                    cnt++;
                }
                else{
                    temp += to_string(cnt) + last;
                    last = ans[j];
                    cnt = 1;
                }
            }
            temp += to_string(cnt) + last;
            ans = temp;
        }
        return ans;
    }
};