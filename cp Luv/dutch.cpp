// Dutch National Flag Algorithm
// sorting array of 0, 1 and 2
#include<bits/stdc++.h>
// status : 
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define ins insert
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrtl(x)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define ct(x,v) count(all(v),x)
#define revsort(v) sort(v.rbegin(),v.rend())
#define reverse(v) reverse(all(v))

// Containers
typedef pair<int, int>      pii;
typedef pair<ll, ll>        pll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef vector<vi>          vvi;
typedef vector<vl>          vvl;
typedef pair<string,string> pss;
typedef map<int, int>       mii;
typedef set<int>            si;

// couts
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define p(s) cout << s << "\n";


#define in(x) cin >> x;
#define inv(a) for (int i = 0; i < a.size(); ++i) cin >> a[i];
#define inv1(a) for (int i = 1; i < a.size(); ++i) cin >> a[i];
#define outv(a) for (int i = 0; i < a.size(); ++i) cout << a[i] << " ";
#define outv1(a) for (int i = 1; i < a.size(); ++i) cout << a[i] << " ";
#define endit cout << "\n";


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


void solve(){
    int n;
    cin >> n;
    vi a(n);
    inv(a);
    int low = 0, mid, high = n - 1;

    while(a[mid] == 0){
        mid++;
    }

    while(a[high] == 2){
        high--;
    }

    while (mid <= high) {
        if(a[mid] == 1){
            mid++;
        }
        else if(a[mid] == 0){
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else{
            swap(a[mid], a[high]);
            high--;
        }
    }
    
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();       
    }

    return 0;
}