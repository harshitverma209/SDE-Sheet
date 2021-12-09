class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N=nums.size();
        int count=0, curr;
        for(int x:nums){
            if(count==0){
                curr=x;
            }
            if(curr==x){
                count++;
            }else{
                count--;
            }
        }
        return curr;
    }
};