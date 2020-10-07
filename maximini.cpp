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
    int n,sum;
    cin>>n>>sum;
    string mini,maxi;
    if(n==1&&sum==0)
    {
        cout<<"0"<<" "<<"0"<<endl;
    }
    else if(n*9<sum||sum==0)
    {
        mini="-1";
        maxi="-1";
        cout<<maxi<<" "<<mini<<endl;
    }
    else
    {
        int tsum=sum;
        mini+='1';
        for(int i=1;i<n;i++)
            mini+='0';
        maxi=mini;
        tsum-=1;
        for(int i=n-1;i>=0&&tsum>0;i--)
        {
            if(tsum>=9)
            {
                mini[i]='9';
                tsum-=9;
            }
            else
            {
                mini[i]=mini[i]+tsum;
                tsum=0;
            }
        }
        cout<<mini<<" ";
        tsum=1;
        for(int i=0;i<n&&tsum<sum;i++)
        {
            if(sum-tsum>=9)
            {
                maxi[i]='9';
                if(i==0)tsum+=8;
                else tsum+=9;
            }
            else
            {
                maxi[i]+=(sum-tsum);
                tsum=sum;
            }
        }
        cout<<maxi<<endl;
    }

}
