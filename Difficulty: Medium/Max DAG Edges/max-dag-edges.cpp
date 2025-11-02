class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
          int kalai=edges.size();
        int max =(V*(V-1))/2;
        return max-kalai;
        
    }
};
