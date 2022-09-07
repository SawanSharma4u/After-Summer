class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
         unordered_map<char, int> chek;
        for(int i = 0; i < t.size(); i++){
            ++chek[t[i]];
        }
        int i = 0, j = 0;
        int k = 0, ans = INT_MAX;
        int st, ed; 
        bool f = true;
        while(k < s.length()){
            if(chek.find(s[k])!=chek.end()){
                --chek[s[k]];
                j = k;
                bool flag = false;
                for(auto i:chek){
                    if(i.second > 0){
                        flag = true;
                    }
                }
                if(!flag){
                    f = false;
                    while(i < s.length() && chek.find(s[i])==chek.end() || chek[s[i]] < 0){
                        if(chek.find(s[i])!=chek.end()){
                            ++chek[s[i]];
                        }
                        i++;
                    }
                }
                if(!flag && ans > j-i+1){
                    st = i;
                    ed = j;
                    ans = j-i+1;
                }
            }
            k++;
        }
        if(f) return "";
        string str="";
        for(; st <= ed; st++){
            str += s[st];
        }
        return str;
    }
};