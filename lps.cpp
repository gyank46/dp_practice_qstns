#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        vector<vector<int> >res(n,vector<int>(n));
        for(int i=0;i<n;i++)
            res[i][i]=1;
        int i=0,j,k=1;
        while(!(i==0&&k==n))
        {
            j=k;
            while(j<n)
            {
                if(s[i]==s[j])
                    res[i][j]=res[i+1][j-1]+2;
                else
                    res[i][j]=max(res[i+1][j],res[i][j-1]);
                i++;
                j++;
            }
            i=0;
            k++;
        }
        for(int i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                cout<<res[i][j]<<" ";
            cout<<endl;
        }
        cout<<res[0][n-1]<<endl;
    }
}
