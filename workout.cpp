#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;


// Driver program
int main()
{
	int n,m;
	cin>>n>>m;
    vector<vector<int> > a(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    vector<vector<int> > btb(n,vector<int>(m));
    vector<vector<int> > bbt(n,vector<int>(m));
    vector<vector<int> > gbt(n,vector<int>(m));
    vector<vector<int> > gtb(n,vector<int>(m));
    btb[0][0]=a[0][0];
    bbt[n-1][m-1]=a[n-1][m-1];
    for(int i=1;i<m;i++)
        btb[0][i]=a[0][i]+btb[0][i-1];
    for(int i=1;i<n;i++)
        btb[i][0]=a[i][0]+btb[i-1][0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
            btb[i][j]=max(btb[i-1][j],btb[i][j-1])+a[i][j];
    }
    for(int j=m-2;j>=0;j--)
        bbt[n-1][j]=a[n-1][j]+bbt[n-1][j+1];
    for(int i=n-2;i>=0;i--)
        bbt[i][m-1]=a[i][m-1]+bbt[i+1][m-1];
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
            bbt[i][j]=max(bbt[i+1][j],bbt[i][j+1])+a[i][j];
    }
    gbt[n-1][0]=a[n-1][0];
    for(int j=1;j<m;j++)
        gbt[n-1][j]=gbt[n-1][j-1]+a[n-1][j];
    for(int i=n-2;i>=0;i--)
        gbt[i][0]=gbt[i+1][0]+a[i][0];
    for(int i=n-2;i>=0;i--)
    {
        for(int j=1;j<m;j++)
            gbt[i][j]=max(gbt[i+1][j],gbt[i][j-1])+a[i][j];
    }
    gtb[0][m-1]=a[0][m-1];
    for(int j=m-2;j>=0;j--)
        gtb[0][j]=gtb[0][j+1]+a[0][j];
    for(int i=1;i<n;i++)
        gtb[i][m-1]=gtb[i-1][m-1]+a[i][m-1];
    for(int i=1;i<n;i++)
        for(int j=m-2;j>=0;j--)
            gtb[i][j]=max(gtb[i-1][j],gtb[i][j+1])+a[i][j];
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //         cout<<btb[i][j]<<" ";
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //         cout<<bbt[i][j]<<" ";
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //         cout<<gbt[i][j]<<" ";
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //         cout<<gtb[i][j]<<" ";
    //     cout<<endl;
    // }
    int ans=INT_MIN;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            int a=btb[i-1][j];
            int b=bbt[i+1][j];
            int c=gbt[i][j-1];
            int d=gtb[i][j+1];
            int max1=a+b+c+d;
            int a1=btb[i][j-1];
            int b1=bbt[i][j+1];
            int c1=gbt[i+1][j];
            int d1=gtb[i-1][j];
            int max2=a1+b1+c1+d1;
            ans=max(ans,max(max1,max2));
        }
    }
    cout<<ans<<endl;
}
