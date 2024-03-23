#include <bits/stdc++.h>

using namespace std;

int main() {
  long long b;
  int ans = 0;
  scanf("%lld", &b);

  // recall the gcd algorithm, and that the gcd(a, b) is one of diviors in some pair of both a and b,
  // the other divior is the lcm(a, b), hence, a * b = gcd(a, b) * lcm(a, b).
  // so, lcm(a, b)/a = b/gcd(a, b), note that we don't know a here just b.
  // To get all the numbers that ivan will write the equation b/gcd(a, b) must have an integer result,
  // so the numbers that divides b, will have integer results for such equation, so we simply get all the diviors of b.
  for(long long i = 1 ; i * i <= b ; ++i) {
    if(b%i == 0) {
      ++ans;
      if (i * i != b) ++ans;
    }
  }
  printf("%d\n",ans);
  return 0;
}
