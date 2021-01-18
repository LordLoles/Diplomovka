#include "Main.h"
#include "./prog/Utils.h"
#include "./prog/Coloring.h"
#include "./prog/Path.h"
#include "./prog/PathGenerator.h"
#include "./prog/ColoringGenerators/AllAndWholeColoringGenerator.h"
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

    PathGenerator pathGenerator = PathGenerator(lengthOfPath, colorsInPath);

    Path nowPath = pathGenerator.nextPath();
    //TODO pozmen Path na array<int, length> (pole intov dlzky length - bude treba ten constexpr)

    while (!(nowPath.empty()))
    {
        found = false;
        cout << endl;
        cout << "path with lists: ";
        nowPath.printPath();

        AllAndWholeColoringGenerator coloringGenerator = AllAndWholeColoringGenerator(nowPath);

        Coloring coloring = coloringGenerator.nextColoring();
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
            coloring = coloringGenerator.nextColoring();
        }
        if (!found)
        {
            cout << "COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! COUNTEREXAMPLE! " << endl;
        }
        nowPath = pathGenerator.nextPath();
    }
}
