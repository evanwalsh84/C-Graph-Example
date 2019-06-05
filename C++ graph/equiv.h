// CSCI 3300
// Assignment: 7A
// Author:     Evan Walsh
// File:       equiv.h
// Tab stops:  8

/* **,**
*/

struct Equiv
{
	int* boss;
	int SizeofArray;
	
	Equiv ( int s )
	{
		SizeofArray = s;
		boss = new int[SizeofArray + 1];
		for(int i = 1; i < SizeofArray; i++)
		{
			boss[i]=0;
		}
	}
};

int leader (Equiv& e, int x, int y);

bool together(Equiv& e, int x, int y);

void combine(Equiv& e, int x, int y);

void printBoss(Equiv& e);
