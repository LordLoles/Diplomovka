#include "Main.h"
#include "./prog/Utils.h"
#include "./prog/Coloring.h"
#include "./prog/Path.h"
#include "./prog/PathGenerator.h"
#include "./prog/ColoringGenerator.h"
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

    PathGenerator pathGen = PathGenerator(lengthOfPath, colorsInPath);

    Path nowPath = pathGen.nextPath();
    //TODO pozmen Path na array<int, length> (pole intov dlzky length - bude treba ten constexpr)

    while (!(nowPath.empty()))
    {
        found = false;
        cout << endl;
        cout << "path with lists: ";
        nowPath.printPath();
        
        ColoringGenerator coloringGen = ColoringGenerator(nowPath);

        Coloring coloring = coloringGen.nextColoring();
        //TODO aj coloring by slo na array<int, length>, ale musis si pamatat momentalnu dlzku

        while (!(coloring.empty()))
        {
            cout << "coloring: ";
            coloring.printColoring();
            if (checkNonRepetitiveness(coloring))
            {
                //this coloring has non-repetitive possibility, so skipping
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
