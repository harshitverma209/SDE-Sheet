class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1; 
        vector<int> numbers; 
        for(int i = 1;i<=n;i++) {
            fact = fact * i; 
            numbers.push_back(i); 
        }
        string ans="";
        k--;
        fact=fact/n;
        while(1){
            ans+=to_string(numbers[k/(fact)]);
            numbers.erase(numbers.begin()+k/(fact));
            k%=fact;
            if(numbers.size()==0){
                break;
            }
            fact=fact/numbers.size();
        }
        return ans;
    }
};