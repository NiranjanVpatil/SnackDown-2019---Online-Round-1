/*PROBLREM STATEMENT
Chef likes prime numbers. However, there is one thing he loves even more. Of course, it's semi-primes! A semi-prime number is an integer which can be expressed as a product of two distinct primes. For example, 15=3·5 is a semi-prime number, but 1, 9=3·3 and 5 are not.

Chef is wondering how to check if an integer can be expressed as a sum of two (not necessarily distinct) semi-primes. Help Chef with this tough task!

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.
Output
For each test case, print a single line containing the string "YES" if it is possible to express N as a sum of two semi-primes or "NO" otherwise.

Constraints
1=T=200
1=N=200
Example Input
3
30
45
62
Example Output
YES
YES
NO
Explanation
Example case 1: N=30 can be expressed as 15+15=(3·5)+(3·5).

Example case 2: 45 can be expressed as 35+10=(5·7)+(2·5).

Example case 3: 62 cannot be expressed as a sum of two semi-primes.

*/
# include<iostream>
using namespace std;

bool isprime(int x)
{
   for(int i = 2; i <= x/2 ;i++)
   { 
	  if( x%i == 0 )
      {  
	    return false;
      }
   }
  return true;
}

bool isSemiprime(int x)
{
    for(int i = 2 ; i <= x/2 ; i++ )
    {
           if( x%i == 0 ) 
            {
                if( isprime(i) && isprime(x/i) && (i!=(x/i)) )  
               {
                  return true;
               }
           }
    }
    return false;
}

bool isChefsemiprime(int N[],int T)
{
	int t[200] = {0};
	int pos;
	int sum = 0;
	int flag = 0;
	for(int i = 0; i < T; i++)
	{
	  int cnt=0 ;	
      for( int k = 3; k <= N[i]; k++ )
      {
         if( isSemiprime(k) ) 
         { 
            t[cnt] = k;
            cnt++;
            pos = cnt;
         }
       }
	
		for(int l = 0; l < pos; l++)
    	{
	    	for(int j = 0; j < pos; j++)
		   {
		    	sum = t[l] + t[j];
			    if(sum == N[i])
			    {
				   cout<<"YES"<<endl;
				   flag = 1;
				   break;
			    }
			    else
			    {
				  int sum = 0;
			    }
		   }
		   if(flag == 1)
		   {
		   	 break;
		   }	   
	    }
	    
	    if(flag == 0)
	    {
	    	cout<<"NO"<<endl;
		}
		
		flag = 0;	
	}
	
}

int main()
{
	int T;
	int n;
	int N[200];
	cin>>T;
	
	if (T < 201 && T > 0 )
	{
			for(int i = 0; i < T; i++)
         	{
		        cin>>n;
		        if( n < 201 && n > 0 )
		        {
		        	N[i] = n;
				}
	        }

	}	
	isChefsemiprime(N,T);         //Find N  as a sum of two semi-primes using calling isChefsemiprime
	return 0;
}

