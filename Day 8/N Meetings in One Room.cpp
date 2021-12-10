#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxMeetings(int start[], int end[], int n){
    vector<pair<int,int>> meetings(n);
    int count=0;
    for(int i=0;i<n;i++){
        meetings.push_back({end[i],start[i]});
    }
    sort(meetings.begin(),meetings.end());
    int curr_max=0;
    for(auto m:meetings){
        if(m.second>curr_max){
            count++;
            curr_max=m.first;
        }
    }
    return count;
}
int main(){
    int start[]={1,3,0,5,8,5};
    int end[]={2,4,6,7,9,9};
    int res=maxMeetings(start,end,6);
    cout<<res;
    return 0;
}