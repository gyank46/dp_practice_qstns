#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<vector<int> > dp(2,vector<int>(n));
    for(int i=0;i<n;i++)
        dp[0][i]=a[i];
    vector<int> ans;
    ans.push_back(*max_element(a.begin(),a.end()));
    int maxi=INT_MIN;
    int i=0,k=1,j=1;
    while(!(i==0&&j==n))
    {
        maxi=INT_MIN;
        while(j!=n)
        {
            dp[1][j]=a[j]<dp[0][j-1]?a[j]:dp[0][j-1];
            maxi=max(maxi,dp[1][j]);
            i++;
            j++;
        }
        i=0;
        k+=1;
        j=k;
        dp[0]=dp[1];
        for(int i=0;i<n;i++)
            dp[1][i]=0;
        ans.push_back(maxi);
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
