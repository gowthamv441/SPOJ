#include <bits/stdc++.h>
using namespace std;
main()
{
	//getting number of vertices
	int n;
	cin>>n;
	//getting number of edges
	int e;
	cin>>e;
	vector< vector<int> > graph(n+1,vector<int> (n+1,0));
	//forming an un
	for(int i=0;i<e;i++)
	{
		int n1,n2,wt;
		cin>>n1>>n2>>wt;
		graph[n1][n2]=wt;
		graph[n2][n1]=wt; 
	}
	//dp table
	vector< vector<int> > dist(n+1,vector<int> (n+1,0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				dist[i][j]=0;			// same nodes
			else if(graph[i][j]==0)
				dist[i][j]=INT_MAX;		// undiscovered nodes
			else
				dist[i][j]=graph[i][j];	//directly connected nodes
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				// if both are Infinite then adding them will lead to negative number
				if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)   
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}

}