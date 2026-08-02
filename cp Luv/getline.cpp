// // #include <bits/stdc++.h>
// // using namespace std;

// // int main()
// // {    string str1,str2;
// //     getline(cin,str1);
// //     getline(cin,str2);// by using getline funvtion we can take whole line as input otherwise normal cin wiould not take spaces as character it will break string as soon as it sees space or newline character
// //     cout << str1 << endl << str2;
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;
// // string s = "Hello\nWorld"; // \n is a special character in C++ to
// int main()
// {
//     // string str;
//     // getline(cin, str);
//     // string str_rev;
//     // for (int i = str.size() - 1; i >= 0; i--)
//     // {
//     //     str_rev.push_back(str[i]);
//     // }
//     // cout << str_rev << endl;
//     // if(str == str_rev) cout << "YES" << endl;
//     // else cout << "NO" << endl;// this is reversing string
//     // extracting digit from a string
//     // string s;
//     // cin >> s;
//     // int last_digit = s[s.size() -1] - '0';// subtracting ascii value of 0 from ascii value of digit to get the digit from string as integer
//     // cout << last_digit;// in case we have to use lasrge integers that cna not be on the range of long or int data type

//     return 0;
// }
#include <iostream>
#include <string>
// #include<bits/stdc++>
using namespace std;

int main() {
	// Complete the program
    string s1,s2;
    cin >> s1 >> s2;
    cout <<  s1.size() << endl << s2.size() << endl ;
    cout << s1 + s2 << endl;
    char temp= s1[0];
    s1[0] = s2[0];
    s2[0] = temp;
    cout << s1 << " " << s2;  
    return 0;
}