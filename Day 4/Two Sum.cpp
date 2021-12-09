class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int n1=nums[i];
            int n2=target-n1;
            if(m.count(n2)!=0){
                return {i,m[n2]};
            }
            m[n1]=i;
        }
        return {};

    }
};