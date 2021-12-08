vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n=A.size();
    long long int S=(n*(n+1))/2;
    long long int P=(n*(n+1)*(2*n+1)/6);
    for(int i=0;i<n;i++){
        S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
    long long int missing=(S+(P/S))/2;
    long long int repeated=missing-S;
    return {repeated,missing};
}