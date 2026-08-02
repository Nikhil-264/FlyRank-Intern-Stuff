#include <bits/stdc++.h>
using namespace std;

void prntVec(vector<int> v)
{
    cout << "Size : " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int N;
    // cin >> N;
    // vector<int> v[N]; // array of vectors
    // for (int i = 0; i < N; i++)
    // {
    //     int n;
    //     cin >> n;
    //     for (int j = 0; j < n; j++)
    //     {
    //         int x;
    //         cin >> x;
    //         v[i].push_back(x);
    //     }
    //     prntVec(v[i]);
    // }

    // vectors of vectors
    int N;
    cin >> N;
    vector<vector<int>> v;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v.push_back(vector<int>()); //***if not to use temp method
        // vector<int> temp;// just to use temp method uncomment temp parts and comment down comment with ***
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x); //***
            // temp.push_back(x);
        }
        // v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        prntVec(v[i]);
    }
    return 0;
}