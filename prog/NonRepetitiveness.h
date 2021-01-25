#pragma once

#ifndef NONREPETITIVENESS_H
#define NONREPETITIVENESS_H

#include "Coloring.h"

using namespace std;

bool checkEqualityOnIndexWithSize(const Coloring & coloring, int index, int size);
bool checkNonRepetitivenessOnIndex(const Coloring & coloring, int index);
bool checkNonRepetitivenessOnLastIndex(const Coloring & coloring);
bool checkNonRepetitiveness(const Coloring & coloring);

#endif
