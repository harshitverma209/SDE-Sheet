class Solution {
public:
    void helper(vector<int> &nums, int idx, vector<int> &curr,  set<vector<int>> &res){
        if(idx==nums.size()){
            res.insert(curr);
            return;
        }
        helper(nums,idx+1,curr, res);
        curr.push_back(nums[idx]);
        helper(nums,idx+1,curr, res);
        curr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        vector<int> curr;
        helper(nums,0,curr,res);
        return vector<vector<int>>(res.begin(),res.end());
    }
};