class Solution {
public:
    int minSteps(int n) {
        if(n<=1) return 0;
        int ans = 0;
        bool flag = false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i==0){
                ans+=i;
                n = n/i;
                flag = true;
                break;
            }
        }
        if(!flag) return n;
        return ans + minSteps(n);
    }
};