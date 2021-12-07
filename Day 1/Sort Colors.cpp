class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N=nums.size();
        int L=0,R=N-1,M=0;
        while(M<=R){
            cout<<endl;
            if(nums[M]==0){
                swap(nums[L++],nums[M++]);
            }else if(nums[M]==1){
                M++;
            }else{
                swap(nums[M],nums[R--]);
            }
        }
    }
};