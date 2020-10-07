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
    int n;
    cin>>n;
    vector<vector<int> > a(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
    vector<vector<int> > res(n,vector<int>(n));
    res[0][0]=a[0][0];
    for(int i=1;i<n;i++)
    {
      res[0][i]=res[0][i-1]+(pow(2,i)*a[0][i]);
    }
    for(int i=1;i<n;i++)
    {
      res[i][0]=res[i-1][0]+(pow(2,i)*a[i][0]);
    }
    for(int i=1;i<n;i++)
    {
      for(int j=1;j<n;j++)
      {
        res[i][j]=max(res[i-1][j],res[i][j-1])+(pow(2,i+j)*a[i][j]);
      }
    }
    cout<<res[n-1][n-1]<<endl;
  }
}
