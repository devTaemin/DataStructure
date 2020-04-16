#ifndef _PCH_H_
#define _PCH_H_


// Precompiled Header
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Relation between items.
enum RelationType { LESS, EQUAL, GREATER };


// Pre-defined variables' value
#define MAXLIST 10
#define MAXSTACK 10
#define MAXQUEUE 11


// Type
#include "ItemType.h"
#include "TempType.h"
#include "ContainerType.h"
#include "SimpleItemType.h"


// List
#include "SortedList.h"
#include "UnSortedList.h"
#include "Stack.h"
#include "CircularQueue.h"


// App
#include "Application.h"


#endif _PCH_H_