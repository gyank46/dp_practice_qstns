#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
#include <unordered_map>
#define ll long long
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll ans=1;
    ll maxi=0;
    ll prev=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>=prev)
            ans++;
        else
        {
            maxi=max(maxi,ans);
            ans=1;
        }
        prev=a[i];
    }
    maxi=max(maxi,ans);
    cout<<maxi<<endl;

}
