class Solution {
  public:
    int minCost(vector<int>& h) {
        // Code here
        int n=h.size();
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        dp[1]=abs(h[0]-h[1]);
        for(int i=2;i<n;i++)
        {
            int a=abs(h[i]-h[i-1])+dp[i-1];
            int b=abs(h[i]-h[i-2])+dp[i-2];
            dp[i]=min(a,b);
            
        }
        return dp[n-1];
    }
};