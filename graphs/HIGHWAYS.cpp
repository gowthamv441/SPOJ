#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
struct cmp
{
	bool operator()(const pii &a,const pii &b)
	{
		return a.first>b.first;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int cities,roads,start,dest;
		cin>>cities>>roads>>start>>dest;
		vector< pii > graph[cities+1]; 
		for(int i=0;i<roads;i++)
		{
			int city1,city2,time1;
			cin>>city1>>city2>>time1;
			graph[city1].pb(mk(city2,time1));
			graph[city2].pb(mk(city1,time1));
		}
		priority_queue< pii, vector< pii >, cmp> pq;
		vector<int> dist(cities+1,INT_MAX);
		pq.push(mk(0,start));
		dist[start]=0;
		while(!pq.empty())
		{
			int traveltime=pq.top().first;
			int city=pq.top().second;
			pq.pop();
			if(city==dest)
			{
				cout<<traveltime<<endl;
				break;
			}
			for(auto it:graph[city])
			{
				if(dist[it.first]>dist[city]+it.second)
				{
					dist[it.first]=dist[city]+it.second;
					pq.push(mk(dist[it.first],it.first));
				}
				
			}
		}
		if(dist[dest]==INT_MAX)
			cout<<"NONE"<<endl;
		
	}
	return 0;
}