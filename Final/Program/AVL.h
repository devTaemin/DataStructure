#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
//		AVL Tree class
//----------------------------------------------------------------
template <typename T>
class AVLTree
{
private:
	BinaryTreeNode<T>* m_Root;			///< Root of Tree.
	int m_Length;						///< Number of item stored.


	int Max(int i, int j);
	//----------------------------------------------------------------
	//		Return the bigger one.
	//----------------------------------------------------------------


	int getHeight(BinaryTreeNode<T>* _node);
	//----------------------------------------------------------------
	//		Return the height of node.
	//----------------------------------------------------------------


	int getBalance(BinaryTreeNode<T>* _node);
	//----------------------------------------------------------------
	//		Return the difference between node's left tree and
	//		node's right tree to check if tree is balanced or not.
	//----------------------------------------------------------------


	void PrintInOrderTraversal(BinaryTreeNode<T>* _root);
	//----------------------------------------------------------------
	//		Display all nodes in tree.
	//----------------------------------------------------------------


	void SaveInOrderTraversal(BinaryTreeNode<T>* _root, ofstream& _out);
	//----------------------------------------------------------------
	//		Save all nodes in tree.
	//----------------------------------------------------------------


	BinaryTreeNode<T>* Rotate_LL(BinaryTreeNode<T>* _parent);
	//----------------------------------------------------------------
	//		Do single rotation to the left.
	//----------------------------------------------------------------


	BinaryTreeNode<T>* Rotate_RR(BinaryTreeNode<T>* _parent);
	//----------------------------------------------------------------
	//		Do single rotation to the right.
	//----------------------------------------------------------------


	BinaryTreeNode<T>* Rotate_LR(BinaryTreeNode<T>* _parent);
	//----------------------------------------------------------------
	//		Do double rotation to the left and right.
	//----------------------------------------------------------------


	BinaryTreeNode<T>* Rotate_RL(BinaryTreeNode<T>* _parent);
	//----------------------------------------------------------------
	//		Do double rotation to the right and left.
	//----------------------------------------------------------------


	BinaryTreeNode<T>* RecursiveInsert(BinaryTreeNode<T>* _node, T _data, bool& _func);
	//----------------------------------------------------------------
	//		Recursive function for adding node.
	//----------------------------------------------------------------


	BinaryTreeNode<T>* RecursivePointerInsert(BinaryTreeNode<T>* _node, T _data, bool& _func);
	//----------------------------------------------------------------
	//		Recursive function for adding node.
	//----------------------------------------------------------------


	BinaryTreeNode<T>* RecursiveDelete(BinaryTreeNode<T>* _node, T _data, bool& _func);
	//----------------------------------------------------------------
	//		Recursive function for deleting node.
	//----------------------------------------------------------------


	BinaryTreeNode<T>* RecursivePointerDelete(BinaryTreeNode<T>* _node, T _data, bool& _func);
	//----------------------------------------------------------------
	//		Recursive function for deleting node.
	//----------------------------------------------------------------


	BinaryTreeNode<T>* MakeBalance(BinaryTreeNode<T>* _node);
	//----------------------------------------------------------------
	//		Balance the input node. 
	//----------------------------------------------------------------


public:
	AVLTree();
	//----------------------------------------------------------------
	//		Default Constructor.
	//----------------------------------------------------------------


	~AVLTree();
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


	void MakeEmpty(BinaryTreeNode<T>*& _node);
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


	void Add(T& _item, bool& _func);
	//----------------------------------------------------------------
	//	Brief  : Add new node in tree.
	//	Pre    : None.
	//	Post   : New node is added in tree.
	//----------------------------------------------------------------

	void AddPointerItem(T& _item, bool& _func);
	//----------------------------------------------------------------
	//	Brief  : Add new node in tree.
	//	Pre    : None.
	//	Post   : New node is added in tree.
	//----------------------------------------------------------------


	void Delete(T& _item, bool& _func);
	//----------------------------------------------------------------
	//	Brief  : Delete target node from tree.
	//	Pre    : None.
	//	Post   : Target node is deleted from tree.
	//----------------------------------------------------------------


