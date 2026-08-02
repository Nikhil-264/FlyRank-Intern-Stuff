#include <bits/stdc++.h>
using namespace std;

void JacobiMethod(vector<vector<double>> &a, vector<double> &b, vector<double> &initialGuess, double w){
    int n = a.size();
    vector<double> x(n, 0);
    x = initialGuess;
    int maxIter = 20;
    int iter = 0;
    
    while(iter < maxIter){
        vector<double> nNew;
        for(int i = 0; i < n; i++){
            double sum = 0;
            for(int j = 0; j < n; j++){
                if(j != i){
                    sum += x[j] * a[i][j];
                }
            }
            sum = b[i] - sum;
            double newValue = sum / a[i][i];
            
            // Apply relaxation factor w
            newValue = (1 - w) * x[i] + w * newValue; // Relaxation factor is w
            
            nNew.push_back(newValue);
        }
        iter++;
        
        // Print the current iteration with the solution rounded to 5 decimal places
        for(int i = 0; i < n; i++){
            cout << fixed << setprecision(5) << nNew[i] << " ";
        }
        cout << endl;
        
        // Update x for the next iteration
        x = nNew;
    }
}

int main()
{
    vector<vector<double>> a = {{3, -2, 1},
                                {1, 3, -1},
                                {1, -2, 3}};
    vector<double> b = {2, 3, 2};
    vector<double> initialGuess = {0, 0, 0};

    // Try with different relaxation factors w = 0.9, 1.0, 1.1
    for(double w : {0.9, 1.0, 1.1}) {
        cout << "Results for w = " << w << ":" << endl;
        JacobiMethod(a, b, initialGuess, w);
        cout << endl;
    }
    
    return 0;
}
