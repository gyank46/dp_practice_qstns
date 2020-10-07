#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    unsigned int n;
	    cin>>n;
	    int ans=0,count=0;
	    while(n!=0)
	    {
	        cout<<n<<endl;
	        ans+=(n/pow(2,32))*(pow(2,32-count));
	        count++;
	        n=n<<1;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
