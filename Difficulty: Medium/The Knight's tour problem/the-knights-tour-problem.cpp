class Solution {
  public:
    vector<vector<int>> knightTour(int n) {        vector<vector<int>> vis(n, vector<int>(n, -1));
        vis[0][0] = 0;
        
        int dirr[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
        int dirc[8] = {-1, 1, -1, 1, 2, -2, 2, -2}; 
        
        auto isValid = [&](int nr, int nc) -> bool {
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == -1) return true;
            return false;
        };
        function<bool(int, int)> f = [&](int r, int c) -> bool {
            
            if(vis[r][c] == n * n - 1) {
                return true;
            }
            
            for(int i = 0; i < 8; i++) {
                int nr = r + dirr[i];
                int nc = c + dirc[i];
                
                if(isValid(nr, nc)) {
                    
                    vis[nr][nc] = vis[r][c] + 1;
    
                    if(f(nr, nc)) 
                    {
                        return true;
                    }
                    else
                    {
                        vis[nr][nc] = -1;
                    }
                    
                }
            }
            
            return false;
            
        };
        
        if(f(0, 0) == false) return {};
        
        return vis;
    }
};