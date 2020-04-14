#include "TempType.h"
#include "pch.h"


// Default Constructor.
TempType::TempType()
{
	numOfItems = 0;
}


// Destructor.
TempType::~TempType(){}


// Adds new data to the last of the queue.
int TempType::Enqueue(ItemType data)
{
	if (tItemList.EnQueue(data)) { 
		numOfItems++;
		return 1; 
	}
	return 0;
}



// Delete data from the first of the queue.
int TempType::Dequeue(ItemType& data)
{
	if (tItemList.DeQueue(data)) {
		numOfItems--;
		return 1;
	}
	return 0;
}
