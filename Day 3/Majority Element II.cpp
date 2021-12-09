class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1, num2, count1 = 0, count2 = 0;
        int n = nums.size();
        for(int num : nums)
            if(num1 == num) count1++;
            else if(num2 == num) count2++;
            else if(count1 == 0) num1 = num, count1++;
            else if(count2 == 0) num2 = num, count2++;
            else count1--, count2--;
        
        count1 = count2 = 0;
        for(int num : nums)
            if(num1 == num) count1++;
            else if(num2 == num) count2++;
        
        vector<int> ans;
        if(count1 > n/3) ans.push_back(num1);
        if(count2 > n/3) ans.push_back(num2);
        return ans;
    }
};