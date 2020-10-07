#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    int n;
    std::cin >>n;
    std::vector<int> v(n);
    int sum=0;
    for (int i = 0; i < n; i++)
    {
      std::cin >> v[i];
      sum+=v[i];
    }
    if(sum%2!=0)
      cout<<-1<<endl;
    else
    {
      sum/=2;
      vector<vector<int> >res(sum+1,vector<int>(n));
      for(int i=0;i<n;i++)
        res[0][i]=1;
      for(int i=1;i<=sum;i++)
      {
        for(int j=n-1;j>=0;j--)
        {
          int x;
          x=j+1<n?res[i][j+1]:0;
          int y;
          if(i-v[j]==0&&j==n-1)
            y=1;
          else
            y=(i-v[j]>=0&&j+1<n)?res[i-v[j]][j+1]:0;
          res[i][j]=x||y;
        }
      }
      for(int i=0;i<=sum;i++)
      {
        for(int j=0;j<n;j++)
          cout<<res[i][j]<<" ";
        cout<<endl;
      }
      cout<<res[sum][0]<<endl;
    }
}
