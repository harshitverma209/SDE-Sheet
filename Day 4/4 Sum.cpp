class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int N=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int twosum=target-(nums[i]+nums[j]);
                int left=j+1;
                int right=N-1;
                while(left<right){
                    if(twosum>nums[left]+nums[right]){
                        left++;
                    }else if(twosum<nums[left]+nums[right]){
                        right--;
                    }else{
                        vector<int> quad={nums[i],nums[j],nums[left],nums[right]};
                        res.push_back(quad);
                        while(left<right and nums[left]==quad[2]){
                            left++;
                        }
                        while(left>right and nums[right]==quad[3]){
                            right++;
                        }
                    }
                }
                while(j+1<N and nums[j]==nums[j+1]){
                    j++;
                }

            }
            while(i+1<N and nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};