#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b)
{
   int maxMultiple = max(a, b);
   while (true)
   {
      if (maxMultiple % a == 0 && maxMultiple % b == 0)
      {
         return maxMultiple;
      }
      maxMultiple++;
   }
}
int main()
{
   int a, b, c;
   cin >> a >> b >> c;
   int step;
   int cth;
   for (int i = 2; c > 0 ;i++)
   {
      if ( i % a == 0 || i % b == 0)
      {
         c = c - 1;
         cth =i;
      }
   }
   // i--;
   // cout << c << endl << cth << endl;
   if (cth % a == 0 && cth % b == 0)
      step = lcm(a, b);
   else if (cth % a == 0)
      step = a;
   else if (cth % b == 0)
      step = b;
   // cout << step << endl;
   while (cth >= 0 )
   {
      cout << cth << " ";
      cth -= step;
   }
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//    int a, b, c;
//    cin >> a >> b >> c;
//    for (int i = 0; c >= 0; i++)
//    {
//       if (i % a == 0 || i % b == 0)
//          c--;
//    }

//    return 0;
// }