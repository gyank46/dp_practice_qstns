#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>


using namespace std;


int maxsumsubmat(vector<vector<int> >&a)
{
    int n=a.size();
    int m=a[0].size();
    vector<int> kad(n);
    int currsum=0,maxsum=INT_MIN,maxleft=0,maxright=0,maxup=0,maxdown=0;
    for(int k=0;k<m;k++)
    {
        for(int j=k;j<m;j++)
        {
            for(int i=0;i<n;i++)
                kad[i]+=a[i][j];
            int csum=0,msum=INT_MIN,up=0,down=0,local_start=0;
            for(int i=0;i<n;i++)
            {
                if(msum<csum+kad[i])
                {
                    msum=csum+kad[i];
                    up=local_start;
                    down=i;
                }
                csum+=kad[i];
                if(csum<0)
                {
                    csum=0;
                    local_start=i+1;
                    // down=i;
                }
            }
            // cout<<up<<" "<<down<<endl;
            if(msum>maxsum)
            {
                maxsum=msum;
                maxleft=k;
                maxright=j;
                maxup=up;
                maxdown=down;
            }
        }
        for(int i=0;i<n;i++)
            kad[i]=0;
    }
    cout<<maxleft<<","<<maxup<<" "<<maxdown<<","<<maxright<<endl;
    return maxsum;
}

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
    cout<<maxsumsubmat(a)<<endl;
}
