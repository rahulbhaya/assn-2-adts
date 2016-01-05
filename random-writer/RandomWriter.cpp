/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the random writer problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "vector.h"
#include "map.h"
#include <iostream>
#include <fstream>

int main()
{
	string filename="";
	int order;
	Map<Vector<char>> keys;
	ifstream inpfile;
	while(true)
	{
		cout<<"Please enter filename to open:";
		filename=GetLine();
	}
	while(true)
	{
		cout<<"What order of analysis?(a number between 1-10:";
		order=GetInteger();
		if(order>=1 && order <=10) break;
	}
	cout << "Analysis.... please wait " << endl;
	//setupkeys(keys,inpfile,seed);
	inpfile.close();
	//string maxkey=obtainAMaxKey(keys);
	//cout<<maxK
	//outputMarkov(thekeys,maxkey);
	
	cout << "FINISHED"<< endl;
	return 0;
}