	void DeletePointerItem(T& _item, bool& _func);
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


	void RetrievePointerItem(T& _item, bool& _found) const;
	//----------------------------------------------------------------
	//	Brief  : Retrieve target node from tree.
	//	Pre    : Initialize bool variable to check if node is founded.
	//	Post   : None.
	//----------------------------------------------------------------


	void Replace(T& _item, bool& _found);
	//----------------------------------------------------------------
	//	Brief  : Replace target node's content in tree.
	//	Pre    : None.
	//	Post   : The content of target node is changed.
	//----------------------------------------------------------------


	void ReplacePointerItem(T& _item, bool& _found);
	//----------------------------------------------------------------
	//	Brief  : Replace target node's content in tree.
	//	Pre    : None.
	//	Post   : The content of target node is changed.
	//----------------------------------------------------------------


	void PrintTree(ostream& _out);
	//----------------------------------------------------------------
	//	Brief  : Display all nodes in tree.
	//	Pre    : None.
	//	Post   : None.
	//----------------------------------------------------------------

};


// Default Constructor.
template <typename T>
AVLTree<T>::AVLTree()
//----------------------------------------------------------------
//	Default Constructor.
//	Initialize the root of tree as 'NULL' and set length 0.
//----------------------------------------------------------------
{
	m_Root = nullptr;
	m_Length = 0;
}


// Destructor.
template <typename T>
AVLTree<T>::~AVLTree()
//----------------------------------------------------------------
//	Destructor.
//----------------------------------------------------------------
{
	//MakeEmpty(m_Root);
}


// Check Whether tree is empty.
template <typename T>
bool AVLTree<T>::IsEmpty() const
//----------------------------------------------------------------
//	Check whether the number of nodes stored is 0 or not.
//	Return true if the length equals to 0, otherwise false.
//----------------------------------------------------------------
{
	if (m_Length == 0)
		return true;
	else
		return false;
}


// Check Whether tree is full.
template <typename T>
bool AVLTree<T>::IsFull() const
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


// Make tree empty by recursive method.
template <typename T>
void AVLTree<T>::MakeEmpty(BinaryTreeNode<T>*& _node)
//----------------------------------------------------------------
//	Make empty(Delete) input node and all of its child nodes.
//	(1)	Stop if node is empty.
//	(2)	Using PostOrderTraversing, delete the lowest nodes first 
//		and delete upper nodes.
//	(3)	Finally delete the target node initailly called as argument.
//----------------------------------------------------------------
{
	if (_node == nullptr)									//	(1)
		return;
	else													//	(2)
	{
		MakeEmpty(_node->left);
		MakeEmpty(_node->right);
		delete _node;										//	(3)
		_node = nullptr;
	}
}


// Get the length of tree.
template <typename T>
int AVLTree<T>::GetLength() const
//----------------------------------------------------------------
//	Return the number of nodes stored in tree.
//----------------------------------------------------------------
{
	return m_Length;
}


// Add new node in tree.
template <typename T>
void AVLTree<T>::Add(T& _item, bool& _func)
//----------------------------------------------------------------
//	(1) Call recursive function to add item.
//----------------------------------------------------------------
{
	if (m_Root == nullptr)
	{
		BinaryTreeNode<T>* tempNode = new BinaryTreeNode<T>;
		tempNode->data = _item;
		tempNode->left = nullptr;
		tempNode->right = nullptr;
		m_Root = tempNode;
		m_Length++;
	}
	else 
	{
		m_Root = RecursiveInsert(m_Root, _item, _func);
	}
}

// Add new node in tree.
template <typename T>
void AVLTree<T>::AddPointerItem(T& _item, bool& _func)
//----------------------------------------------------------------
//	(1) Call recursive function to add item.
//----------------------------------------------------------------
{
	if (m_Root == nullptr)
	{
		BinaryTreeNode<T>* tempNode = new BinaryTreeNode<T>;
		tempNode->data = _item;
		tempNode->left = nullptr;
		tempNode->right = nullptr;
		m_Root = tempNode;
		m_Length++;
	}
	else
	{
		m_Root = RecursivePointerInsert(m_Root, _item, _func);
	}
}



