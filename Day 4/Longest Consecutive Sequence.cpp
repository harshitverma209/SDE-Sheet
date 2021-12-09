class Solution {
public:
int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int ans=0;
        int a=0;
        if(nums.size()==0)
            return 0;
        for(int i=0;i<nums.size();i++)
        {
           s.insert(nums[i]);
        }
        vector<int> v;
        set<int>::iterator it;
        for (it = s.begin(); it != s.end(); it++)
        {
            int curr=*it;
            if(s.find(curr-1)!=s.end()){
                ans++;
            }else
            {
                a=max(a,ans);
                ans=0;
            }
           a=max(a,ans);
        
        }

        return a+1;
    }
};