class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N=prices.size();
        vector<int> left(N,INT_MAX);
        left[0]=prices[0];
        for(int i=1;i<N;i++){
            left[i]=min(left[i-1],prices[i]);
        }
        int profit=0;
        for(int i=0;i<N;i++){
            profit=max(profit, prices[i]-left[i]);
        }
        return profit;
    }
};