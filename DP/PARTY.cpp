#include<bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int amount,n;
	cin>>amount>>n;
	while(amount||n)
	{
		vector<int> funs(n+1);
		vector<int> fees(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>fees[i]>>funs[i];
		}
		vector< vector< int > > dp(n+1,vector< int >(amount+1,0));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=amount;j++)
			{
				if(fees[i]>j)
				{
					dp[i][j]=dp[i-1][j];
				}
				else	
				{
					dp[i][j]=max(dp[i-1][j],funs[i]+dp[i-1][j-fees[i]]);
				}
			}
		}
		int cost=0;
		int maxfun=dp[n][amount];
		for(int i=0;i<=amount;i++)
		{
			if(dp[n][i]==maxfun)
				{
					cost=i;
					break;
				}
		}
		cout<<cost<<" "<<maxfun<<endl;
		cin>>amount>>n;
	}
	return 0;
}