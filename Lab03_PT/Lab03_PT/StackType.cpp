#include "StackType.h"



void StackType::MakeEmpty()
{
	top = -1;
}


bool StackType::IsEmpty() const
{
	return (top == -1);
}


bool StackType::IsFull() const
{
	return (top == MAX_ITEMS - 1);
}


void StackType::Push(ItemType newItem)
{
	if (IsFull()) {
		throw PushOnFullStack();
	}
	items[top++] = newItem;
}


void StackType::Pop(ItemType& Item)
{
	if (IsEmpty()) {
		throw PopOnEmptyStack();
	}
	Item = items[top--];
}

