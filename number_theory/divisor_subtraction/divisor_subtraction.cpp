#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    bool flag = false;
    if (n%2 != 0) { // if the number is odd we need to find the first divisor to subtract it from it and change the number into an even number (odd - even = even, even - even = even).
        long long mn = 1;
        for (long long i = 2 ; i * i <= n ; ++i) {
            if (n%i == 0) {
                mn = i;
                break;
            }
        }
        flag = true; // divior found.
        if (mn != 1) {
            n -= mn;
        } else { // prime number we can just do it in one operation.
            puts("1");
            return 0;
        }
    }
    int add = flag ? 1 : 0;
    cout << n/2 + add << endl; // otherwise we can just divide by 2 (even number) to get the number of divisions, and add one if there is a divisor for the odd number.
    return 0;
}