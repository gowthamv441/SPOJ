/*

There is a SmileyLand of angels. The queen of all angels Smiley1807 loves the number 1807. She is so much obsessed with 1807 that she asked her programmer friend to write a program to find the length of the largest sub sequence having digits 1,8,0 and 7 in order. For example if given sequence is 1800777700088888000777 then one of the largest sub sequence satisfying the above condition is 1800000000777 (there is one more possibility of 1888888000777)and hence the length of largest sub sequence is 13.
Input

The input contains only one test case.

The test case consist of only one sequence which may be as long as 10^6. There are only 1,8,0 or 7 present in the input sequence.
Output

Output contains only one line containing the length of the largest sub-sequence.
Example

Input:
1800777700088888000777

Output:
13

Explanation
1800000000777 is the largest sub-sequence

*/


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