// Delete target node from tree.
template <typename T>
void AVLTree<T>::Delete(T& _item, bool& _func)
//----------------------------------------------------------------
//	(1) Call recursive function to delete item.
//----------------------------------------------------------------
{
	m_Root = RecursiveDelete(m_Root, _item, _func);
}


// Delete target node from tree.
template<typename T>
void AVLTree<T>::DeletePointerItem(T& _item, bool& _func)
//----------------------------------------------------------------
//	(1) Call recursive function to delete item.
//----------------------------------------------------------------
{
	m_Root = RecursivePointerDelete(m_Root, _item, _func);
}

// Retrieve target node from tree.
template <typename T>
void AVLTree<T>::Retrieve(T& _item, bool& _found) const
//----------------------------------------------------------------
//	(1)  Declare temporary node to refer to root of AVL Tree.
//	(2)	 Loop while temporary node is not nullptr.
//	(2.1)If target item is less than node's item,
//		 move to the left node to find the target item.
//	(2.2)If target item is greater than node's item,
//		 move to the right node to find the target item.
//	(2.3)If target item is founded,
//		 move to the left node to find the target item.
//		- Copy the content of item to the argument '_item'.
//		- Make the '_found' argument to refer to true.
//	(3)	 If fail to find target item, '_found' refer to false.
//----------------------------------------------------------------
{
	BinaryTreeNode<T>* TempNode;							//	(1)
	TempNode = m_Root;
	_found = false;

	while (TempNode != nullptr)								//	(2)
	{
		if (TempNode->data > _item)							//(2.1)
		{
			TempNode = TempNode->left;
		}
		else if (TempNode->data < _item)					//(2.2)
		{
			TempNode = TempNode->right;
		}
		else												//(2.3)
		{
			_item = TempNode->data;
			_found = true;
			break;
		}
	}														//	(3)
}


// Retrieve target node from tree.
template<typename T>
void AVLTree<T>::RetrievePointerItem(T& _item, bool& _found) const
//----------------------------------------------------------------
//	(1)  Declare temporary node to refer to root of AVL Tree.
//	(2)	 Loop while temporary node is not nullptr.
//	(2.1)If target item is less than node's item,
//		 move to the left node to find the target item.
//	(2.2)If target item is greater than node's item,
//		 move to the right node to find the target item.
//	(2.3)If target item is founded,
//		 move to the left node to find the target item.
//		- Copy the content of item to the argument '_item'.
//		- Make the '_found' argument to refer to true.
//	(3)	 If fail to find target item, '_found' refer to false.
//----------------------------------------------------------------
{
	BinaryTreeNode<T>* TempNode;							//	(1)
	TempNode = m_Root;
	_found = false;

	while (TempNode != nullptr)								//	(2)
	{
		T target = TempNode->data;
		int tID = target->GetID();
		int CompareID = _item->GetID();
		if (tID > CompareID)							//(2.1)
		{
			TempNode = TempNode->left;
		}
		else if (tID < CompareID)						//(2.2)
		{
			TempNode = TempNode->right;
		}
		else												//(2.3)
		{
			_item = TempNode->data;
			_found = true;
			break;
		}
	}														//	(3)
}


// Replace target node's content in tree.
template <typename T>
void AVLTree<T>::Replace(T& _item, bool& _found)
//----------------------------------------------------------------
//	
//----------------------------------------------------------------
{
	BinaryTreeNode<T>* TempNode;
	TempNode = m_Root;
	_found = false;
	while (TempNode != nullptr)
	{
		if (TempNode->data > _item)
		{
			TempNode = TempNode->left;
		}
		else if (TempNode->data < _item)
		{
			TempNode = TempNode->right;
		}
		else
		{
			TempNode->data = _item;
			_found = true;
			break;
		}
	}
}


