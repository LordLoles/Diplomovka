#include "TestByColorPathGenerator.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;


void TestByColorPathGenerator::test_isColorDisjunct()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(3, 4);

    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(2);
    byColorPathGenerator.generateNextColor(3);
    byColorPathGenerator.generateNextColor(3);
    //path should be {0, 1, 2} {1, 3, -1} {0, 3, -1}

    if (byColorPathGenerator.isColorDisjunct(0))
        {cout << "test_isColorDisjunct(): Color 0 should not be disjunct on path "; byColorPathGenerator.lastResult.printPath();}
    if (byColorPathGenerator.isColorDisjunct(1))
        {cout << "test_isColorDisjunct(): Color 1 should not be disjunct on path "; byColorPathGenerator.lastResult.printPath();}
    if (byColorPathGenerator.isColorDisjunct(2))
        {cout << "test_isColorDisjunct(): Color 2 should not be disjunct on path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.isColorDisjunct(3))
        {cout << "test_isColorDisjunct(): Color 3 should be disjunct on path "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_canBeFilled()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(3, 4);
    vector<array<int, 3>> path = {{0, 1, 2}, {0, 3, -1}, {0, -1, -1}};
    byColorPathGenerator.lastResult = Path(path);

    if (!byColorPathGenerator.canBeFilled(0))
        {cout << "test_canBeFilled(): Should be able to fill path, generating color 0, path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.canBeFilled(1))
        {cout << "test_canBeFilled(): Should be able to fill path, generating color 1, path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.canBeFilled(2))
        {cout << "test_canBeFilled(): Should be able to fill path, generating color 2, path "; byColorPathGenerator.lastResult.printPath();}
    if (byColorPathGenerator.canBeFilled(3))
        {cout << "test_canBeFilled(): Should not be able to fill path, generating color 3, path "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_checkWholeColorLex()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(4, 5);

    vector<array<int, 3>> path = {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}};
    byColorPathGenerator.lastResult = Path(path);
    if (!byColorPathGenerator.checkWholeColorLex(0))
        {cout << "test_checkWholeColorLex() 1: Lexicographicity of color 0 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.checkWholeColorLex(1))
        {cout << "test_checkWholeColorLex() 1: Lexicographicity of color 1 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.checkWholeColorLex(2))
        {cout << "test_checkWholeColorLex() 1: Lexicographicity of color 2 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
        
    path = {{0, 3, 4}, {1, 2, 3}, {0, 2, 3}, {0, 1, 3}};
    byColorPathGenerator.lastResult = Path(path);
    if (!byColorPathGenerator.checkWholeColorLex(1))
        {cout << "test_checkWholeColorLex() 2: Lexicographicity of color 1 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
    if (byColorPathGenerator.checkWholeColorLex(2))
        {cout << "test_checkWholeColorLex() 2: Color 2 should be at lex. sooner positions than color 1, but got 'true', path "; byColorPathGenerator.lastResult.printPath();}
    if (byColorPathGenerator.checkWholeColorLex(3))
        {cout << "test_checkWholeColorLex() 2: Color 3 should be at lex. sooner positions than color 0, but got 'true', path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.checkWholeColorLex(4))
        {cout << "test_checkWholeColorLex() 2: Lexicographicity of color 4 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
        
    path = {{0, 1, 4}, {1, 2, 3}, {0, 2, 3}, {0, 1, 3}};
    byColorPathGenerator.lastResult = Path(path);
    if (byColorPathGenerator.checkWholeColorLex(1))
        {cout << "test_checkWholeColorLex() 3: Color 1 should be at lex. sooner positions than color 0, but got 'true', path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.checkWholeColorLex(2))
        {cout << "test_checkWholeColorLex() 3: Lexicographicity of color 2 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
    if (byColorPathGenerator.checkWholeColorLex(3))
        {cout << "test_checkWholeColorLex() 3: Color 3 should be at lex. sooner positions than color 2, but got 'true', path "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_checkWholeColorsLex()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(4, 5);

    vector<array<int, 3>> path = {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}};
    byColorPathGenerator.lastResult = Path(path);
    if (!byColorPathGenerator.checkWholeColorsLex(0, 1, 0))
        {cout << "test_checkWholeColorsLex() 1: Lexicographicity of colors 0, 1, from vertex 0 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.checkWholeColorsLex(1, 2, 0))
        {cout << "test_checkWholeColorsLex() 1: Lexicographicity of colors 1, 2, from vertex 0 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.checkWholeColorsLex(2, 0, 1))
        {cout << "test_checkWholeColorsLex() 1: Lexicographicity of colors 2, 0, from vertex 1 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
        
    path = {{0, 3, 4}, {1, 2, 3}, {0, 2, 3}, {0, 1, 3}};
    byColorPathGenerator.lastResult = Path(path);
    if (byColorPathGenerator.checkWholeColorsLex(2, 1, 1))
        {cout << "test_checkWholeColorsLex() 2: Color 2 should be at lex. sooner positions than color 1, from vertex 1, but got 'true', path "; byColorPathGenerator.lastResult.printPath();}
    if (byColorPathGenerator.checkWholeColorsLex(3, 0, 0))
        {cout << "test_checkWholeColorsLex() 2: Color 3 should be at lex. sooner positions than color 0, from vertex 1, but got 'true', path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.checkWholeColorsLex(3, 0, 1))
        {cout << "test_checkWholeColorsLex() 2: Lexicographicity of colors 0, 3, from vertex 1 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
    if (!byColorPathGenerator.checkWholeColorsLex(2, 0, 1))
        {cout << "test_checkWholeColorsLex() 2: Lexicographicity of colors 0, 2, from vertex 1 should be ok, path "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_deleteColorBeingGenerated()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(2, 4);
    byColorPathGenerator.nextFullPath();

    byColorPathGenerator.deleteColorBeingGenerated();
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, 1, -1})
        {cout << "test_deleteColor(): Path should be {0, 1, -1} {0, 1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.deleteColorBeingGenerated();
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, -1, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_deleteColor(): Path should be {0, -1, -1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.deleteColorBeingGenerated();
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{-1, -1, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{-1, -1, -1})
        {cout << "test_deleteColor(): Path should be {-1, -1, -1} {-1, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_getFirstAppearance()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(4, 5);
    vector<array<int, 3>> path = {{0, 3, 4}, {1, 2, 3}, {0, 2, 3}, {0, 1, 3}};
    byColorPathGenerator.lastResult = Path(path);

    int firstAppearance = byColorPathGenerator.getFirstAppearance(0);
    if (firstAppearance != 0)
        {cout << "test_getFirstAppearance(): First appearance of 0 is on vertex 0, but got " << firstAppearance << ", path was "; byColorPathGenerator.lastResult.printPath();}
    firstAppearance = byColorPathGenerator.getFirstAppearance(1);
    if (firstAppearance != 1)
        {cout << "test_getFirstAppearance(): First appearance of 1 is on vertex 1, but got " << firstAppearance << ", path was "; byColorPathGenerator.lastResult.printPath();}
    firstAppearance = byColorPathGenerator.getFirstAppearance(2);
    if (firstAppearance != 1)
        {cout << "test_getFirstAppearance(): First appearance of 2 is on vertex 1, but got " << firstAppearance << ", path was "; byColorPathGenerator.lastResult.printPath();}
    firstAppearance = byColorPathGenerator.getFirstAppearance(3);
    if (firstAppearance != 0)
        {cout << "test_getFirstAppearance(): First appearance of 3 is on vertex 0, but got " << firstAppearance << ", path was "; byColorPathGenerator.lastResult.printPath();}
    firstAppearance = byColorPathGenerator.getFirstAppearance(4);
    if (firstAppearance != 0)
        {cout << "test_getFirstAppearance(): First appearance of 4 is on vertex 0, but got " << firstAppearance << ", path was "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_generateFillingColors()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(4, 4);
    vector<array<int, 3>> path = {{0, 1, -1}, {0, 1, 3}, {0, -1, -1}, {3, -1, -1}};
    byColorPathGenerator.lastResult = Path(path);
    byColorPathGenerator.colorsUsage = vector<set<int>>{{0, 1, 2}, {0, 1}, {}, {1, 3}};

    bool res = byColorPathGenerator.generateFillingColors(1);
    if (res || byColorPathGenerator.lastResult.to_vector() != vector<array<int, 3>>{{0, 1, -1}, {0, 1, 3}, {0, -1, -1}, {3, -1, -1}})
        {cout << "test_generateFillingColors(): should have generated {0, 1, -1}, {0, 1, 3}, {0, -1, -1}, {3, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    res = byColorPathGenerator.generateFillingColors(2);
    if (!res || byColorPathGenerator.lastResult.to_vector() != vector<array<int, 3>>{{0, 1, -1}, {0, 1, 3}, {0, 2, -1}, {3, 2, -1}})
        {cout << "test_generateFillingColors(): should have generated {0, 1, -1}, {0, 1, 3}, {0, 2, -1}, {3, 2, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    res = byColorPathGenerator.generateFillingColors(3);
    if (!res || byColorPathGenerator.lastResult.to_vector() != vector<array<int, 3>>{{0, 1, 3}, {0, 1, 3}, {0, 2, 3}, {3, 2, -1}})
        {cout << "test_generateFillingColors(): should have generated {0, 1, 3}, {0, 1, 3}, {0, 2, 3}, {3, 2, -1}, but was "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_generateNextColor()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(2, 4);

    byColorPathGenerator.generateNextColor(0);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, -1, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{-1, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, -1, -1} {-1, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(0);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, -1, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, -1, -1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(2);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, -1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, 1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, 1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, 1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, 1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, 1} {0, 1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    bool ret = byColorPathGenerator.generateNextColor(1);
    if (ret || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, -1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, -1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    ret = byColorPathGenerator.generateNextColor(1);
    if (!ret || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 2, 1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 2, 1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    ret = byColorPathGenerator.generateNextColor(0);
    if (ret || byColorPathGenerator.lastResult.at(0) != array<int, 3>{-1, 2, 1} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{-1, -1, -1})
        {cout << "test_generateNextColor(): should have generated {-1, 2, 1} {-1, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

        
    byColorPathGenerator = ByColorPathGenerator(3, 4);
    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(2);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{-1, -1, -1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, -1, -1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {-1, -1, -1} {0, -1, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(3);
    byColorPathGenerator.generateNextColor(3);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, -1, -1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, -1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {3, -1, -1} {0, 3, -1}, but was "; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(2);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, 2, -1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, 1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {3, 2, -1} {0, 3, 1}, but was "; byColorPathGenerator.lastResult.printPath();}
        
    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, 2, 1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, -1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {3, 2, 1} {0, 3, -1}, but was "; byColorPathGenerator.lastResult.printPath();}
        
    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, 2, 1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, 1})
        {cout << "test_generateNextColor(): should have generated {0, 1, 2} {3, 2, 1} {0, 3, 1}, but was "; byColorPathGenerator.lastResult.printPath();}
        
    byColorPathGenerator.generateNextColor(1);
    if (byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, -1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{3, 2, -1} || 
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 3, -1})
        {cout << "test_generateNextColor(): should have generated {0, -1, 2} {3, 2, -1} {0, 3, -1}, but was "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_getFirstNotFullVertex()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(3, 4);

    int vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 0)
        {cout << "test_getFirstNotFullVertex(): First not full should be 0, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(0);
    byColorPathGenerator.generateNextColor(0);
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 0)
        {cout << "test_getFirstNotFullVertex(): First not full should be 0 again, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 0)
        {cout << "test_getFirstNotFullVertex(): First not full should be 0 once again, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(2);
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 1)
        {cout << "test_getFirstNotFullVertex(): First not full should be 1, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(3);
    byColorPathGenerator.generateNextColor(3);
    byColorPathGenerator.generateNextColor(1);
    byColorPathGenerator.generateNextColor(2);
    byColorPathGenerator.generateNextColor(1);
    //path should be {0, 1, 2} {3, 2, 1} {0, 3, -1}
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != 2)
        {cout << "test_getFirstNotFullVertex(): First not full should be 2, but was " << vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}

    byColorPathGenerator.generateNextColor(1);
    //path should be full - {0, 1, 2} {3, 2, 1} {0, 3, 1}
    vertex = byColorPathGenerator.getFirstNotFullVertex();
    if (vertex != -1)
        {cout << "test_getFirstNotFullVertex(): There should not be not full vertex, but function returned " << 
        vertex << ", whole path was"; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_nextFullPath()
{
    ByColorPathGenerator byColorPathGenerator = ByColorPathGenerator(1, 3);

    bool isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2})
        {cout << "test_nextFullPath() 0: Full path should be {0, 1, 2}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (isFull)
        {cout << "test_nextFullPath() 0: There should not be any more full paths, but was generated "; byColorPathGenerator.lastResult.printPath();}


    byColorPathGenerator = ByColorPathGenerator(2, 4);

    isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, 1, 2})
        {cout << "test_nextFullPath() 1: Full path should be {0, 1, 2} {0, 1, 2}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (isFull)
        {cout << "test_nextFullPath() 1: There should not be any more full paths, but was generated "; byColorPathGenerator.lastResult.printPath();}


    byColorPathGenerator = ByColorPathGenerator(3, 4);

    isFull = byColorPathGenerator.nextFullPath();
    if (!isFull || byColorPathGenerator.lastResult.at(0) != array<int, 3>{0, 1, 2} || 
        byColorPathGenerator.lastResult.at(1) != array<int, 3>{0, 1, 2} ||
        byColorPathGenerator.lastResult.at(2) != array<int, 3>{0, 1, 2})
        {cout << "test_nextFullPath() 2: Full path should be {0, 1, 2} {0, 1, 2} {0, 1, 2}, but was "; byColorPathGenerator.lastResult.printPath();}

    isFull = byColorPathGenerator.nextFullPath();
    if (isFull)
        {cout << "test_nextFullPath() 2: There should not be any more full paths, but was generated "; byColorPathGenerator.lastResult.printPath();}
}

void TestByColorPathGenerator::test_all()
{
    cout << "Testing ByColorPathGenerator..." << endl;
    
    test_isColorDisjunct();
    test_canBeFilled();
    test_checkWholeColorLex();
    test_checkWholeColorsLex();
    test_deleteColorBeingGenerated();

    test_getFirstAppearance();
    test_getFirstNotFullVertex();

    test_generateFillingColors();
    test_generateNextColor();
    //test_nextFullPath(); TODO otestuj, az ked budu optimalizacie, kedze sa vysledok funkcie vzdy meni
}
