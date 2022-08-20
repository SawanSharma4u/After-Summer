class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int idx;
        int i = 0, j = arr.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
                idx = mid;
                break;
            }
            else if(arr[mid] > arr[mid-1]){
                i = mid;
            }
            else j = mid;
        }
        return idx;
    }
};