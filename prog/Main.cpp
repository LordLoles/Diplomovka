#include "Main.h"
#include "Utils.h"
#include "Coloring.h"
#include "Path.h"
#include "NextPathGenerator.h"
#include "NextColoringGenerator.h"
#include "NonRepetitiveness.h"
#include "Utils.cpp"                // needed for visual studio code
#include "Coloring.cpp"             // needed for visual studio code
#include "Path.cpp"                 // needed for visual studio code
#include "NonRepetitiveness.cpp"    // needed for visual studio code
#include "NextPathGenerator.cpp"    // needed for visual studio code
#include "NextColoringGenerator.cpp"    // needed for visual studio code
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

    NextPathGenerator npg = NextPathGenerator(length, colors);

    Path nowPath = npg.nextPath();

    while (!(nowPath.empty()))
    {
        found = false;
        //cout << endl;
        //cout << "path with lists: ";
        nowPath.printPath();
        
        NextColoringGenerator ncg = NextColoringGenerator(length, nowPath);

        Coloring coloring = ncg.nextColoring();
        while (!(coloring.empty()))
        {
            //cout << "coloring: ";
            //coloring.printColoring();
            if (!checkNonRepetitiveness(coloring))
            {
                found = true;
            }
            coloring = ncg.nextColoring();
        }
        if (!found)
        {
            cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
        }
        nowPath = npg.nextPath();
    }
}
