#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n,sum;
    cin>>m>>n>>sum;
    long res[sum+1][n+1];
    for(int i=0;i<=sum;i++)
    {
      for(int j=0;j<=n;j++)
        res[i][j]=0;
    }
    for(int i=1;i<=m&&i<=sum;i++)
    {
        res[i][1]=1;
    }
    // for(int i=0;i<=sum;i++)
    // {
    //   for(int j=0;j<=n;j++)
    //     cout<<res[i][j]<<" ";
    //   cout<<endl;
    // }
    for(int j=2;j<=n;j++)
    {
      for(int i=1;i<=sum;i++)
      {
        for(int l=1;l<=m&&i>l;l++)
        {
            res[i][j]+=res[i-l][j-1];
        }
      }
    }
    cout<<res[sum][n]<<endl;
  }
}
