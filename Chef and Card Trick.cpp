/*PROBLEM STATEMENT
Chef is recently learning magic tricks that use a deck of cards. Each card in this deck has an integer written on it. Currently, he is learning how to make the deck sorted in non-decreasing order (from top to bottom) of the numbers on the cards using at most one shuffle move.

A shuffle move means taking an arbitrary number of cards from the top of the deck and putting them at the bottom of the deck in the same relative order.

For example, if we have a deck of cards with numbers (5,7,3,3,8,2), it is allowed to take the top three cards (5,7,3) and put them at the bottom; the result is (3,8,2,5,7,3).

You are trying to convince Chef that sometimes, it is impossible to sort the deck in non-decreasing order using at most one shuffle move. That is why you need to write a program that determines if it is possible to sort a given deck or not.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN denoting the cards in the deck from top to bottom.
Output
For each test case, print a single line containing the string "YES" if it is possible to sort the deck or "NO" if it is impossible.

Constraints
1=T=100
2=N=105
the sum of N over all test cases does not exceed 106
1=Ai=109 for each valid i
Subtasks
Subtask #1 (50 points):

2=N=1,000
the sum of N over all test cases does not exceed 10,000
Subtask #2 (50 points): original constraints

Example Input
2
5
1 5 2 4 3
5
3 4 5 1 2
Example Output
NO
YES
*/
# include<iostream>
using namespace std;

/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
}*last;
 
/*
 * Class Declaration
 */
class circular_llist
{
    public:
        void create_node(int value);
        void display_list();
        bool checkorder(int N);
        int move();
        circular_llist()
        {
            last = NULL;           
        }
};

/*
 * Create Circular Link List
 */
void circular_llist::create_node(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;   
    }
    else
    {
        temp->next = last->next; 
        last->next = temp;
        last = temp;
    }
}
 
/*
 * Display Circular Link List 
 */
void circular_llist::display_list()
{
    struct node *s;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = last->next;
    cout<<"Circular Link List: "<<endl;
    while (s != last)
    {
        cout<<s->info<<"->";
        s = s->next;
    }
    cout<<s->info<<endl;
}

int circular_llist::move()
{
	struct node *s;
	int temp;
	s = last->next;

    while (s != last)
    {
        temp = s->info;
        s->info = s->next->info;
        s->next->info = temp;
        s = s->next;
    }
}
bool circular_llist::checkorder(int N)
{
	struct node *s;
	int temp;
	s = last->next;
	int c = 0;
	    while (s != last)
	    {
	    	if(s->info < s->next->info)
	    {
	    	c++;
		}
		s = s->next;
		}
		
	
	if(c == (N-1))
	{
		cout<<"YES"<<endl;
		return true;
		
	}
	
}
int main()
{
	int T;
	int N;

	cin>>T;
	cin>>N;
	
	int element;
	circular_llist cl,c2,c3;
	int p;
	p = 1;
	
	if (T < 101 && T > 0 )
	{
		for(int i = 0; i < T; i++)
		{
			for(int i = 0; i < N; i++)
	        {
                cin>>element;
                cl.create_node(element);
            }         
	        for(int j = 0; j < N-1; j++)
	        {
	            c2.move();
	            bool r;
	            r = c3.checkorder(N);
	            if(r == true)
	            {
	            	break;
	            	p = 0;
				}
	            cl.display_list();
			}
			if(p == 1)
			{
				cout<<"No"<<endl;
			}
			p = 1;
			
		}
    }
	
	
	
	return 0;
}


