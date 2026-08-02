// Maze problem HackerRank

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n + 1][m + 1] = {0};
	int hsh[n + 1][m + 1] = {INT_MAX};
	int maxi = INT_MIN;
	for (auto i = 1; i <= n; ++i)
	{
		for (auto j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}
	cout << maxi << endl;
}