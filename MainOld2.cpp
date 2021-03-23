#include "Main.h"
#include "./prog/Utils.h"
#include "./prog/Coloring.h"
#include "./prog/Path.h"
#include "./prog/PathGenerators/SimpleWithMemoryPathGenerator.h"
#include "./prog/ColoringGenerators/PartialColoringGenerator.h"
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

    SimpleWithMemoryPathGenerator pathGenerator = SimpleWithMemoryPathGenerator(lengthOfPath, colorsInPath);

    //Path nowPath = pathGenerator.initialPath();
    Path nowPath = pathGenerator.initialPath();
    int paths = 0;

    //TODO pozmen Path na array<int, length> (pole intov dlzky length - bude treba ten constexpr)

    while (!(nowPath.empty()))
    {
        /*found = false;
        cout << endl;
        cout << "path with lists: ";
        nowPath.printPath();*/
        paths++;

        PartialColoringGenerator coloringGenerator = PartialColoringGenerator(nowPath);

        Coloring coloring = coloringGenerator.initialColoring();
        //TODO aj coloring by slo na array<int, length>, ale musis si pamatat momentalnu dlzku
        while (!(coloring.empty()))
        {
            /*cout << "coloring: ";
            coloring.printColoring();*/

            if (checkNonRepetitivenessOnLastIndex(coloring))
            {
                if (coloringGenerator.isFullColoring())
                {
                    found = true;
                    break;
                }
                else
                {
                    coloring = coloringGenerator.nextColoring();
                }
            }
            else
            {
                //coloring contains repetition
                coloring = coloringGenerator.skipColoring();
            }
        }
        if (!found)
        {
            cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
            nowPath.printPath();
        }
        nowPath = pathGenerator.nextPath();
    }
    cout << "MainOld2: Paths count " << paths << endl;
}