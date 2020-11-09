//#include "../prog/Utils.h"
#include "../prog/Path.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

void test_size()
{
    Path* path = new Path();
    if (path->size() != 0) cout << "size should be zero" << endl;
}

int main()
{
    test_size();
}
