class Solution {
public:
    int merge(vector<int> &arr, int start,int end){
    int i=start,mid=(start+end)/2+1,j=mid;
    int count=0;
    vector<int> temp;
        for(i=start;i<mid;i++){
            while(j<=end and arr[i] > 2LL*arr[j]){
                j++;
            }
            count += (j - mid);
        }
        i=start;
        j=mid;
    while(i<mid && j<=end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
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
int merge_sort(vector<int> &arr, int start, int end){
    if(start>=end){
        return 0;
    }
    int mid=(start+end)/2;
    return merge_sort(arr,start,mid)+merge_sort(arr,mid+1,end)+merge(arr,start,end);
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return 0;
        return merge_sort(nums,0,n-1);
    }
};