// Replace target node's content in tree.
template <typename T>
void AVLTree<T>::ReplacePointerItem(T& _item, bool& _found)
//----------------------------------------------------------------
//	
//----------------------------------------------------------------
{
	BinaryTreeNode<T>* TempNode;
	TempNode = m_Root;
	_found = false;
	while (TempNode != nullptr)
	{
		T target = TempNode->data;
		int tID = target->GetID();
		if (tID > _item->GetID())
		{
			TempNode = TempNode->left;
		}
		else if (tID < _item->GetID())
		{
			TempNode = TempNode->right;
		}
		else
		{
			TempNode->data = _item;
			_found = true;
			break;
		}
	}
}

// Display all nodes in tree.
template <typename T>
void AVLTree<T>::PrintTree(ostream& _out)
//----------------------------------------------------------------
//	
//----------------------------------------------------------------
{
	PrintInOrderTraversal(m_Root);
}



/////////////////////////Private Functions/////////////////////////
//----------------------------------------------------------------
//			  Private Functons for Recursive Processing.
//----------------------------------------------------------------
template <typename T>
int AVLTree<T>::Max(int i, int j)
//----------------------------------------------------------------
//	Return the bigger one.
//----------------------------------------------------------------
{
	if (i > j)
		return i;
	return j;
}


// Return the height of node.
template <typename T>
int AVLTree<T>::getHeight(BinaryTreeNode<T>* _node)
//----------------------------------------------------------------
//	(1) Declare variable 'height'.
//	(2) End point, node is nullptr,
//		-	count the height by recursive method.
//		-	compare the each side of child nodes' height, and choose
//			greater one as height.
//	(3)	Return the height equals to child's maximum height + 1.
//----------------------------------------------------------------
{
	int height = 0;											//	(1)
	if (_node != nullptr)									//	(2)
	{
		int i = getHeight(_node->left);
		int j = getHeight(_node->right);
		height = Max(i, j);
	}
	return height + 1;										//	(3)
}


// Return the difference between node's left tree and node's right tree to check if tree is balanced or not.
template <typename T>
int AVLTree<T>::getBalance(BinaryTreeNode<T>* _node)
//----------------------------------------------------------------
//	Return the difference between node's left tree and
//	node's right tree to check if tree is balanced or not.
//----------------------------------------------------------------
{
	return getHeight(_node->left) - getHeight(_node->right);
}


// Display all nodes in tree.
template <typename T>
void AVLTree<T>::PrintInOrderTraversal(BinaryTreeNode<T>* _root)
//----------------------------------------------------------------
//		
//----------------------------------------------------------------
{
	if (_root != NULL)
	{
		PrintInOrderTraversal(_root->left);
		cout << _root->data << endl;
		PrintInOrderTraversal(_root->right);
	}
}


// Save all nodes in tree.
template <typename T>
void AVLTree<T>::SaveInOrderTraversal(BinaryTreeNode<T>* _root, ofstream& _out)
//----------------------------------------------------------------
//		
//----------------------------------------------------------------
{

}


// Do single rotation to the left.
template <typename T>
BinaryTreeNode<T>* AVLTree<T>::Rotate_LL(BinaryTreeNode<T>* _parent)
//----------------------------------------------------------------
//		
//----------------------------------------------------------------
{
	BinaryTreeNode<T>* child = _parent->left;
	_parent->left = child->right;
	child->right = _parent;
	return child;
}


// Do single rotation to the right.
template <typename T>
BinaryTreeNode<T>* AVLTree<T>::Rotate_RR(BinaryTreeNode<T>* _parent)
//----------------------------------------------------------------
//		
//----------------------------------------------------------------
{
	BinaryTreeNode<T>* child = _parent->right;
	_parent->right = child->left;
	child->left = _parent;
	return child;
}


// Do double rotation to the left and right.
template <typename T>
BinaryTreeNode<T>* AVLTree<T>::Rotate_LR(BinaryTreeNode<T>* _parent)
//----------------------------------------------------------------
//		
//----------------------------------------------------------------
{
	BinaryTreeNode<T>* child = _parent->left;
	_parent->left = Rotate_RR(child);
	return Rotate_LL(_parent);
}


