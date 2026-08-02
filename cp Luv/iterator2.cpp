// some short methods to write the iterators
// thsi feature avaliable after C++ 11
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {2, 3, 4, 5, 6, 9};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    // we can use this syntax to shorten the time o write the code
    for (int value : v)
    {
        value++;
        cout << value << " "; // i it will make v copy of the value from the vector
    }                         // Range based loops
    cout << endl;
    for (int value : v)
    {
        cout << value << " "; // i it will make v copy of the value from the vector you can sse by this code that even the value is incremented in the frst loop its not incremeneted in the second loop that why it usesw copy of the value in this loop
    }                         // Range based loops
    cout << endl;
    for (int &value : v)
    {
        value++;
        cout << value << " "; // i it will make v copy of the value from the vector
    }                         // Range based loops
    cout << endl;             // if we use & int he loop it wont be the copy of elements it will use the direct valur from vector
    auto a = 'd';// auto keyword will identify  the data type dynamically
    // cout << a << endl;
    cout << typeid(a).name() << endl;// so we can use it in the iterator
    // vector<int>::iterator it;// byn using auto keyword we dont have to write the gievm line

    for (auto it = v.begin(); it < v.end(); it++)
    {
        cout << (*it) << " ";
    }
    
    return 0;
}