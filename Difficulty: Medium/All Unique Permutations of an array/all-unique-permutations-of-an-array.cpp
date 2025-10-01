class Solution {
  public:
   vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        set<vector<int>> st;
        
        do {
             st.insert(arr);
        } while(next_permutation(arr.begin(),arr.end()));
      
       vector<vector<int>> ans;
       for(auto it : st)
       {
           ans.push_back(it);
       }
       return ans;   
    }


};