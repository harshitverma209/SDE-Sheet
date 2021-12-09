class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M=matrix.size();
        int N=matrix[0].size();
        int i=M-1,j=0;
        while(i>=0 and j<N){
            if(matrix[i][j]>target){
                i--;
            }else if(matrix[i][j]<target){
                j++;
            }else{
                return true;
            }
        }
        return false;
    }
};