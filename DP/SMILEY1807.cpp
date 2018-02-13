#include<bits/stdc++.h>
using namespace std;
main()
{
	string s;
	cin>>s;
	vector<int> seq(4,0);
	bool flag=0;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			seq[0]=seq[0]+1;
			flag=1;
		}
		else if(s[i]=='8'&&flag)
		{
			seq[1]=max(seq[1]+1,seq[0]+1);
		}
		else if(s[i]=='0'&&flag)
		{
			seq[2]=max(seq[2]+1,seq[1]+1);
		}
		else if(s[i]=='7'&&flag)
		{
			seq[3]=max(seq[3]+1,seq[2]+1);
		}
	}
	cout<<seq[3]<<endl;
}