#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;// add size when using unione by size,
public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);

        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    // for using uninone by size we have to declare the size vector that we dont need in the union by rank so use one of the at a time dont use bth of them at a time and while using using by rank comment out the size part

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; 
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.findUPar(3) == ds.findUPar(7)) cout << "YES" << endl;
    else cout << "NO" << endl;
    cout << ds.findUPar(7) << endl;

    ds.unionByRank(3, 7);
    
    if(ds.findUPar(3) == ds.findUPar(7)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}