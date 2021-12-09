class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int N=nums.size();
        if(N==0){
            return 0;
        }
        int max1=0,count=0;
        for(int i=0;i<N;i++){
            if(nums[i]==1){
                count++;
            }else{
                count=0;
            }
            max1=max(max1,count);
        }
        return max1;
    }
};