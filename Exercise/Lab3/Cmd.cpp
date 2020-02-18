/*
#include "Cmd.hpp"

template <typename T>
Cmd<T>::Cmd() {}

template <typename T>
Cmd<T>::~Cmd() {}

template <typename T>
void Cmd<T>::run()
{
	int input;
	bool key = true;

	while (key) {
		cout << "     " << "--- ID - Command -----" << endl;
		cout << "     " << "        1 : Enqueue Element" << endl;
		cout << "     " << "        2 : Dequeue Element" << endl;
		cout << "     " << "        3 : Is Empty?" << endl;
		cout << "     " << "        4 : Is Full?" << endl;
		cout << "     " << "        5 : EmptyQueue Exception test" << endl;
		cout << "     " << "        6 : FullQueue Exception test" << endl;
		cout << "     " << "        7 : Print all" << endl;
		cout << "     " << "        0 : Quit" << endl;
		cout << endl;
		cout << endl;
		cout << "     " << "Choose a Command --> ";
		cin >> input;

		switch (input)
		{
		case(1):
			enqueueElem();
			break;
		case(2):
			dequeueElem();
			break;
		case(3):
			isEmpty();
			break;
		case(4):
			isFull();
			break;
		case(5):
			emptyQueueExceptionTest();
			break;
		case(6):
			fullQueueExceptionTest();
			break;
		case(7):
			printAll();
			break;
		case(0):
			key = quit();
			break;
		}
		default:
			cerr << "False input!" << endl;
	}
	
}

template <typename T>
void Cmd<T>::enqueueElem()
{
	Cqueue.EnQueue();
}

template <typename T>
void Cmd<T>::dequeueElem()
{
	Cqueue.DeQueue();
}

template <typename T>
void Cmd<T>::isEmpty()
{
	Cqueue.IsEmpty();
}

template <typename T>
void Cmd<T>::isFull()
{
	Cqueue.IsFull();
}


template <typename T>
void Cmd<T>::emptyQueueExceptionTest()
{

}

template <typename T>
void Cmd<T>::fullQueueExceptionTest()
{

}

template <typename T>
void Cmd<T>::printAll()
{
	Cqueue.Print();
}

template <typename T>
bool Cmd<T>::quit()
{
	return false;
}
*/