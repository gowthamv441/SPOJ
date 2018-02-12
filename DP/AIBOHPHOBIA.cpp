#include<bits/stdc++.h>
using namespace std;
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		string rev="";
		for(int i=s.length()-1;i>=0;i--)
			rev+=s[i];
		int n=s.length();
		vector< vector<int> > dp(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s[i-1]==rev[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
			}
		}		
		cout<<n-dp[n][n]<<endl;
	}
}