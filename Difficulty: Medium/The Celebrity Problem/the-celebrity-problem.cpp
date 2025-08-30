class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<int> follower(n,0);
        vector<int> following(n,0);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(mat[i][j]==1){
                    follower[j]++;
                    following[i]++;
                }
            }
        }
        int celeb=-1;
        for(int i=0; i<n; ++i){
            if(follower[i]==n && following[i]==1){
                celeb=i;
            }
        }
        return celeb;
    }
};