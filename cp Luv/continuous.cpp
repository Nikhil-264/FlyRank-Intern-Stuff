// making continuos subarrays/ substring using recurtion and backtracking

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generate(string &s)
    {
        vector<string> subsets;
        for (int i = 0; i < s.size(); i++)
        {
            string str = "";
            for (int j = i; j < s.size(); j++)
            {
                str.push_back(s[j]);
                subsets.push_back(str);
            }
        }
        return subsets; // but its O(n^2) *sad
        // learn O(n*log(n))
    }
};
int main()
{
    Solution ok;
    string st;
    cin >> st;
    vector<string> ans = ok.generate(st);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
// Code corrected by chatGPT
// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     vector<string> ans;

//     void generate(string &name, int start, int end)
//     {
//         ans.push_back(name.substr(start, end - start + 1)); // Add the current substring to the result
//         if (end < name.size() - 1) // If possible, include the next character in the substring
//             generate(name, start, end + 1);
//     }

//     vector<string> contSubstrings(string s)
//     {
//         for (int start = 0; start < s.size(); start++)
//         {
//             for (int end = start; end < s.size(); end++)
//             {
//                 generate(s, start, end);
//             }
//         }
//         return ans;
//     }
// };

// int main()
// {
//     Solution ok;
//     string s;
//     cin >> s;
//     vector<string> main_ans = ok.contSubstrings(s);
//     sort(main_ans.begin(), main_ans.end()); // Sort to remove duplicates
//     main_ans.erase(unique(main_ans.begin(), main_ans.end()), main_ans.end()); // Remove duplicates
//     for (int i = 0; i < main_ans.size(); i++)
//     {
//         cout << main_ans[i] << endl;
//     }

//     return 0;
// }
