#include <bits/stdc++.h>
using namespace std;
const long long M = 2760727302517;

long long binExpItr(long long a, long long b){
    long long ans = 1;
    while (b)
    {
        if(b & 1) ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;// used LL because value usd for calculations are in long long because values can exceed the long longeger range but the main ans is stord in long longeger so declared as long longeger
        b = (b >> 1);
    }
    return ans;    
}

long long calculateSumOfSquaredDifferences(long long a[], long long n) {
    long long sum = 0, sumSquared = 0;

    for (long long i = 0; i < n; i++) {
        sum += a[i];
        sumSquared += a[i] * a[i];
    }

    long long ans = n * sumSquared - sum * sum;
    return ans;
}


long long main()
{
	long long t;
	cin >> t;
	while(t--){
		long long n, q;
		cin >> n >> q;
		vector<long long> a(n);
		for (long long i = 0; i < n; i++){
			cin >> a[i];
		}
		while(q--){
			long long w;
			cin >> w;
			if(w == 1 or w == 2){
				long long v;
				long long x;
				cin >> x >> v;
				if(w == 1){
					a[x - 1] = v;
				}
				if(w == 2){
					a[x - 1] += v;
				}
			}
			long long ans = 0;
			if(w == 3){
				for (long long i = 0; i < n; i++)
				{
					for (long long j = i; j < n; j++)
					{
						ans += binExpItr((a[i] - a[j]), 2);
					}
				}
				cout << ans << endl;
			}
		}
		
	}
	return 0;
}