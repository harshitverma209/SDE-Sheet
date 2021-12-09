#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int largestSubarray(vector<int> &arr, int target){
    unordered_map<int, int> m;
    int maxLen=0;
    int currSum=0;
    for(int i = 0; i < arr.size();i++){
        int ele=arr[i];
        currSum+=ele;
        if(currSum==target){
            maxLen=max(maxLen,i+1);
        }else{
            if(m.find(currSum-target)!=m.end()){
                maxLen=max(maxLen,i-m[currSum-target]);
            }else{
                m[currSum]=i;
            }
        }
    }
    return maxLen;
}
int main(){
    vector<int> arr={15,-2,2,-8,1,7,10,23};
    int res=largestSubarray(arr,0);
    cout<<res<<endl;
    return 0;
}