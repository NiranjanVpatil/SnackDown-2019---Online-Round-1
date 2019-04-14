/* PROBLEM STATEMENT
The first line contain the number of test-cases T.

The first line of each test-case contains a single integer N.

Output
For each test case print a single line containing the string "HOSTED" if SnackDown was hosted in year N or "NOT HOSTED" otherwise (without quotes).

Constraints
1=T=10
2010=N=2019
Example Input
2
2019
2018
Example Output
HOSTED
NOT HOSTED

*/
# include<iostream>
# include<string.h>
using namespace std;

int main()
{
	int T;
	int N[T];
	cin>>T;
	if(T > 0 && T <11)
	{
		for(int i = 0; i < T; i++)
		{
			cin>>N[i];
		}
		for(int j = 0; j < T; j++)
		{
			if(N[j] > 2009 && N[j] < 2020)
			{   
			   if(N[j] == 2010 || N[j] == 2015 || N[j] == 2016 || N[j] == 2017 || N[j] == 2019)
			   {
			   	  cout<<"HOSTED"<<endl;
			   	  
			   }
			   else
			   {
			   	cout<<"NOT HOSTED"<<endl;
			   }
			}
		}
	}
	return 0;
}


