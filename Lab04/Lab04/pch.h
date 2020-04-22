#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


#define MAXLIST 10
#define MAXQUEUE 11
#define MAXCONTAINER 10
#define FILENAMESIZE 1024



// Relation between items.
enum RelationType {LESS, EQUAL, GREATER};


// DS
#include "UnSortedList.h"
#include "SortedList.h"
#include "CircularQueue.h"
#include "SingleLinkedList.h"


// Type
#include "SimpleItemType.h"
#include "ItemType.h"
#include "TempType.h"
#include "ContainerType.h"
#include "StorageType.h"


// App
#include "Application.h"
