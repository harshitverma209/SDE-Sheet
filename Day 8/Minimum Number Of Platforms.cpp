#include<bits/stdc++.h>
 using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    int count=1;
    int res=1;
    sort(arr,arr+n);
    sort(dep,dep+n);
    int i=1,j=0;
    while(i<n and j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }else{
            j++;
            count--;
        }
        res=max(res,count);
    }
    return res;
 }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }