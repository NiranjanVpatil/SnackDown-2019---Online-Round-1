/*
PRPBLEM STATEMENT
All submissions for this problem are available.Pari loves prime numbers, in her free time she likes to calculate the sum of all distinct prime factors of a given number. But her elder sister asked her to find the same on a given range and then add all the sums. Since Pari is busy these days, she asks for your help.

Input
First line will contain T, number of Test Cases.
Each Test case contains of a single line of input, two space separated integers l,r
Output
For each Test Case output in a single line, the answer% ( 109+7 ).

Constraints
1=T=10
1=l=r=106
Sample Input
  2
  2 6
  10 15
Sample Output
  17
  53
EXPLANATION
TestCase1:
Number DistinctPrimeFactors Sum
2              2                                           2
3              3                                           3
4              2                                           2
5              5                                           5
6              2,3                                         5
…………………………………………………………

Total Sum = 2+3+2+5+5 = 17
*/
# include<iostream>
# include<math.h>
using namespace std;      

int sumprimeFactors(int n) 
{ 
	int sum = 0;
	while (n%2 == 0) 
	{ 
		sum = sum + 2;
		n = n/2; 
		break;
	} 
	if(n%2 == 0)
	{
		n = n/2;
	}
	for (int i = 3; i <= sqrt(n); i = i+2) 
	{ 
		while (n%i == 0) 
		{ 
			sum = sum + i;
			n = n/i; 
		} 
	} 
	if (n > 2) 
	{
		sum = sum + n;
	}
	return sum;	
} 
int main()
{
	int T;
	long int l[T],r[T];
	cin>>T;
	int sum;
	
	if (T < 10 && T > 0 )
	{
			for(int i = 0; i < T; i++)
         	{
		        cin>>l[i]>>r[i];
		        
	        }
	}
	for(int k = 0; k < T; k++)
	{
		if( l[k] < 1000000 && l[k] > 0 && r[k] <1000000 && r[k] > 0 )
		        {
		        	sum = 0;
					for(int i = l[k]; i <= r[k]; i++)
		        	{
						sum = sum + sumprimeFactors(i);;	
					}
					cout<<sum<<endl;   	
				}	
	}	
	return 0;
}


