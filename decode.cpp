#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>


using namespace std;
string decodeAtIndex(string s, int k)
{
    int n=s.length();
    if(n==0)
        return "";
    string res;
    string ans;
    for(int i=0;i<n;i++)
    {
        // cout<<res<<endl;
        if(!(s[i]>='2'&&s[i]<='9'))
        {
            if(res.length()>=k)
                break;
            res+=s[i];
        }
        else
        {
            int t=s[i]-'0';
            int len=res.length();
            if(len+(t-1)*len>=k)
            {
                // cout<<res<<endl;
                int stepoff=(k-len)%len;
                if(stepoff==0)
                    stepoff=len;
                ans+=res[stepoff-1];
                return ans;
            }
            else
            {
                string temp=res;
                for(int j=1;j<=t-1;j++)
                    res.append(temp);
            }
        }

    }
    ans+=res[k-1];
    return ans;
}
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<decodeAtIndex(s,k)<<endl;
}
