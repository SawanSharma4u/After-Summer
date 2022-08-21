class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> arr(10, 0);
        for(auto i : num){
            arr[i-'0']++;
        }
        string mid;
        bool ch = false;
        string st = "";
        for( int i = 9; i >=0; i--){
            if(i==0 && st.length()==0) continue;
            if(arr[i]%2!=0 && !ch){
                mid = to_string(i);
                ch = true;
            }
            if(arr[i]/2!=0){
                int cnt = arr[i]/2;
                while(cnt--){
                    st += to_string(i);
                }
            }
        }
        if(st.length()==0 && mid.length()==0) return "0";
        num = st + mid;
        reverse(st.begin(), st.end());
        return num + st;
    }
};