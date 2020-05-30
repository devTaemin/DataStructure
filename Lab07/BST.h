#pragma once
//----------------------------------------------------------------
//		Binary Tree Node struct
//----------------------------------------------------------------
template <typename T>
struct BinaryTreeNode
{
	T data;								///< Data.
	BinaryTreeNode<T>* left;			///< Connected node on the left side.
	BinaryTreeNode<T>* right;			///< Connected node on the right side.
};


//----------------------------------------------------------------
//		BST(Binary Search Tree) class
//----------------------------------------------------------------
template <typename T>
class BinarySearchTree
{
private:
	BinaryTreeNode<T>* root;			///< Root of Tree.

public:
	BinarySearchTree();
	//----------------------------------------------------------------
	//		Default Constructor.
	//----------------------------------------------------------------


	~BinarySearchTree();
	//----------------------------------------------------------------
	//		Destructor.
	//----------------------------------------------------------------


	bool IsEmpty() const;
	//----------------------------------------------------------------
	//	Brief  : Check Whether tree is empty.
	//	Pre    : None.
	//	Post   : None.
	//	Return : Return True if tree is empty, otherwise False.
	//----------------------------------------------------------------


	bool IsFull() const;
	//----------------------------------------------------------------
	//	Brief  : Check Whether tree is full.
	//	Pre    : None.
	//	Post   : None.
	//	Return : Return True if tree is full, otherwise False.
	//----------------------------------------------------------------


	void MakeEmpty();
	//----------------------------------------------------------------
	//	Brief  : Make tree empty.
	//	Pre    : None.
	//	Post   : Tree is empty.
	//----------------------------------------------------------------


	int GetLength() const;
	//----------------------------------------------------------------
	//	Brief  : Get the length of tree.
	//	Pre    : None.
	//	Post   : None.
	//	Return : Return the length of tree.
	//----------------------------------------------------------------


	void Add(T _item);
	//----------------------------------------------------------------
	//	Brief  : Add new node in tree.
	//	Pre    : None.
	//	Post   : New node is added in tree.
	//----------------------------------------------------------------


	void Delete(T _item);
	//----------------------------------------------------------------
	//	Brief  : Delete target node from tree.
	//	Pre    : None.
	//	Post   : Target node is deleted from tree.
	//----------------------------------------------------------------


	void Retrieve(T& _item, bool& _found) const;
	//----------------------------------------------------------------
	//	Brief  : Retrieve target node from tree.
	//	Pre    : Initialize bool variable to check if node is founded.
	//	Post   : None.
	//----------------------------------------------------------------


	void PrintTree(ostream& _out) const;
	//----------------------------------------------------------------
	//	Brief  : Display all nodes in tree.
	//	Pre    : None.
	//	Post   : None.
	//----------------------------------------------------------------

};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}


template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{

}


template <typename T>
bool BinarySearchTree<T>::IsEmpty() const
//----------------------------------------------------------------
//	(1) If root node refers to NULL, then return true.
//	(2) otherwise, return false.
//----------------------------------------------------------------
{
	if (root == NULL)										//	(1)
		return true;
	else													//	(2)
		return false;
}


template <typename T>
bool BinarySearchTree<T>::IsFull() const
//----------------------------------------------------------------
//	(1) Create binary tree node.
//	(2) Try to create and declare dynamic allocation.
//		if the process on allocation act properly, return false.
//  (3) Otherwise, if there is an error 'bad allocation'
//      return true.
//----------------------------------------------------------------
{
	BinaryTreeNode<T>* room;								//	(1)
	try														//	(2)
	{
		room = new BinaryTreeNode<T>;
		delete room;
		return false;
	}
	catch (std::bad_alloc exception)						//	(3)
	{
		return true;
	}
}


template <typename T>
void BinarySearchTree<T>::MakeEmpty()
//----------------------------------------------------------------
//	(1) Call the function for initialization.
//----------------------------------------------------------------
{
	MakeEmptyTree(root);									//	(1)
}


template <typename T>
int BinarySearchTree<T>::GetLength() const
//----------------------------------------------------------------
//	(1)	Call the recursive function for counting nodes.
//----------------------------------------------------------------
{
	return CountNodes(root);								//	(1)
}


