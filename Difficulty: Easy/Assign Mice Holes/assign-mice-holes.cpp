class Solution {
  public:
    int assignHole(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int res=0;
        for(int i=0;i<a.size();i++)
        {
            res=max(res,abs(b[i]-a[i]));
        }
        return res;
    }
};