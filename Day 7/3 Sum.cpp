class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N=nums.size();
        sort(nums.begin(),nums.end());
        int target=0;
        vector<vector<int>> res;
        for(int i=0;i<N;i++){
            int left=i+1,right=N-1;
            int new_target=target-nums[i];
            while(left<right){
                int two_sum=nums[left]+nums[right];
                if(two_sum<new_target){
                    left++;
                }else if(two_sum>new_target){
                    right--;
                }else{
                    vector<int> triplets={nums[i],nums[left],nums[right]};
                    res.push_back(triplets);
                    while(left<right and nums[left]==triplets[1]){
                        left++;
                    }
                    while(left<right and nums[right]==triplets[2]){
                        right--;
                    }
                }
            }
            while(i+1<N and nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};