template <typename T>
void BinarySearchTree<T>::Add(T _item)
//----------------------------------------------------------------
//	(1)	Call the recursive function for adding a node.
//----------------------------------------------------------------
{
	Insert(root, _item);
}


template <typename T>
void BinarySearchTree<T>::Delete(T _item)
//----------------------------------------------------------------
//	(1) Call the recursive function for deleting a node.
//----------------------------------------------------------------
{
	DeleteItem(root, _item);
}


template <typename T>
void BinarySearchTree<T>::Retrieve(T& _item, bool& _found) const
//----------------------------------------------------------------
//	(1) Call the recursive function for finding a node.
//----------------------------------------------------------------
{
	RetrieveItem(root, _item, _found);
}


template <typename T>
void BinarySearchTree<T>::PrintTree(ostream& _out) const
//----------------------------------------------------------------
//	(1)	Call the recursive function for printing nodes.
//----------------------------------------------------------------
{
	cout << endl;

	cout << "\t[PreOrder]" << endl;
	PrintPreOrderTraversal(root, _out);
	cout << endl;

	cout << "\t[InOrder]" << endl;
	PrintInOrderTraversal(root, _out);
	cout << endl;

	cout << "\t[PostOrder]" << endl;
	PrintPostOrderTraversal(root, _out);
	cout << endl;
}


/////////////////////////Global Functions/////////////////////////
//----------------------------------------------------------------
//			  Global Functons for Recursive Processing.
//----------------------------------------------------------------
template <typename T>
void MakeEmptyTree(BinaryTreeNode<T>*& _root)
//----------------------------------------------------------------
//	(1) Make root refer to Null in order to make empty.
//----------------------------------------------------------------
{
	_root = NULL;											//	(1)
}


template <typename T>
int CountNodes(BinaryTreeNode<T>* _root)
//----------------------------------------------------------------
//	Using recursive process to count the number of nodes in tree.
//	(1) Return 0, if root refers to NULL. 
//		(End condition of recursion)
//	(2) Sum up the number of left nodes, current node(1), and
//		right nodes by recursive method.
//----------------------------------------------------------------
{
	if (_root == NULL)										//	(1)
		return 0;
	else													//	(2)
		return CountNodes(_root->left) + 1 + CountNodes(_root->right);
}


template <typename T>
void Insert(BinaryTreeNode<T>*& _root, T _item)
//----------------------------------------------------------------
//	(1) If root refers to NULL, 
//		Dynamically allocate the node and connect the each sides
//		with NULL nodes.
//		And let the current node refers to target item.
//	(2)	if root is not empty and current item is greater than 
//		target item,
//		move to the left node from root and try to compare and insert
//		target item in recursive method.
//	(3)	if root is not empty and current item is less than 
//		target item,
//		move to the right node from root and try to compare and insert
//		target item in recursive method.
//	(4)	If the item is already stored, display error message.
//----------------------------------------------------------------
{
	if (_root == NULL)										//	(1)
	{
		_root = new BinaryTreeNode<T>;
		_root->left = NULL;
		_root->right = NULL;
		_root->data = _item;
	}
	else if (_root->data > _item)							//	(2)
		Insert(_root->left, _item);
	else if (_root->data < _item)							//	(3)
		Insert(_root->right, _item);
	else													//	(4)
		cout << "\t---[ERROR: DUPLICATED ITEM]---" << endl;	
}


template <typename T>
void DeleteItem(BinaryTreeNode<T>*& _root, T _item)
//----------------------------------------------------------------
//		Search the target item to delete by recursive method.
//	(1) if target item is less than the item in the root.
//	(2) if target item is greater than the item in the root.
//	(3) if target item is equal to the item.
//   -- 만약 이 상태에서 item이 찾아지지 않는다면 오류가 발생할 수 있다...?
//----------------------------------------------------------------
{
	if (_item < _root->data)								//  (1)
		DeleteItem(_root->left, _item);
	else if (_item > _root->data)							//  (2)
		DeleteItem(_root->right, _item);
	else													//  (3)
		DeleteNode(_root);
}


