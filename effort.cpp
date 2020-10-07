#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> le(n);
        vector<int> he(n);
        for(int i=0;i<n;i++)
            cin>>he[i];
        for(int i=0;i<n;i++)
            cin>>le[i];
        vector<int> rh(n);
        vector<int> lh(n);
        lh[0]=le[0];
        rh[0]=he[0];
        rh[1]=he[1];
        lh[1]=le[1]+max(lh[0],rh[0]);
        for(int i=2;i<n;i++)
        {
            rh[i]=max(lh[i-2]+he[i],he[i]+rh[i-2]);
            lh[i]=le[i]+max(lh[i-1],rh[i-1]);
        }
        for(int i=0;i<n;i++)
            cout<<rh[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<lh[i]<<" ";
        cout<<endl;
        cout<<max(rh[n-1],lh[n-1])<<endl;

    }
}
