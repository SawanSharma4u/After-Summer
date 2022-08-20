class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int idx;
        for(int i = 1; i < arr.size()-1; i++){
            if(arr[i]> arr[i-1] && arr[i] > arr[i+1]){
                idx = i;
                break;
            }
        }
        return idx;
    }
};