// Dijkstra using the priority queue and the adjcency list
#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
#define ll long long 
using namespace std;
struct cmp
{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)
    {
        return a.first>b.first;
    }   
};
main()
{
    ios::sync_with_stdio(false);
    int t; // testcase
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; // no of cities
        string s;
        vector<int> graph[n+1]; //adjcency list 
       	int cost[n+1][n+1];
        map<string,int> mp;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            mp[s]=i;
            int k,neighbour,c;
            cin>>k;                   // getting no of neighbours
            for(int j=0;j<k;j++)
            {
                cin>>neighbour>>c;    // getting the neighbour and cost to reach the neighbour
                graph[i].pb(neighbour);
                cost[i][neighbour]=c;
            }
        }
        int Query;
        cin>>Query;   
        while(Query--)
        {
            priority_queue<pii , vector< pii >, cmp > pq;
            ll dist[n+1];                   // store the maximum distance to node from the start index
            fill(dist,dist+(n+1),INT_MAX);
            string source , dest;
            cin>>source>>dest;
            int st=mp[source],dt=mp[dest];
            dist[st]=0;
            pq.push(mk(0,st));                        //push the start node into pq
            while(!pq.empty())
            {
                int wt=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                if(node==dt)                    // if the node we're reading is the dest node print output
                {
                    cout<<wt<<endl;
                    break;
                }
                for(auto it:graph[node])          //check for each neighbours of the node
                {
                    if(dist[it]>dist[node]+cost[node][it])          //if we get minimum cost to reach the neighbour  
                    {                                               //via curr node update it & push to pq else ignore
                        dist[it]=dist[node]+cost[node][it];
                        pq.push(mk(dist[it],it));
                    }
                }
            }
        }
    }
    return 0;
}
