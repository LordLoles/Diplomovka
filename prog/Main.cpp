#include "Main.h"
#include "Utils.h"
#include "Coloring.h"
#include "Path.h"
#include "PathGenerator.h"
#include "ColoringGenerator.h"
#include "NonRepetitiveness.h"
#include "Utils.cpp"                // needed for visual studio code
#include "Coloring.cpp"             // needed for visual studio code
#include "Path.cpp"                 // needed for visual studio code
#include "NonRepetitiveness.cpp"    // needed for visual studio code
#include "PathGenerator.cpp"    // needed for visual studio code
#include "ColoringGenerator.cpp"    // needed for visual studio code
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;


const int length = 4;
const int colors = 4;


int main()
{
    bool found;

    PathGenerator pathGen = PathGenerator(length, colors);

    Path nowPath = pathGen.nextPath();

    while (!(nowPath.empty()))
    {
        found = false;
        //cout << endl;
        //cout << "path with lists: ";
        nowPath.printPath();
        
        ColoringGenerator coloringGen = ColoringGenerator(nowPath);

        Coloring coloring = coloringGen.nextColoring();

        while (!(coloring.empty()))
        {
            //cout << "coloring: ";
            coloring.printColoring();
            if (checkNonRepetitiveness(coloring)) //this coloring is non-repetitive
            {
                found = true;
                break;
            }
            coloring = coloringGen.nextColoring();
        }
        if (!found)
        {
            cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
        }
        nowPath = pathGen.nextPath();
    }
}
