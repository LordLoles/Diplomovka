#include "Main.h"
#include "./prog/Utils.h"
#include "./prog/Coloring.h"
#include "./prog/Path.h"
#include "./prog/PathGenerators/ByColorCappedColorsPathGenerator.h"
#include "./prog/NonRepetitiveness.h"
#include "./prog/Consts.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;


int main()
{
    ofstream file ;
    file.open("PathsStarts.txt", ios::trunc);

    if (!file.is_open())
    {
        cout << "Unable to open file";
        return 0;
    }

    bool found;
    int paths = 0;
    ByColorCappedColorsPathGenerator pathGenerator = ByColorCappedColorsPathGenerator(lengthOfPath, 2);
    Path nowPath = pathGenerator.initialPath();

    while (!(nowPath.empty()))
    {
        paths++;
        file << nowPath.to_string() << "\n";
        //nowPath.printPath();
        nowPath = pathGenerator.nextPath();
    }

    file.close();
    cout << "Paths count " << paths << endl;
    cout << "Colors used " << pathGenerator.colorsUsed() << endl;
}
