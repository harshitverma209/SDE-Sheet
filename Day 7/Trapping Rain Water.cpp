class Solution {
public:
    int trap(vector<int>& height) {
        int N=height.size();
        if(N<=2){
            return 0;
        }
        vector<int> left(N,0);
        vector<int> right(N,0);
        left[0]=height[0];
        right[N-1]=height[N-1];
        for(int i=1;i<N;i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=N-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int totalTrappedWater=0;
        for(int i=0;i<N;i++){
            totalTrappedWater+=min(left[i],right[i])-height[i];
        }
        return totalTrappedWater;
    }
};