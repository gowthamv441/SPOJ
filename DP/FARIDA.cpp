#include <bits/stdc++.h>
#define ll long long
using namespace std;
main()
{
	ll t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ll n;
		cin>>n;
		if(n>=1)
		{
			vector<ll> dp(n);
			for(ll i=0;i<n;i++)
				cin>>dp[i];	
			if(n>1)
			{
				dp[1]=max(dp[0],dp[1]);
				for(ll i=2;i<n;i++)
				{
					dp[i]=max(dp[i-1],dp[i-2]+dp[i]);
				}
				cout<<"Case "<<k<<": "<<dp[n-1]<<endl;
			}
			else if(n==1)
			{
				cout<<"Case "<<k<<": "<<dp[0]<<endl;
			}
		}
		else
			cout<<"Case "<<k<<": "<<0<<endl;
	}
	return 0;
}
