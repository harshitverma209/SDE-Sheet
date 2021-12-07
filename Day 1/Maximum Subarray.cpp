class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,mSum=INT_MIN;
        for(int x:nums){
            sum+=x;
            mSum=max(sum,mSum);
            sum=max(sum,0);
        }
        return mSum;
    }
};