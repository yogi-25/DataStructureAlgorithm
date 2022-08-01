class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        int count = 0;
        for(int i = 2; i*i < n; ++i) {
            if(primes[i] == true) {
                for(int j = i*i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        for(int i = 2; i < n; ++i) {
            if(primes[i]) {
                count++;
            }
        }
        return count;
    }
};