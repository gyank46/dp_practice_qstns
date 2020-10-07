#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

struct box
{
  int he;
  int wi;
  int le;
};

bool myfunc(box &a,box &b)
{
  return (a.wi*a.le<b.wi*b.le);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int> l(n);
    vector<int> d(n);
    vector<int> w(n);
    for(int i=0;i<3*n;i++)
    {
      if(i%3==0)
        cin>>l[i/3];
      else if(i%3==1)
        cin>>d[i/3];
      else
        cin>>w[i/3];
    }
    vector<box> boxi(3*n);
    int j=0;
    for(int i=0;i<n;i++)
    {
      boxi[j].he=l[i];
      boxi[j].wi=min(d[i],w[i]);
      boxi[j].le=max(d[i],w[i]);
      j++;
      boxi[j].he=d[i];
      boxi[j].wi=min(l[i],w[i]);
      boxi[j].le=max(l[i],w[i]);
      j++;
      boxi[j].he=w[i];
      boxi[j].wi=min(d[i],l[i]);
      boxi[j].le=max(d[i],l[i]);
      j++;
    }
    sort(boxi.begin(),boxi.end(),myfunc);
    for(int i=0;i<3*n;i++)
    {
      cout<<boxi[i].he<<" "<<boxi[i].wi<<" "<<boxi[i].le<<endl;
    }
    vector<int> res(3*n);
    for(int i=0;i<3*n;i++)
      res[i]=boxi[i].he;
    res[3*n-1]=boxi[3*n-1].he;
    for(int i=3*n-2;i>=0;i--)
    {
      for(int j=i+1;j<3*n;j++)
        if(boxi[i].wi<boxi[j].wi&&boxi[i].le<boxi[j].le)
          res[i]=max(res[i],res[j]+boxi[i].he);
    }
    for(int i=0;i<3*n;i++)
      cout<<res[i]<<endl;
    cout<<*max_element(res.begin(),res.end())<<endl;
  }
}
