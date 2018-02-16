#include <bits/stdc++.h>
using namespace std;
int n;
int dp[2001][2001];
int arr[2005];
int trt_for_cows(int st,int end,int age)
{ 
	if(st>end){	return 0;}
    if(dp[st][end]!=-1)
		return dp[st][end];
	return dp[st][end]=max(trt_for_cows(st+1,end,age+1)+arr[st]*age,trt_for_cows(st,end-1,age+1)+arr[end]*age);
}
main()
{
	cin>>n;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<trt_for_cows(0,n-1,1)<<endl;
}