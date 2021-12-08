#include<bits/stdc++.h>
using namespace std;
int merge(long long *arr, int start,int end){
    int i=start,mid=(start+end)/2+1,j=mid;
    int count=0;
    vector<int> temp;
    while(i<mid && j<=end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            count+=mid-i;
            j++;
        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    int k=0;
    for(int i=start;i<=end;i++){
        arr[i]=temp[k++];
    }
    return count;
}
int merge_sort(long long *arr, int start, int end){
    if(start>=end){
        return 0;
    }
    int mid=(start+end)/2;
    return merge_sort(arr,start,mid)+merge_sort(arr,mid+1,end)+merge(arr,start,end);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return merge_sort(arr,0,n-1);
}