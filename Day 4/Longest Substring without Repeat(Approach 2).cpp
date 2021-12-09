class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N=s.length();
        vector<int> m(256,-1);
        int left=0,right=0,length=0,maxLength=0;
        while(right<N){
            if(m[s[right]]!=-1){
                left=max(left,m[s[right]]+1);
            }
            m[s[right]]=right;
            length=right-left+1;
            maxLength=max(length,maxLength);
            right++;
        }
        return maxLength;
    }
};