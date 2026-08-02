#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &histo)
    {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
            {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                cout << "height: " << height << " width: " << width << endl;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
};

int main()
{
    int t = 1;
    // cin >> t;
    while(t--){
        vector<int> heights = {2, 3, 4, 5, 6};
        Solution sol;
        cout << sol.largestRectangleArea(heights) << endl;
    }
    return 0;
}