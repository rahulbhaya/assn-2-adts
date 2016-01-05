/*
 * File: WordLadder.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the word ladder problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include "genlib.h"
#include "simpio.h"
#include "lexicon.h"
#include "queue.h"
#include "vector.h"
#include "console.h"
#include <iostream>

Lexicon dict("EnglishWords.dat");
void wordladder(string,string);
string nextword(string,Lexicon,Lexicon);



int main()
{
	
	string start,end;
	while(1)
	{
		cout << "Enter first word (Enter To Exit):";
		start=GetLine();
		if (start == "") return 0;
		cout << "Enter end word(Enter to Exit) : ";
		end=GetLine();
		if (end == "") return 0;
		wordladder(start,end);
	}
	
	return 0;
}
void wordladder(string start,string end)
{
	if(!dict.containsWord(start))
	{
		cout<<"Error!Not an english word inputted or not found in dictionary";
		return;
	}
	Queue<Vector<string> > q;
	Lexicon onceused;
	string nextstr;
	Vector<string> toadd;
	toadd.add(start);
	q.enqueue(toadd);
	while(1)
	{
		if (q.size()==0)
		{
			cout << "\nladder not possible\n";
			break;
		}
		Vector<string> newstr = q.dequeue();
		while(1)
		{
			nextstr= nextword(newstr[newstr.size()-1],dict,onceused);
			if (nextstr == end) 
			{
				cout << "Ladder found\n";
				foreach(string list in newstr)
				{
					cout << list << " - ";
				}
				cout<<"\n";
				return;
			} 
			else if (nextstr != "")
			{
				Vector<string> more = newstr;
				more.add(nextstr);
				q.enqueue(more);
			}
	
			else if (nextstr =="")
				break;
			onceused.add(nextstr);
		}
	}
}
string nextword(string word, Lexicon dict, Lexicon onceused)
{
	string newword;
	char ch;
	int i;
	for (i =0;i<word.size();i++)
	{
		newword=word;
		for (ch='a';ch<='z';ch++)
		{
			newword = newword.replace(i,1,1,ch);
			if (dict.containsWord(newword))
				if (!onceused.containsWord(newword))
					return newword;
		}
	}
	return "";
}