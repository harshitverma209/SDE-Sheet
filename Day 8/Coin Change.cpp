#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int coinChange(vector<int> coins, int m, vector<int> &dp){
    //Base Case
    if(m==0){
        return 0;
    }
    int minCoins=INT_MAX;
    if(dp[m]!=-1){
        return dp[m];
    }
    for(int i=0; i<coins.size(); i++){
        int coin=coins[i];
        if(coin<=m){
            int rem_coins=coinChange(coins,m-coin,dp);
            if(rem_coins!=INT_MAX){
                minCoins = min(rem_coins+1,minCoins);
            }
        }
    }
    return dp[m]=minCoins;
}
int main(){
    vector<int> coins={3,7,10};
    int m=5;
    vector<int> dp(m+1,-1);
    int res=coinChange(coins,m,dp);
    // for(int x:dp){
    //     cout<<x<<"\t";
    // }
    // cout<<endl;
    if(res==INT_MAX){
        cout<<"NOT POSSIBLE";
    }else{
        cout<<res;
    }
    return 0;
}