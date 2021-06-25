int lcs(int na, int nb, string sA, string sB){
        int dp[na+1][nb+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i<=na; i++){
            
            for(int j = 1; j<=nb; j++){
                if(sA[i-1]==sB[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[na][nb];
    }
