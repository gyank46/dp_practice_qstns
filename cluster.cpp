#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

#define maxi 100000000

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++)
      cin>>a[i];
    int k;
    cin>>k;
    int res[n+1][k+1];
    for(int i=0;i<n;i++)
    {
      res[i][1]=(a[i]-a[n-1])*(a[i]-a[n-1]);
    }
    for(int j=2;j<=k;j++)
    {
      for(int i=n-1;i>=0;i--)
      {
        int mini=maxi;
        for(int l=i+1;l<n;l++)
        {
          mini=min(mini,res[l][j-1]+(a[i]-a[l-1])*(a[i]-a[l-1]));
        }
        res[i][j]=mini;
        //cout<<i<<" "<<j<<" "<<res[i][j]<<endl;
      }
    }
    cout<<res[0][k]<<endl;

  }
}
