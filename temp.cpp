#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
#include <unordered_map>
using namespace std;
long long int del(vector<long long int>& nums)
{
    long long int n=nums.size();
    if(n==0)
        return 0;
    sort(nums.begin(),nums.end());
    unordered_map<long long int,long long int> m;
    for(long long int i=0;i<n;i++)
        m[nums[i]]++;
    vector<long long int> a;
    a.push_back(nums[0]);
    long long int prev=nums[0];
    for(long long int i=1;i<n;i++)
    {
        if(nums[i]!=prev)
        {
            a.push_back(nums[i]);
            prev=nums[i];
        }
    }
    long long int m1=a.size();
    vector<long long int> dp(m1);
    dp[0]=m[a[0]]*a[0];
    dp[1]=a[1]==a[0]+1?max(dp[0],m[a[1]]*a[1]):dp[0]+m[a[1]]*a[1];
    for(long long int i=2;i<m1;i++)
        dp[i]=a[i]==a[i-1]+1?max(dp[i-1],dp[i-2]+m[a[i]]*a[i]):dp[i-1]+m[a[i]]*a[i];
    return dp[m1-1];
}

int main()
{
    long long int n;
    cin>>n;
    vector<long long int> a(n);
    for(long long int i=0;i<n;i++)
        cin>>a[i];
    cout<<del(a)<<endl;
}
