#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  // cool animation, https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
  // sieve's algorithms works as follows, 
  // it assumes all numbers are primes, then starts with the first prime and marks all of its multiples as non-primes, because they all have a diviors (the current number).
  // then it goes to the next number that has not been marked yet and does the same thing and so on until n.
  // Complexity: O(nlog(log(n))) Geometric Series of (1/2 + 1/3 + 1/4 + 1/5 + ... + 1/n) or integration of 1/x from 1 to n.
  vector<bool> is_prime(n+1, true); // mark all numbers as "primes".
  is_prime[0] = is_prime[1] = false; // mark 0 and 1 as non-primes (base case).
  for (int i = 2; i <= n; i++) { // start from 2, the first known prime, and mark all its multiple as non-prime, and do the same for the rest of the numbers until n.
      if (is_prime[i] && (long long) i * i <= n) { // check if the current number is prime, we have to mark its multiples as non-primes.
          for (int j = i * i; j <= n; j += i) { // go from i^2; no need to start from eariler since other multiples has already been marked, recall the divisibliy pair algorithm that works in sqrt(n), we add i each time to go to the next multiple.
          		is_prime[j] = false; // mark the multiples as non-primes.		 
          }
      }
  }
  return 0;
}