template <typename T>
void DeleteNode(BinaryTreeNode<T>*& _root)
//----------------------------------------------------------------
//		Delete the node and rearrange the binary tree.
//		Target node is founded and given in the argument.
//	(1)	If the left node of the target is empty,
//		replace the target position with the node on the right.
//	(2)	If the right node of the target is empty,
//		replace the target position with the node on the left.
//	(3)	If the both side of the target is not empty,
//		find the replacement with the function 'GetPredecessor',
//		replace the target position with the founded node,
//		and delete the replacing node at the original position.
//----------------------------------------------------------------
{
	T item;
	BinaryTreeNode<T>* tempNode;
	tempNode = _root;

	if (_root->left == NULL)								//  (1)
	{
		_root = _root->right;
		delete tempNode;
	}
	else if (_root->right == NULL)							//	(2)
	{
		_root = _root->left;
		delete tempNode;
	}
	else													//	(3)
	{
		GetPredecessor(_root->left, item);
		_root->data = item;
		DeleteItem(_root->left, item);
	}
}


template <typename T>
void GetPredecessor(BinaryTreeNode<T>* _root, T& _item)
//----------------------------------------------------------------
//		Find the node to replce deleting node.
//	(1) Find the biggest node on the left child node of the target
//		node.
//	(2) Copy the item.
//----------------------------------------------------------------
{
	while (_root->right != NULL)							//	(1)
		_root = _root->right;
	_item = _root->data;									//	(2)
}


template <typename T>
void RetrieveItem(BinaryTreeNode<T>* _root, T& _item, bool& found)
//----------------------------------------------------------------
//		Retreive the node with target item. 
//	(1)	If the current node is empty, make the found variable false.
//	(2) if the target item is less than the item in the current node,
//		retrieve the node on the left side of current node.
//	(3) if the target item is greater than the item in the current node,
//		retrieve the node on the right side of current node.
//	(4) if the target item is equal to the item in the current node,
//		copy the item in the node, and make the found variable true.
//----------------------------------------------------------------
{
	if (_root == NULL)										//	(1)
		found = false;
	else if (_item < _root->data)							//	(2)
		RetrieveItem(_root->left, _item, found);
	else if (_item > _root->data)							//	(3)
		RetrieveItem(_root->right, _item, found);
	else													//	(4)
	{
		_item = _root->data;
		found = true;
	}
}


template<typename T>
void PrintPreOrderTraversal(BinaryTreeNode<T>* _root, ostream& _out)
//----------------------------------------------------------------
//		전위 순회 (Preorder traverse)
//	(0)	End point.
//	(1)	Display root.
//	(2) Traverse to the left child root.
//	(3)	Traverse to the right child root.
//----------------------------------------------------------------
{
	if (_root != NULL)										//	(0)
	{
		_out << _root->data;								//	(1)
		PrintPreOrderTraversal(_root->left, _out);			//	(2)
		PrintPreOrderTraversal(_root->right, _out);			//	(3)
	}
}


template<typename T>
void PrintInOrderTraversal(BinaryTreeNode<T>* _root, ostream& _out)
//----------------------------------------------------------------
//		중위 순회 (Inorder traverse)
//	(0)	End point.
//	(1) Traverse to the left child root.
//	(2)	Display root.
//	(3) Travese to the right child root.
//----------------------------------------------------------------
{
	if (_root != NULL)										//	(0)
	{
		PrintInOrderTraversal(_root->left, _out);			//	(1)
		_out << _root->data;								//	(2)
		PrintInOrderTraversal(_root->right, _out);			//	(3)
	}
}


template<typename T>
void PrintPostOrderTraversal(BinaryTreeNode<T>* _root, ostream& _out)
//----------------------------------------------------------------
//		후위 순회 (Postorder traverse)
//	(0)	End point.
//	(1)	Traverse to the left child root.
//	(2)	Traverse to the right child root.
//	(3)	Display root.
//----------------------------------------------------------------
{
	if (_root != NULL)										//	(0)
	{
		PrintPostOrderTraversal(_root->left, _out);			//	(1)
		PrintPostOrderTraversal(_root->right, _out);		//	(2)
		_out << _root->data;								//	(3)
	}
}