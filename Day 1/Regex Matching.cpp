class Solution {
public:
    bool patternMatching(string s, string p, int M, int N, vector<vector<int>> &dp){
        if(N<0 && M>=0){
            return false;
        }
        if(M<0){
            if(N<0){
                return true;
            }
            if(N>=0 && p[N]=='*'){
                return patternMatching(s,p,M,N-2,dp);
            }
            return false;
        }
        if(dp[M][N]!=-1){
            return dp[M][N];
        }
        if(p[N]=='*'){
            return dp[M][N]=patternMatching(s,p,M,N-2,dp) || ((p[N-1]==s[M] or p[N-1]=='.') && patternMatching(s,p,M-1,N,dp));
        }
        if(p[N]=='.' or p[N]==s[M]){
            return dp[M][N]=patternMatching(s,p,M-1,N-1,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int M=s.length();
        int N=p.length();
        vector<vector<int>> dp(M+1,vector<int>(N+1,-1));
        bool res=patternMatching(s,p,M-1,N-1,dp);
        return res;
    }
};