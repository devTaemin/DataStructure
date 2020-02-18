#ifndef Cmd_hpp
#define Cmd_hpp
#include "CircularQueueType.hpp"

template <typename T>
class Cmd
{
public:
	Cmd() {}
	~Cmd() {}

	void run()
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
			default:
				cerr << "False input!" << endl;
			}
		}
	}


	void enqueueElem()
	{
		if (!Cqueue.IsFull()) {
			T input;
			cout << "     " << "Enter the item: ";
			cin >> input;
			Cqueue.EnQueue(input);
		}
		else {
			cerr << "     " << "fail to enqueue Element!" << endl;
		}
	
	}

	void dequeueElem()
	{
		if (!Cqueue.IsEmpty()) {
			T temp;
			Cqueue.DeQueue(temp);
			cout << temp << endl;
		}
		else {
			cerr << "     " << "fail to dequeue Element!" << endl;
		}
	
	}

	void isEmpty()
	{
		if (Cqueue.IsEmpty()) { cout << "     " << "EMPTY!" << endl; }
		else { cout << "     " << "Not EMPTY!" << endl; }
		cout << endl;
	}

	void isFull()
	{
		if (Cqueue.IsFull()) { cout << "     " << "FULL!" << endl; }
		else { cout << "     " << "Not FULL!" << endl; }
		cout << endl;
	}

	void emptyQueueExceptionTest() 
	{
	
	}

	void fullQueueExceptionTest() 
	{
	
	}

	void printAll()
	{
		Cqueue.Print();
		cout << endl;
	}

	bool quit()
	{
		return false;
	}

private:
	CircularQueueType<T> Cqueue;
};
/*
class Cmd
{
public:
	Cmd();
	~Cmd();

	void run();
	void enqueueElem();
	void dequeueElem();
	void isEmpty();
	void isFull();
	void emptyQueueExceptionTest();
	void fullQueueExceptionTest();
	void printAll();
	bool quit();

private:
	CircularQueueType<T> Cqueue;
};
#include "Cmd.hpp"
*/
#endif