// Do double rotation to the right and left.
template <typename T>
BinaryTreeNode<T>* AVLTree<T>::Rotate_RL(BinaryTreeNode<T>* _parent)
//----------------------------------------------------------------
//		
//----------------------------------------------------------------
{
	BinaryTreeNode<T>* child = _parent->right;
	_parent->right = Rotate_LL(child);
	return Rotate_LL(_parent);
}


// Recursive function for adding node.
template <typename T>
BinaryTreeNode<T>* AVLTree<T>::RecursiveInsert(BinaryTreeNode<T>* _node, T _data, bool& _func)
//----------------------------------------------------------------
//	(1)	 If node equals to 'nullptr', then create node dynamically,
//		 store the data, connect left and right node 'nullptr', and
//		 increase the length of tree.
//	(2)	 If node is not 'nullptr'
//	(2.1)If node's data is greater than input data,
//		- Compare with the left child node.
//		- If the node is empty, Take the (1) process.
//		- Otherwise, recursive the function with argument node->left.
//		- Keep the balance.
//	(2.2)If node's data is less than input data,
//		- Compare with the right child node.
//		- If the node is empty, Take the (1) process.
//		- Otherwise, recursive the function with argument node->right.
//		- Keep the balance.
//	(2.3)If node's data is equal to input data,
//		- Display the error message.
//----------------------------------------------------------------
{
	bool func;
	if (_node->data > _data)							//(2.1)
	{
		if (_node->left == nullptr)
		{
			BinaryTreeNode<T>* NewNode = new BinaryTreeNode<T>;
			NewNode->data = _data;
			NewNode->left = nullptr;
			NewNode->right = nullptr;
			_node->left = NewNode;
			m_Length++;
			_func = true;
		}
		else
		{
			RecursiveInsert(_node->left, _data, func);
		}
		_node = MakeBalance(_node);
	}
	else if (_node->data < _data)						//(2.2)
	{
		if (_node->right == nullptr)
		{
			BinaryTreeNode<T>* NewNode = new BinaryTreeNode<T>;
			NewNode->data = _data;
			NewNode->left = nullptr;
			NewNode->right = nullptr;
			_node->right = NewNode;
			m_Length++;
			_func = true;
		}
		else
		{
			RecursiveInsert(_node->right, _data, func);
		}
		_node = MakeBalance(_node);
	}
	else												//(2.3)
	{
		cout << "\t---[ERROR: DUPLICATED ITEM]---" << endl;
		_func = false;
	}
	//}
	return _node;
}


template<typename T>
BinaryTreeNode<T>* AVLTree<T>::RecursivePointerInsert(BinaryTreeNode<T>* _node, T _data, bool& _func)
//----------------------------------------------------------------
//	(1)	 If node equals to 'nullptr', then create node dynamically,
//		 store the data, connect left and right node 'nullptr', and
//		 increase the length of tree.
//	(2)	 If node is not 'nullptr'
//	(2.1)If node's data is greater than input data,
//		- Compare with the left child node.
//		- If the node is empty, Take the (1) process.
//		- Otherwise, recursive the function with argument node->left.
//		- Keep the balance.
//	(2.2)If node's data is less than input data,
//		- Compare with the right child node.
//		- If the node is empty, Take the (1) process.
//		- Otherwise, recursive the function with argument node->right.
//		- Keep the balance.
//	(2.3)If node's data is equal to input data,
//		- Display the error message.
//----------------------------------------------------------------
{
	bool func;
	T target = _node->data;
	if (target->GetID() > _data->GetID())							//(2.1)
	{
		if (_node->left == nullptr)
		{
			BinaryTreeNode<T>* NewNode = new BinaryTreeNode<T>;
			NewNode->data = _data;
			NewNode->left = nullptr;
			NewNode->right = nullptr;
			_node->left = NewNode;
			this->m_Length++;
			_func = true;
		}
		else
		{
			RecursiveInsert(_node->left, _data, func);
		}
		_node = MakeBalance(_node);
	}
	else if (target->GetID() < _data->GetID())						//(2.2)
	{
		if (_node->right == nullptr)
		{
			BinaryTreeNode<T>* NewNode = new BinaryTreeNode<T>;
			NewNode->data = _data;
			NewNode->left = nullptr;
			NewNode->right = nullptr;
			_node->right = NewNode;
			this->m_Length++;
			_func = true;
		}
		else
		{
			RecursiveInsert(_node->right, _data, func);
		}
		_node = MakeBalance(_node);
	}
	else												//(2.3)
	{
		cout << "\t---[ERROR: DUPLICATED ITEM]---" << endl;
		_func = false;
	}
	//}
	return _node;
}


