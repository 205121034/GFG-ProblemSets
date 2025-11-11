class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.length();
        int n = s2.length();
        
        // Create a DP table to store LCS lengths
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill the DP table for LCS
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Length of shortest supersequence
        // = length of s1 + length of s2 - length of LCS
        int lcsLen = dp[m][n];
        return m + n - lcsLen;
    }
};