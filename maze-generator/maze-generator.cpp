/**
 * File: maze-generator.cpp
 * ------------------
 * Last modified: jcain on 9/26/09.
 */

#include <iostream>
#include "set.h"
#include "vector.h"
#include "genlib.h"
#include "extgraph.h"
#include "simpio.h"
#include "random.h"
#include "maze-types.h"
#include "maze-graphics.h"

/**
 * Prompts the user so that he or she will supply an
 * integer in the range [minDimension, maxDimension].
 *
 * @param string prompt the text that should be printed to make it
 *        clear to the user that an integer should be entered.
 * @param int minDimension the lowest number the GetMazeDimension
 *        function will accept as in range.
 * @param int maxDimension the highest number the GetMazeDimension
 *        will accept as in range.
 * @return an integer in the range [minDimension, maxDimension].
 */

static int GetMazeDimension(string prompt, int minDimension = 7, int maxDimension = 50)
{
	while (true) {
		cout << prompt;
		int response = GetInteger();
		if (response == 0 ||response >= minDimension && response <= maxDimension) 
			return response;
		cout << "Please enter a number between "<< minDimension << " and " << maxDimension << ", inclusive." << endl;
	}
}

int main() 
{
	Vector<wall> theWalls;
	Vector<Vector<cell> >chambers;
	Randomize();
	InitMazeGraphics();
	while (true)
	{
		int dimension = GetMazeDimension("What should the dimension of your maze be [0 to exit]? ");
		if (dimension == 0) break;

		//makeChambers(chambers,dimension);
		cout << "Here's where we'll generate a maze before your very eyes." << endl;
	}

	return 0;
}
