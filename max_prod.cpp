#include <iostream>
using namespace std;

// Utility function to get the maximum of two and three integers
int max(int a, int b) { return (a > b)? a : b;}
int max(int a, int b, int c) { return max(a, max(b, c));}

int maxProd(int n)
{
   int val[n+1];
   val[0] = val[1] = 0;

   // Build the table val[] in bottom up manner and return
   // the last entry from the table
   for (int i = 1; i <= n; i++)
   {
      int max_val = 0;
      for (int j = 1; j <= i/2; j++)
      {
        int x=max(val[i-j],i-j);
        int y=max(val[j],j);
        max_val = max(max_val, x*y);
      }
      val[i] = max_val;
   }
   return val[n];
}
int main()
{
    cout << "Maximum Product is " << maxProd(19)<<endl;
    return 0;
}
