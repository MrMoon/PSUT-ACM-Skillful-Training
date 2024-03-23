#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	if(n <= k) return puts("NO") , 0; // if k is bigger or equal than n it is impossible to find the solution since there isn't at least k (k >= n) primes from 1 to n (the range is less than k).
	vector<bool> is_prime(n+2, true); // mark all numbers as "primes".
    is_prime[0] = is_prime[1] = false; // mark 0 and 1 as non-primes (base case).
    for (int i = 2; i <= n; i++) { // start from 2, the first known prime, and mark all its multiple as non-prime, and do the same for the rest of the numbers until n.
        if (is_prime[i] && (long long) i * i <= n) { // check if the current number is prime, we have to mark its multiples as non-primes.
            for (int j = i * i; j <= n; j += i) { // go from i^2; no need to start from earlier since other multiples has already been marked, recall the divisibility pair algorithm that works in sqrt(n), we add i each time to go to the next multiple.
            		is_prime[j] = false; // mark the multiples as non-primes.		 
            }
        }
    }
    vector<int> v;
	for(int i = 2 ; i <= n + 1 ; ++i) if(is_prime[i]) v.emplace_back(i); // emplace_back is a faster version of push_back.
	for(int i = 1 ; i < n ; ++i) {
		if(!k) break; // !k = (k == 0)
		int idx = v[i] + v[i - 1] + 1; // check the neighboring primes (twin primes) + 1.
		if(idx > n) break; // if the resulting number if bigger than the range no need to continue.
		k -= is_prime[idx]; // check the resulting number if it is prime or not.
	}
	puts(!k ? "YES" : "NO");
	return 0;
}
