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
        vector<int> a(n);
        vector<int> in(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>in[i];
        int j;
        for(int i=0;i<n;i++)
        {
            j=i;
            // cout<<a[in[j]]<<" "<<in[j]<<a[j]<<endl;
            while(in[j]!=i)
            {
                int temp=a[in[j]];
                a[in[j]]=a[i];
                a[i]=temp;
                int temp1=in[in[j]];
                in[in[j]]=in[j];
                in[j]=temp1;
            }
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<in[i]<<" ";
        cout<<endl;
    }
}
