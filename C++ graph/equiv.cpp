// CSCI 3300
// Assignment: 7A
// Author:     Evan Walsh
// File:       equiv,cpp
// Tab stops:  8

/* **,**
*/

#include <cstdio>
#include "equiv.h"
//===========================================
//		leader
//===========================================
//leader returns the finalboos of the input vertice
//===========================================
int leader(Equiv& e, int k)
{
	int r = k;
	while(e.boss[r] != 0) 
	{
		r = e.boss[r];
	}
	return r;
}
//===========================================
//		together
//===========================================
//together checks if the two input vertices are
//under the same boss and returns true if they are.
//===========================================
bool together(Equiv& e, int x, int y)
{
	if(leader(e, x) == leader(e, y))
		{
		return true;
		}
	else
		{
		return false;
		}
}
//===========================================
//		combine
//===========================================
//combine sets the two input values equal to the same
//boss.
//==========================================
void combine(Equiv& e, int x, int y)
{
	if (!together(e, x, y))
	{
		int temp1 = leader(e, x);
		int temp2 = leader(e, y);
		e.boss[temp1] = temp2;
	}

}
//===========================================
//		print
//===========================================
//print prints the index of each value and the corresponding
//leader.
//===========================================
void printBoss(Equiv& e)
{
	for(int i = 1; i <= e.SizeofArray; i++)
	{
		printf("index:%i " , i);
		printf("leader: %i\n", e.boss[i]);
	}
	printf("\n");
}
