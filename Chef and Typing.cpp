/*PROBLEM STATEMENT
Chef is practising his typing skills since his current typing speed is very low. He uses a training application that displays some words one by one for Chef to type.

When typing a word, Chef takes 0.2 seconds to type the first character; for each other character of this word, he takes 0.2 seconds to type this character if it is written with a different hand than the previous character, or 0.4 seconds if it is written with the same hand. The time taken to type a word is the sum of times taken to type all of its characters. However, if a word has already appeared during practice, Chef can type it in half the time it took him to type this word for the first time.

Currently, Chef is practising in easy mode, which only uses words that consists of characters 'd', 'f', 'j' and 'k'. The characters 'd' and 'f' are written using the left hand, while the characters 'j' and 'k' are written using the right hand.

Given the words that appeared during Chef's practice, calculate the total time taken by Chef to type all the words.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of words Chef had to type.
Each of the following N lines contains a single string — a word Chef has to type.
Output
For each test case, print a single line containing one integer — the time taken by Chef to type all the words, in the units of tenths of seconds.

Constraints
1=T=100
1=N=100
each word contains only characters 'd', 'f', 'j', 'k'
the length of each word does not exceed 20
Subtasks
Subtask #1 (100 points): original constraints

Example Input
1
5
fdjkd
dfjdk
dfd
fdjkd
kkjjk


*/
# include<iostream>
# include<string.h>
using namespace std;

class typing
{
 public:
	char word[20];
	bool hand[20];
    void getdata()                //member function
	{
		cin>>word;
		int len;
		int flag = 0;
		len=strlen(word);
		for(int k = 0; k < len; k++)
		{
			if(word[k] == 'd' || word[k] == 'f' )
			{
				flag++;
				hand[k] = true;
			}
			if(word[k] == 'j' || word[k] == 'k')
			{
				flag++;
				hand[k] = false;
			}
		}
		if(flag != len)
		{
			exit;
		}
		
	}
};

int main()
{
	int T;
	int N;
	cin>>T;
		
	typing record[N];
	int count;
    count=0;
	
	if (T < 101 && T > 0 )
	{
		for(int i = 0; i < T; i++)
        {
		    cin>>N;
		    if(N < 101 && N > 0)
		    {
		        for(int j = 0; j < N; j++)
			    {
			   	    record[j].getdata();
			    }    
			}   
        }
	}	

    int time[N];
	int f_time = 0;
	int length;
	
	for(int a = 0; a < N; a++)
	{
	    time[a] = 2;	    
		length = strlen(record[a].word);
    	for(int k = 1; k < length; k++)
		{
	        if(record[a].hand[k] == record[a].hand[k-1])	
	        {
	        	time[a] = time[a] + 4;                        // if it is written with the same hand
		   }
		   else
		   {
				time[a] = time[a] + 2;                        //if it is written with the different hand
		   }
		}
		
	    for(int l = 0; l < a; l++)
    	{
		 	if(time[a] == time[l] )
		 	{
		 		int templen;
		 		templen = strlen(record[l].word);
		 		if(length == templen)
		 		{
		 			time[a] = 0.5*time[a];              // if a word has already appeared during practice
		 			break;
				 }
			 }
		}
		f_time = f_time + time[a];  
    }
	cout<<f_time;
	return 0;
}


