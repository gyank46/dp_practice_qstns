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
    string s;
    cin>>s;
    int n=s.length();
    int prev=0;
    vector<int> a(n);
    a[0]=0;
    for(int i=1;i<n;i++)
    {
        if((s[i]=='.'&&s[i-1]=='.')||(s[i]=='#'&&s[i-1]=='#'))
        {
            a[i]=prev+1;
            prev+=1;
        }
        else
            a[i]=prev;
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<a[r-1]-a[l-1]<<endl;
    }
}
