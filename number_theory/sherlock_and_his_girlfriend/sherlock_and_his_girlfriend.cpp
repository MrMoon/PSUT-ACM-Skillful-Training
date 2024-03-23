#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  vector<bool> a(n + 2);
  ++n;
  // sieve.
  for(long long i = 2 ; i <= n ; ++i) if(!a[i]) for(long long j = i * i ; j <= n ; j += i) a[j] = true;
  // if n is less than 3 we use only 1 number
  puts(n > 3 ? "2" : "1");
  // if the number is prime we can just color it in 1, otherwise, we can color it in 2.
  // proof: prime numbers have no prime divisors of each other, 
  // composite numbers can be represented as prime numbers hence they just are colored in the other color.
  for(int i = 2 ; i <= n ; ++i) printf("%d ",a[i] + 1);
  puts("");
  return 0;
}