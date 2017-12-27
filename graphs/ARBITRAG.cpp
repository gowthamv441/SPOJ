#include <bits/stdc++.h>
#define pii pair<int,int>
#define mk make_pair
#define	pb push_back
#define MAX 100000
using namespace std;
main()
{
	int n;
	cin>>n;
	int index=1;
	while(n)
	{
		string str="";
		map<string,int> mp;
		for(int i=1;i<=n;i++)
		{
			cin>>str;
			mp.insert(mk(str,i));
		}
		vector< vector<double> > graph(n+1,vector<double>(n+1,0));
		int e;
		cin>>e;
		for(int i=0;i<e;i++)
		{
			string source,dest;
			double wt;
			cin>>source>>wt>>dest;
			graph[mp[source]][mp[dest]]=wt;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					graph[i][j]=max(graph[i][j],graph[i][k]*graph[k][j]);
				}
			}
		}
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			if(graph[i][i]>1.0)
			{
				flag=true;
				break;
			}
		}
		if(flag)
			cout<<"Case "<<index<<": Yes"<<endl;
		else
			cout<<"Case "<<index<<": No"<<endl;
		index++;
		cin>>n;
	}
}