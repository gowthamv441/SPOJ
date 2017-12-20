#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
using namespace std;
struct cmp
{
	bool operator()(const pii &a,const pii &b)
	{
		return a.first>b.first;
	}
};
main()
{
	cout<<"Enter the no of nodes"<<endl;
	int n;
	cin>>n;
	cout<<"Enter the no of edges"<<endl;
	int e;
	cin>>e;
	vector<int> graphs[n+1];
	vector< vector<int> > cost(n+1,vector<int>(n+1,0));
	cout<<"Enter the connections (node1 node2 weight)"<<endl;
	for(int i=0;i<e;i++)
	{
		int n1,n2,wt;
		cin>>n1>>n2>>wt;
		cost[n1][n2]=wt;
		cost[n2][n1]=wt;
		graphs[n1].pb(n2);
		graphs[n2].pb(n1);
	}
	//Djikstra's algorithm starts here....
	priority_queue< pii, vector< pii >, cmp> pq;
	int start;
	cout<<"Enter the Source Node ..."<<endl;
	cin>>start;
	pq.push(mk(0,start));
	vector<int> dist(n+1);
	fill(dist.begin(),dist.end(),INT_MAX);
	dist[start]=0;
	while(!pq.empty())
	{
		int wt=pq.top().first;
		int node=pq.top().second;
		pq.pop();
		for(auto it:graphs[node])
		{
			if(dist[it]>dist[node]+cost[node][it])
			{
				dist[it]=dist[node]+cost[node][it];
				pq.push(mk(dist[it],it));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<endl;
	}
	return 0;
}