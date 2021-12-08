class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> distinctIntervals;
        vector<int> tempInterval(2,0);
        tempInterval=intervals[0];
        for(auto interval:intervals){
            if(tempInterval[1]>=interval[0]){
                tempInterval[1]=max(tempInterval[1],interval[1]);
            }
            else{
                distinctIntervals.push_back(tempInterval);
                tempInterval=interval;
            }
        }
        distinctIntervals.push_back(tempInterval);
        return distinctIntervals;
    }
};