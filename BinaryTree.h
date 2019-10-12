#ifndef BINARYTREE_H
#define BINARYTREE_H
#define ERR -1
#define OK 1

#include <iostream>

template <typename T>
class BinaryTree
{
private:
	T data;
	int type;
	BinaryTree<T>* left;
	BinaryTree<T>* right;
public:
	BinaryTree<T>(T data = NULL, int type = NULL, BinaryTree<T>* left = NULL, BinaryTree<T>* right = NULL)
	{
		this->data = data;
		this->type = type;
		this->left = left;
		this->right = right;
	}
	int addData(T data)
	{
		if (this->data != NULL)
			return ERR;
		this->data = data;
		return OK;
	}
	int addType(int type)
	{
		if (this->type != NULL)
			return ERR;
		this->type = type;
		return OK;
	}
	int addLeft(BinaryTree<T>* left)
	{
		if (this->left != NULL)
			return ERR;
		this->left = left;
		return OK;
	}
	int addRight(BinaryTree<T>* right)
	{
		if (this->right != NULL)
			return ERR;
		this->right = right;
		return OK;
	}
	T getData()
	{
		return data;
	}
	int getType()
	{
		return type;
	}
	BinaryTree<T>* getLeft()
	{
		return left;
	}
	BinaryTree<T>* getRight()
	{
		return right;
	}
	void printInOrder()
	{
		cout << this->getData() << " ";
		if (this->getLeft() != NULL)
			this->getLeft()->printInOrder();
		if (this->getRight() != NULL)
			this->getRight()->printInOrder();
	}
};
#endif
