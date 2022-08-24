class Solution {
public:
    bool isMatch(string str, string ptr) {
        int star=-1;
        int ss = 0;
        int i = 0, j = 0;
        while(i < str.length()){
            if(str[i]==ptr[j] || ptr[j]=='?'){
                i++;
                j++;
                continue;
            }
            if(ptr[j]=='*'){
                star = j++;
                ss = i;
                continue;
            }
            if(star!=-1){
                j = star + 1;
                i = ++ss;
                continue;
            }
            return false;
        }
        while(j < ptr.length() && ptr[j] == '*'){
            j++;
        }
        return j==ptr.length();
    }
};