// Recursive function for deleting node.
template <typename T>
BinaryTreeNode<T>* AVLTree<T>::RecursiveDelete(BinaryTreeNode<T>* _node, T _data, bool& _func)
//----------------------------------------------------------------
//	(1)	 If Tree is empty, or there's no item in AVL Tree, stop function.
//	(2)	 If Tree's node is not nullptr,
//	(2.1)If target data is less than node's data,
//		- Recursively use delete function on left child node.
//		- After deleting item, make balance of AVL Tree.
//	(2.2)If target data is greater than node's data,
//		- Recursively use delete function on right child node.
//		- After deleting item, make balnace of AVL Tree.
//	(3)	 If target data is founded,
//	(3.1)If both of child nodes are empty, just delete node.
//	(3.2)If left child node is not empty, copy the node, and delete 
//		 parent node, and finally return the copied node.
//	(3.3)If right child node is not empty, copy the node, and delete 
//		 parent node, and finally return the copied node.
//	(3.4)If both of child nodes are not empty,
//		 Go to the left child and keep traversing to the right child.
//		 then, refer to the data in final right child node in target node.
//		 and make balnce of AVL Tree from the target node.
//----------------------------------------------------------------
{
	bool func;
	if (_node == nullptr)												// (1)
	{
		cout << "\t---[ERROR: NO TARGET DATA IN AVL TREE]---" << endl;
		_func = false;
	}
	else																//	(2)
	{
		if (_node->data > _data)										//(2.1)
		{
			_node->left = RecursiveDelete(_node->left, _data, func);
			_node = MakeBalance(_node);
			m_Length--;
			_func = true;
		}
		else if (_node->data < _data)									//(2.2)
		{
			_node->right = RecursiveDelete(_node->right, _data, func);
			_node = MakeBalance(_node);
			m_Length--;
			_func = true;
		}
		else															//	(3)
		{
			if (_node->left == nullptr && _node->right == nullptr)		//(3.1)
			{
				delete _node;
				_node = nullptr;
				m_Length--;
				_func = true;
				return _node;
			}
			else if (_node->left == nullptr && _node->right != nullptr) //(3.2)
			{
				BinaryTreeNode<T>* TempNode = _node->right;
				delete _node;
				m_Length--;
				_func = true;
				return TempNode;
			}
			else if (_node->left != nullptr && _node->right == nullptr) //(3.3)
			{
				BinaryTreeNode<T>* TempNode = _node->left;
				delete _node;
				m_Length--;
				_func = true;
				return TempNode;
			}
			else														//(3.4)
			{
				BinaryTreeNode<T>* dummy = _node->left;
				while (dummy->right != nullptr)
				{
					dummy = dummy->right;
				}
				_node->data = dummy->data;
				_node->left = RecursiveDelete(_node->left, _node->data, func);
				_node = MakeBalance(_node);
				m_Length--;
				_func = true;
				return _node;
			}
		}
	}
	return _node;
}


