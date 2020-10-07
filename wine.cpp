#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<vector<int> > dp(n,vector<int>(n));
    for(int i=0;i<n;i++)
        dp[i][i]=a[i]*n;
    int i=0,k=1,j=k;
    while(!(i==0&&j==n))
    {
        while(j!=n)
        {
            // cout<<i<<" "<<j<<endl;
            dp[i][j]=max(a[i]*(n-j+i)+dp[i+1][j],a[j]*(n-j+i)+dp[i][j-1]);
            j++;
            i++;
        }
        k++;
        j=k;
        i=0;
    }
    cout<<dp[0][n-1]<<endl;
}
