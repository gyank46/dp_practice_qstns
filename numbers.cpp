#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;
int main()
{
    vector<int> ans(1001);
    int count=0;
    for(int i=1;i<=1000;i++)
    {
        int a=(i%10==1||i%10==2||i%10==3||i%10==4||i%10==5);
        if(i<10)
        {
            if(a)
            {
                count++;
                ans[i]=count;
            }
            else
                ans[i]=ans[i-1];
        }
        int j=i/10;
        int b=(j%10==1||j%10==2||j%10==3||j%10==4||j%10==5);
        if(i>=10&&i<100)
        {
            if(a&&b)
            {
                count++;
                ans[i]=count;
            }
            else
                ans[i]=ans[i-1];
        }
        j=j/10;
        int c=(j%10==1||j%10==2||j%10==3||j%10==4||j%10==5);
        if(i>=100&&i<1000)
        {
            if(a&&b&&c)
            {
                count++;
                ans[i]=count;
            }
            else
                ans[i]=ans[i-1];
        }

    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1000)
            ans[n]=ans[n-1];
        cout<<ans[n]<<endl;
    }
}