// Recursive function for deleting node.
template <typename T>
BinaryTreeNode<T>* AVLTree<T>::RecursivePointerDelete(BinaryTreeNode<T>* _node, T _data, bool& _func)
//----------------------------------------------------------------
//	(1)	 If Tree is empty, or there's no item in AVL Tree, stop function.
//	(2)	 If Tree's node is not nullptr,
//	(2.1)If target data is less than node's data,
//		- Recursively use delete function on left child node.
//		- After deleting item, make balance of AVL Tree.
//	(2.2)If target data is greater than node's data,
//		- Recursively use delete function on right child node.
//		- After deleting item, make balnace of AVL Tree.
//	(3)	 If target data is founded,
//	(3.1)If both of child nodes are empty, just delete node.
//	(3.2)If left child node is not empty, copy the node, and delete 
//		 parent node, and finally return the copied node.
//	(3.3)If right child node is not empty, copy the node, and delete 
//		 parent node, and finally return the copied node.
//	(3.4)If both of child nodes are not empty,
//		 Go to the left child and keep traversing to the right child.
//		 then, refer to the data in final right child node in target node.
//		 and make balnce of AVL Tree from the target node.
//----------------------------------------------------------------
{
	bool func;
	if (_node == nullptr)												// (1)
	{
		cout << "\t---[ERROR: NO TARGET DATA IN AVL TREE]---" << endl;
		_func = false;
	}
	else																//	(2)
	{
		T target = _node->data;
		
		if (target->GetID() > _data->GetID())							//(2.1) 
		{
			_node->left = RecursiveDelete(_node->left, _data, func);
			_node = MakeBalance(_node);
			m_Length--;
			_func = true;
		}
		else if (target->GetID() < _data->GetID())						//(2.2)
		{
			_node->right = RecursiveDelete(_node->right, _data, func);
			_node = MakeBalance(_node);
			m_Length--;
			_func = true;
		}
		else															//	(3)
		{
			if (_node->left == nullptr && _node->right == nullptr)		//(3.1)
			{
				delete _node;
				_node = nullptr;
				m_Length--;
				_func = true;
				return _node;
			}
			else if (_node->left == nullptr && _node->right != nullptr) //(3.2)
			{
				BinaryTreeNode<T>* TempNode = _node->right;
				delete _node;
				m_Length--;
				_func = true;
				return TempNode;
			}
			else if (_node->left != nullptr && _node->right == nullptr) //(3.3)
			{
				BinaryTreeNode<T>* TempNode = _node->left;
				delete _node;
				m_Length--;
				_func = true;
				return TempNode;
			}
			else														//(3.4)
			{
				BinaryTreeNode<T>* dummy = _node->left;
				while (dummy->right != nullptr)
				{
					dummy = dummy->right;
				}
				_node->data = dummy->data;
				_node->left = RecursiveDelete(_node->left, _node->data, func);
				_node = MakeBalance(_node);
				m_Length--;
				_func = true;
				return _node;
			}
		}
	}
	return _node;
}


// Balance the input node. 
template <typename T>
BinaryTreeNode<T>* AVLTree<T>::MakeBalance(BinaryTreeNode<T>* _node)
//----------------------------------------------------------------
//	(1) Declare balance factor variable and get value.
//	(2)	If Balance factor is over 1, it means that left sub tree is
//		weighted.
//		- if balance is over 0, then use Ratate_LL function to keep balance.
//		- otherwise, use Rotate_LR function to keep balance.
//	(3) If Balance factor is below -1, it means that right sub tree is
//		weighted.
//		- if balance is below 0, then use Rotate_RR function to keep balance.
//		- otherwise, use Rotate_RL function to keep balance.
//	(4)	No problem with balance.	
//----------------------------------------------------------------
{
	int Balance_factor = getBalance(_node);					//	(1)

	if (Balance_factor > 1)									//	(2)
	{
		if (getBalance(_node->left) > 0)
			_node = Rotate_LL(_node);
		else
			_node = Rotate_LR(_node);
	}
	else if (Balance_factor < -1)							//	(3)
	{
		if (getBalance(_node->right) < 0)
			_node = Rotate_RR(_node);
		else
			_node = Rotate_RL(_node);
	}
	return _node;											//	(4)
}