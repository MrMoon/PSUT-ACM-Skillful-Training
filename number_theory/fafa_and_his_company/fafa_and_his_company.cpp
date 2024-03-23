#include <iostream>
 
using namespace std;
 
int main(){
  int n , ans = 1;
  scanf("%d",&n);
 
  // to divide n employees equally on l leaders, the number of employees has to divide the number of leaders;
  // recall the divisibility equation, a | b => b = a*k for some integer k. So, we need to find such numbers for n.
  // the reason it is i * i <= n is because the diviors always comes in pairs a * b = n, 
  // and the maximum number for a and b is square root of n, otherwise a * b will be bigger than n.
  for(int i = 2 ; i * i <= n ; i++) {  // we start from 2 because we already started the ans from 1.
    if (n%i == 0) {
      ans++;
      ans += (i * i != n); // perfect squares have a pair of divisors that are the same (16: 4 * 4), so we don't have to count 4 twice.
    }
  }
 
  printf("%d\n",ans);
}
