class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int N=s.length();
        int cl=0,ml=0;
        int i=0,j=0;
        while(i<=j and j<N){
            char c=s[j];
            m[c]++;
            while(m[c]>=2){
                m[s[i]]--;
                i++;
            }
            cl=j-i+1;
            ml=max(cl,ml);
            j++;
        }
        return ml;
    }
};