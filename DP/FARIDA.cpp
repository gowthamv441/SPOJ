/*


Once upon time there was a cute princess called Farida living in a castle with her father, mother and uncle. On the way to the castle there 
lived many monsters. Each one of them had some gold coins. Although they are monsters they will not hurt. Instead they will give you the gold
coins, but if and only if you didn't take any coins from the monster directly before the current one. To marry princess Farida you have to 
pass all the monsters and collect as many coins as possible. Given the number of gold coins each monster has, calculate the maximum number of
coins you can collect on your way to the castle.

Input

The first line of input contains the number of test cases. Each test case starts with a number N, the number of monsters, 0 <= N <= 10^4. The 
next line will have N numbers, number of coins each monster has, 0 <= The number of coins with each monster <= 10^9. Monsters described in 
the order they are encountered on the way to the castle.

Output

For each test case print “Case C: X” without quotes. C is the case number, starting with 1. X is the maximum number of coins you can collect.

Example

Input:
2
5
1 2 3 4 5
1
10

Output:
Case 1: 9
Case 2: 10


*/



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
