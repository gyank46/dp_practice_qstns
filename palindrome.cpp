#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int pal(string s)
{
  int n=s.length();
  if(n==0||n==1)
    return 0;
  if(s[0]!=s[n-1])
  {
    string x="";
    for(int i=1;i<n;i++)
      x+=s[i];
    string y="";
    for(int i=0;i<n-1;i++)
      y+=s[i];
    return min(pal(x),pal(y))+1;
  }
  else
  {
    string z="";
    for(int i=1;i<n-1;i++)
      z+=s[i];
    return pal(z);
  }
}

int dp(string s)
{
  int n=s.length();
  vector<vector<int> >res(n,vector<int>(n));
  for(int i=0;i<n;i++)
    res[i][i]=0;
  int start=0,end=n-1,row=1;
  int k=1;
  //cout<<res[row][start]<<" ";
  while(k<=n-1)
  {
    for(int i=start;i<end;i++)
    {

      if(s[row]!=s[i])
        res[row][i]=min(res[row-1][i],res[row][i+1])+1;
      else
        res[row][i]=res[row-1][i+1];

      row++;
    }
    end--;
    row=n-end;
    k++;
  }
  return res[n-1][0];
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    cout<<dp(s)<<endl;
  }
}
