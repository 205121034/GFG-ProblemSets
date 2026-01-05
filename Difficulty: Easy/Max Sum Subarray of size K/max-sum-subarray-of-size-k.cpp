class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=arr[i];
        }
        int t=ans;
        for(int i=k;i<arr.size();i++){
            t-=arr[i-k];
            t+=arr[i];
            ans = max(ans,t);
        }
        return ans;
    }
};