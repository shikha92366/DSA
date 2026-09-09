class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        vector<bool> prime(n, true);

        prime[0] = prime[1] = false;

        // Remove all even numbers
        for (int i = 4; i < n; i += 2) {
            prime[i] = false;
        }

        // Sieve only odd numbers
        for (int i = 3; i * i < n; i += 2) {

            if (prime[i]) {

                for (int j = i * i; j < n; j += 2 * i) {
                    prime[j] = false;
                }
            }
        }

        int count = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i])
                count++;
        }

        return count;
    }
};