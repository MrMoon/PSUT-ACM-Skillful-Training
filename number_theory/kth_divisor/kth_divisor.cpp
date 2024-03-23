#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n;
  int k;
  scanf("%lld%d",&n, &k);

  // we don't initialize the vector size here because we don't know how many divisors n has, 
  // and we care about the size the we compute later to check if there is a kth divisor or not.
  vector<long long> ans; 

  for(long long i = 1 ; i * i <= n ; ++i){ // i is long long because i * i can become larger than an int.
    if(n%i == 0){
      ans.push_back(i); // the first diviors of the pairs.
      if(i * i != n) ans.push_back(n/i); // the second divior of the pair. We don't add it if i * i is a perfect square.
    }
  }
  // sort the diviors because the order is important and it is not necessary to get the right sequence from the loop above.
  sort(ans.begin(), ans.end());
  if (k > (int) ans.size()) {
    puts("-1"); // there is no kth divisor.
  } else {
    printf("%lld\n",ans[k - 1]);
  }
  return 0;
}