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
        string s;
        cin>>s;
        int n=s.length();
        vector<vector<int> > res(n,vector<int>(n));
        for(int i=0;i<n;i++)
            res[i][i]=1;


    }

}
