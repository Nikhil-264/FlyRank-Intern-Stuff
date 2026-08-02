// Rotating the matrix by 90 degrees

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> mat, int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
                swap(mat[i][j], mat[j][i]);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     reverse(mat[i].begin(), mat[i].end());
    // }
    return mat;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (auto &row : mat)
    {
        for (auto &x : row)
            cin >> x;
    }
    rotateMatrix(mat, n);
    for (const auto &row : mat)
    {
        for (const auto &x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}