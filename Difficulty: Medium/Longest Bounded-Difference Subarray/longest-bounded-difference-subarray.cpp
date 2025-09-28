class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int ans=1;
        
        int mx=arr[0];
        int mn=arr[0];
        
        int l=0;
        int j=0;
        
        multiset<int>si;
        multiset<int,greater<int>>sd;
        si.insert(arr[0]);
        sd.insert(arr[0]);
        
        for(int r=1;r<n;r++){
            si.insert(arr[r]);
            sd.insert(arr[r]);
            if(arr[r] > mx){
                mx=arr[r];
                while(mx-mn > x && !si.empty() && !sd.empty() && r>=l){
                    auto i=si.find(arr[l]);
                    auto I=sd.find(arr[l]);
                    if(*i == mn) mn=*(next(si.begin()));
                    si.erase(i);
                    sd.erase(I);
                    l++;
                }
            }
            else if(arr[r] < mn){
                mn=arr[r];
                while(mx-mn > x && !sd.empty() && !si.empty() && r>=l){
                    auto i=sd.find(arr[l]);
                    auto I=si.find(arr[l]);
                    if(*i == mx) mx=*(next(sd.begin()));
                    sd.erase(i);
                    si.erase(I);
                    l++;
                }
            }
            if(r-l+1 > ans){
                ans=r-l+1;
                j=l;
            }
        }
        
        vector<int>v;
        for(int i=j;i<j+ans;i++){
            v.push_back(arr[i]);
        }
        return v;
    }
};