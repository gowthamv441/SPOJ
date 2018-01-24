#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
using namespace std;
struct cmp
{
	bool operator()(const pii &a,const pii &b)
	{
		return a.first>b.first;
	}
};
int djikstra(vector< pii > graph[],int start,int dest,int n)
{
	priority_queue < pii, vector< pii >, cmp> pq;
	vector<int> dist(n+1,INT_MAX);
	pq.push(mk(0,start));
	dist[start]=0;
	while(!pq.empty())
	{
		int wt=pq.top().first;
		int node=pq.top().second;
		pq.pop();
		if(node==dest)
		{
			return wt;
		}
		for(int i=0;i<graph[node].size();i++)
		{
			pii it=graph[node][i];
			if(dist[it.first]>dist[node]+it.second)
			{
				dist[it.first]=dist[node]+it.second;
				pq.push(mk(dist[it.first],it.first));
			}
		}
	}
	return dist[dest];
}
main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector< pii > graph[n+1];
	int exit1;
	cin>>exit1;
	int timelimit;
	cin>>timelimit;
	int e;
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int st,dt,wt;
		cin>>st>>dt>>wt;
		graph[st].pb(mk(dt,wt));
	}
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(djikstra(graph,i,exit1,n)<=timelimit)
			count++;
	}
	cout<<count<<endl;
}