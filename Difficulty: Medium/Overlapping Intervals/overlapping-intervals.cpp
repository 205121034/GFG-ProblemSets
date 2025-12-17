class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
          sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int n = arr.size();
        
        for(int i=1; i<n; i++){
            int start = arr[i][0];
            int lastBack = ans.back()[1];
            if(start <= lastBack){
                ans.back()[1] = max(lastBack, arr[i][1]);
            }else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};
