class Solution {
public:
    // int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    //     int sum1 =0 , sum2 = 0;
    //     int runningSum1 = 0, runningSum2 = 0;
    //     int max1 = INT_MIN, max2 = INT_MIN;
    //     //My base array is num1;
    //     for(int i = 0; i < nums1.size(); i++){
    //         sum1 += nums1[i];
    //         sum2 += nums2[i];
    //         runningSum1 += nums2[i]-nums1[i];
    //         if(runningSum1 < 0) runningSum1 = 0;
    //         max1 = max(max1, runningSum1);
    //         runningSum2 += nums1[i]-nums2[i];
    //         if(runningSum2 < 0) runningSum2 = 0;
    //         max2 = max(max2, runningSum2);
    //     }
    //     return max(sum1 + max1, sum2 + max2);
    // }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
      int n=nums1.size();
      vector<long long>sum1;
       vector<long long>sum2;
      sum1.push_back(0);
      sum2.push_back(0);
      int i;
      for( i=0;i<n;i++){
        sum1.push_back(sum1.back()+nums1[i]);
        sum2.push_back(sum2.back()+nums2[i]);
                          }
      long long  fsum1=sum1[n];
      long long  fsum2=sum2[n];
      
      long long fans=max(fsum1,fsum2);
      
      for(int i=0;i<=n;i++){
        sum2[i]=sum2[i]-sum1[i];
        
                            }
     
      
      long long _maxdiff=INT_MIN,_min=0LL,_mindiff=INT_MAX,_max=0LL;
      
      for( i=1;i<=n;i++){
        if(sum2[i]-_min>_maxdiff)
            _maxdiff=sum2[i]-_min;
        
        if(_min>sum2[i])
                _min=sum2[i];
        
        if(sum2[i]-_max<_mindiff)
                   _mindiff=sum2[i]-_max;
        
        if(_max<sum2[i])
                  _max=sum2[i];
                               
                         }
      
      
     
      
      fans=max(fans,max(fsum2-_mindiff,fsum1+_maxdiff));
      
      
      return fans;
        
    }
};