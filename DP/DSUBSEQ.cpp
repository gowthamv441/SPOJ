#include <bits/stdc++.h>
#define ll long long 
using namespace std;
main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string str="";
		cin>>str;
		ll n=str.length();
		vector<ll> last(500,0);
		vector<ll> dp(n+1,0);
		dp[0]=1;
		for(ll i=1;i<=n;i++)
		{
			dp[i]=(2*dp[i-1])%1000000007;
			if(last[str[i-1]]!=0)
				dp[i]=abs(dp[i]-dp[last[str[i-1]]-1]+1000000007)%1000000007;
			last[str[i-1]]=i;
		}
		cout<<(dp[n])%1000000007<<endl;

	}
}