#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> fac;
    for(int i=2;i<=sqrt(n);i++)
    {
        fac.push_back(i);
        if(i!=n/i)
            fac.push_back(n/i);
    }
    cout<<fac.size()<<endl;

}
