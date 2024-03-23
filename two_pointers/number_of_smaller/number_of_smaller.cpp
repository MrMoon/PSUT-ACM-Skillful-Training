#include <bits/stdc++.h>

using namespace std;

int main() {
	#ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n); // initilize a vector of size n for the first array.
    vector<int> b(m); // initilize a vector of size m for the second array.
    vector<int> ans(m); // initilize a vector of size m for the answer.

    for (int i = 0 ; i < n ; ++i) // reading the ith value of a (from 0 to n - 1).
    	cin >> a[i];

    for (auto& x: b) // reading the values of b from 0 to m - 1.
    	cin >> x;

    int i = 0, j = 0; // the two pointers, i is the first array, and j is for the second array.
    for (j = 0 ; j < m ; ++j) {
    	// while the numbers in the first array are less than the number at b[j] (the number that j points at).
    	while(i < n and a[i] < b[j])
    		++i;
    	ans[j] = i; // there are i elements less than b[j].
    }

    for (auto x : ans)
    	printf("%d ",x);
    puts("");
    return 0;
}