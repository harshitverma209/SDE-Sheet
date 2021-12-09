int Solution::solve(vector<int> &A, int B) {
    long long count=0;
    int xord=0;
    unordered_map<int,int> m;
    for(int x:A){
        xord^=x;
        if(xord==B){
            count++;
        }
        int h=xord^B;
        if(m.find(h)!=m.end()){
            int c=m[h];
            count+=c;
        }
        m[xord]++;
    }
    return count;
}