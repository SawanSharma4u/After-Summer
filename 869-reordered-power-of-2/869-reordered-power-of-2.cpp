class Solution {
    int* count(int n){
        int* ans = new int[10];
        while(n > 0){
            ans[n%10]++;
            n/=10;
        }
        return ans;
    }
public:
    bool reorderedPowerOf2(int n) {
        int* cnt = count(n);
        for(int i = 0; i < 31; i++){
            int* temp = count(1<<i);
            int j = 0;
            while(j < 10){
                if(cnt[j]==temp[j]) j++;
                else break;
            }
            if(j==10) return true;
        }
        return false;
    }
};