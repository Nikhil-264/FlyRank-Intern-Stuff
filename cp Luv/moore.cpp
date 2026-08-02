// Moore's Voting Algorithm
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v){
    int ct = 0;
    int el;
    for (int i = 0; i < v.size(); i++)
    {
        if(ct == 0){
            ct = 1;
            el = v[i];
        }
        else if(v[i] == el){
            ct++;
        }
        else{
            ct--;
        }
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == el) cnt++;
    }
    if(cnt > (v.size() / 2)){
        return el;
    }
    else return -1;
}

int main()
{
    
    return 0;
}