#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>


using namespace std;

// static int speed_up=[](){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     return 0;
// }();

string add(string a,string b)
{
    int carry=0;
    string res;
    int na=a.length(),nb=b.length();
    int i=na-1;
    int j=nb-1;
    while(i>=0||j>=0)
    {
        int ta,tb;
        ta=i>=0?a[i]-'0':0;
        tb=j>=0?b[j]-'0':0;
        res=(char)(((ta+tb+carry)%10)+'0')+res;
        carry=(ta+tb+carry)/10;
        i--;
        j--;
    }
    if(carry)
        res=(char)(carry+'0')+res;
    return res;
}
// string add

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        string t;
        cin>>s;
        int n=s.length();
        int i;
        for(i=0;i<n;i++)
        {
            if(s[i]!='0')
                break;
        }
        for(;i<n;i++)
            t+=s[i];
        if(t=="")
            cout<<"1"<<endl;
        else
        {
            string bmid;
            string amid;
            int n=t.length();
            for(int i=0;i<t.length()/2;i++)
                bmid+=t[i];
            if(n%2==0)
            {
                for(int i=t.length()/2;i<n;i++)
                    amid+=t[i];
            }
            else
                for(int i=t.length()/2+1;i<n;i++)
                    amid+=t[i];
            // cout<<amid<<" "<<bmid<<endl;
            // cout<<add(bmid,"1")<<endl;
            string temp;
            if(n%2)
                temp=bmid+t[t.length()/2];
            string rbmid=bmid;
            reverse(rbmid.begin(),rbmid.end());
            if(amid<rbmid)
            {
                // cout<<"here1"<<endl;
                if(n%2)
                    cout<<temp<<rbmid<<endl;
                else
                    cout<<bmid<<rbmid<<endl;

            }
            else
            {
                // cout<<"here2"<<endl;
                if(n%2==0)
                {
                    // cout<<"here3"<<endl;
                    int c9=0;
                    for(int i=0;i<bmid.length();i++)
                    {
                        if(bmid[i]=='9')
                            c9++;
                    }
                    if(c9==bmid.length())
                    {
                        // cout<<"here1"<<" "<<c9<<endl;
                        // string a1;
                        cout<<'1';
                        for(int i=0;i<=2*c9-2;i++)
                            cout<<'0';
                        cout<<'1'<<endl;
                        // a1[0]='1';
                        // a1[a1.length()-1]='1';
                        // cout<<a1<<endl;
                    }
                    else
                    {
                        string x=add(bmid,"1");
                        if(x.length()>bmid.length())
                        {
                            // cout<<"here4"<<endl;
                            string t1=x;
                            reverse(t1.begin(),t1.end());
                            t1.erase(0,1);
                            cout<<x<<t1<<endl;
                        }
                        else
                        {
                            // cout<<"here5"<<endl;
                            string t2=x;
                            reverse(t2.begin(),t2.end());
                            cout<<x<<t2<<endl;
                        }
                    }
                }
                else
                {
                    // cout<<"here6"<<endl;
                    if(n==1&&t!="9")
                        cout<<to_string(stoi(t)+1)<<endl;
                    else if(n==1&&t=="9")
                        cout<<"11"<<endl;
                    else
                    {
                        int c9=0;
                        for(int i=0;i<temp.length();i++)
                        {
                            if(temp[i]=='9')
                                c9++;
                        }
                        if(c9==temp.length())
                        {
                            // cout<<"here1"<<" "<<c9<<endl;
                            cout<<'1';
                            for(int i=0;i<2*c9-2;i++)
                                cout<<'0';
                            cout<<'1'<<endl;
                            // cout<<a1<<endl;
                        }
                        else
                        {
                            string x=add(temp,"1");
                            if(x.length()>temp.length())
                            {
                                // cout<<"here7"<<endl;
                                string t2=x;
                                reverse(t2.begin(),t2.end());
                                t2.erase(0,2);
                                cout<<x<<t2<<endl;
                            }
                            else
                            {
                                // cout<<"here8"<<endl;
                                string t2=x;
                                reverse(t2.begin(),t2.end());
                                t2.erase(0,1);
                                cout<<x<<t2<<endl;
                            }
                        }
                    }

                }
            }

        }
    }
}
