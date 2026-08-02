// medium example
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
long long int ar[N];

int main()
{
	// your code goes here
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b, d;
		cin >> a >> b >> d;
		ar[a] += d;
		ar[b + 1] -= d; // concept of hashing and prefix sum mixed
	}
	for (int i = 1; i <= n; ++i)
		ar[i] += ar[i - 1];
	long long max = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (max < ar[i])
			max = ar[i];
	}
	cout << max << endl;

	return 0;
}
// 5 3
// 1 2 100
// 2 5 100
// 3 4 100//this is test input//200 is output
