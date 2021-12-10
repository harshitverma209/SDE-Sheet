class Solution {
public:
    void findCombinations(vector<int> &candidates, int M, int N,vector<int> &curr,                vector<vector<int>> &res){
        if((N<0 and M>0) or M<0){
            return;
        }
        if(M==0){
            //Add here
            res.push_back(curr);
            return;
        }
        findCombinations(candidates,M,N-1,curr,res);
        if(candidates[N]<=M){
            curr.push_back(candidates[N]);
            findCombinations(candidates,M-candidates[N],N,curr,res);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int N=candidates.size();
        vector<vector<int>> res;
        vector<int> curr;
        findCombinations(candidates,target,N-1,curr,res);
        return res;
    }
};