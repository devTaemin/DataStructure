#ifndef _NodeType_hpp_
#define _NodeType_hpp_
#include <iostream>
using namespace std;

template <typename T>
struct NodeType
{
	T info;
	NodeType* next;
};
#endif