class Solution {
public:
double myPow(double x, int n) {
        // Base case: x^0
        if (n == 0) { return 1; }
        
        long N = labs(n); // Returns absolute value as a long int
        double base = x;
        double factor = 1; // This is where we put the odd exponent
        
        while (N > 1) {
            if (N & 1) { // Exponent is odd
                factor = factor * base; // Pluck one exponent out
                --N;                    // Decrease exponent by 1
            } else {
                base = base * base; // O(lg(n)) time complexity
                N = N >> 1; // Integer division
            }
        }
        
        base = base * factor;
        
        return n > 0 ? base : 1 / base;
    }
};