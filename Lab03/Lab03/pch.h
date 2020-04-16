#ifndef _PCH_H_
#define _PCH_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXLIST 10
#define MAXSTACK 10
#define MAXQUEUE 11
// Relation between items.
enum RelationType { LESS, EQUAL, GREATER };

// DS
#include "SortedList.h"
#include "UnSortedList.h"
#include "Stack.h"
#include "CircularQueue.h"


// Type
#include "ItemType.h"
#include "SimpleItemType.h"
#include "TempType.h"
#include "ContainerType.h"


// App
#include "Application.h"



#endif _PCH_H_