#include "Main.h"
#include "./prog/Utils.h"
#include "./prog/Coloring.h"
#include "./prog/Path.h"
#include "./prog/PathGenerators/SimplePathGenerator.h"
#include "./prog/ColoringGenerators/WholeColoringGenerator.h"
#include "./prog/NonRepetitiveness.h"
#include "./prog/Consts.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;


int main()
{
    bool found;

    SimplePathGenerator pathGenerator = SimplePathGenerator(lengthOfPath, colorsInPath);

    Path nowPath = pathGenerator.nextPath();

    while (!(nowPath.empty()))
    {
        found = false;
        //cout << endl;
        //cout << "path with lists: ";
        //nowPath.printPath();

        WholeColoringGenerator coloringGenerator = WholeColoringGenerator(nowPath);

        Coloring coloring = coloringGenerator.nextColoring();

        while (!(coloring.empty()))
        {
            //cout << "coloring: ";
            //coloring.printColoring();
            if (checkNonRepetitiveness(coloring))
            {
                //this coloring has non-repetitive possibility, so skipping
                found = true;
                break;
            }
            coloring = coloringGenerator.nextColoring();
        }
        if (!found)
        {
            cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
        }
        nowPath = pathGenerator.nextPath();
    }
}
