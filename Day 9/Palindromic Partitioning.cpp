class Solution {
public:
    bool isPal(string &s,int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void helper(string &s, int idx, vector<string> &curr, vector<vector<string>> &res){
        if(idx==s.length()){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPal(s,idx,i)){
                //Partition Possible
                curr.push_back(s.substr(idx,i-idx+1));
                helper(s,i+1,curr,res);
                curr.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        helper(s,0,curr,res);
        return res;
    }
};