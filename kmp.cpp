#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t,p;
    cin>>t>>p;
    int nt=t.length();
    int np=p.length();
    vector<int> aux(np,0);
    int len = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    int i,j;
    for(i=0;i<n;)
    {
        for(j=i;j<np;j++)
        {
            if(t[i]!=p[j])
                break;
        }

    }
}
