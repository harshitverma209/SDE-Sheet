class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        dp.push_back({1});
        if(numRows==1)   return dp;
        dp.push_back({1,1});
        if(numRows==2)  return dp;
        for(int i=3;i<=numRows;i++){
            vector<int> row(i,1);
            for(int j=1;j<i-1;j++){
                row[j]=dp[i-2][j-1]+dp[i-2][j];
            }
            dp.push_back(row);
        }
        return dp;
    }
};