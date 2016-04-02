/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	struct node *trav1 = date1head;
	struct node *trav2 = date2head;
	int count = 1,yrnum1=0,yrnum2=0,mnnum1=0,mnnum2=0,dynum1=0,dynum2=0;
	int mul = 1;
	while (trav1!= NULL&&trav2!=NULL)
	{
		trav1 = trav1->next;
		trav2 = trav2->next;
			count++;
			if (count == 5)
			{
				while (trav1 != NULL)
				{
					yrnum1 = yrnum1*mul + trav1->data;
					mul = mul * 10;
					trav1 = trav1->next;
				}
			}
			mul = 1;
			if (count == 5)
			{
				while (trav2 != NULL)
				{
					yrnum2 = yrnum2*mul + trav2->data;
					mul = mul * 10;
					trav2 = trav2->next;
				}
			}
	}
	if (yrnum1 == yrnum2)
	{
		trav1 = date1head;
		trav2 = date2head;
		int count = 1, mul = 1;
		while (trav1 != NULL&&trav2 != NULL)
		{
			trav1 = trav1->next;
			trav2 = trav2->next;
			count++;
			if (count == 3)
			{
				int dp = count;
				while (trav1 != NULL)
				{
					if (dp < 5)
					{
						mnnum1 = mnnum1*mul + trav1->data;
						mul = mul * 10;
						trav1 = trav1->next;
						dp++;
					}
					else
						break;
				}
			}
			mul = 1;
			if (count == 3)
			{
				int dp = count;
				while (trav2 != NULL)
				{
					if (dp < 5)
					{
						mnnum2 = mnnum2*mul + trav2->data;
						mul = mul * 10;
						trav2 = trav2->next;
						dp++;
					}
					else
						break;
				}
			}
		}
		if (mnnum1 == mnnum2)
		{
			trav1 = date1head;
			trav2 = date2head;
			dynum1 = trav1->data * 10 + trav2->data;
			dynum1 = trav1->data * 10 + trav2->data;
			return abs(dynum1 - dynum2-1);
		}
		}
	return -1;
}