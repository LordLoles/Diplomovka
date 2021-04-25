#include "Main.h"
#include "./prog/Utils.h"
#include "./prog/Coloring.h"
#include "./prog/Path.h"
#include "./prog/PathGenerators/ByColorContinuingPathGenerator.h"
#include "./prog/ColoringGenerators/PartialColoringGenerator.h"
#include "./prog/NonRepetitiveness.h"
#include "./prog/Consts.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

constexpr int processorsCount = 4; //to how many part should be the file splitted
constexpr int thisProcessorNumber = 0; //which lines will this code process


int main()
{
    ifstream file("PathsStarts.txt");

    if (!file.is_open())
    {
        cout << "Unable to open file";
        return 0;
    }

    bool found;
    int lines = 0;
    int paths;
    int colorsUsed = 0;
    string line;

    while (getline(file, line))
    {
        lines++;
        if (((lines-1) % processorsCount) != thisProcessorNumber) continue;
        
        /*cout << endl;
        cout << "parsing line: " << line << endl;*/
        
        paths = 0;
        ByColorContinuingPathGenerator pathGenerator = ByColorContinuingPathGenerator(lengthOfPath, 2, colorsInPath, stringToPath(line));
        Path nowPath = pathGenerator.initialPath();

        while (!(nowPath.empty()))
        {
            /*cout << "path with lists: ";
            nowPath.printPath();*/
            paths++;

            found = false;

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

        if (colorsUsed < pathGenerator.colorsUsed()) colorsUsed = pathGenerator.colorsUsed();
    }

    file.close();
    cout << "Paths count " << paths << endl;
    cout << "Colors used " << colorsUsed << endl;
}
