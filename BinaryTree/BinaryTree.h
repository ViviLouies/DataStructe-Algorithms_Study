#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include<iostream>
#include"LinkedQueue.h"
using std::cout;

template<class T>
class BinaryTree;

template<class T>
class BinaryTreeNode{
	friend BinaryTree<T>;
	friend void Visit(BinaryTreeNode<T> *);
	friend void InOrder(BinaryTreeNode<T> *);
	friend void PreOrder(BinaryTreeNode<T> *);
	friend void Infix(BinaryTreeNode<T>*);
	friend void PostOrder(BinaryTreeNode<T> *);
	friend void LevelOrder(BinaryTreeNode<T> *);
private:
	T data;
	BinaryTreeNode<T>* LeftChild, *RightChild;
public:
	BinaryTreeNode(){
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T& e){
		data = e;
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T&e, BinaryTreeNode *l, BinaryTreeNode* r){
		data = e;
		LeftChild = l;
		RightChild = r;
	}
};

template<class T>
void PreOrder(BinaryTreeNode<T>* t){
	if (t){
		// ���ʸ��ڵ�
		Visit(t);
		// ǰ�����������
		PreOrder(t->LeftChild);
		// ǰ�����������
		PreOrder(t->RightChild);
	}
}

template<class T>
void InOrder(BinaryTreeNode<T>* t){
	if (t){
		// �������������
		InOrder(t->LeftChild);
		Visit(t);
		InOrder(t->RightChild);
	}
}

template<class T>
void PostOrder(BinaryTreeNode<T>* t){
	if (t){
		// �������������
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		Visit(t);
	}
}

template<class T>
void Infix(BinaryTreeNode<T> *t){
	// �����ȫ���ŵ���׺���ʽ
	if (t){
		cout << "(";
		// �������
		Infix(t->LeftChild);
		// ������
		cout << t->data;
		// �Ҳ�����
		Infix(t->RightChild);
		cout << ")";
	}
}

template<class T>
void LevelOrder(BinaryTreeNode<T>* t){
	// ��*t������
	LinkedQueue<BinaryTreeNode<T>*>	 Q;
	while (t){
		Visit(t);
		// ��t���Һ��ӷ������
		if (t->LeftChild)
			Q.Add(t->LeftChild);
		if (t->RightChild)
			Q.Add(t->RightChild);
		// ������һ���ڵ�
		try{
			Q.Delete(t);
		}
		catch (OutOfBounds){
			return;
		}
	}
}

/*��BinaryTree*/
template<class T>
class BinaryTree{
private:
	BinaryTreeNode<T> *root;	// ���ڵ�ָ��
	void PreOrder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t);
	void Inorder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t);
	void PostOrder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t);
public:
	BinaryTree(){ root = 0; }
	~BinaryTree(){};
	bool IsEmpty() const{
		return ((root) ? false : true);
	}
	bool Root(T& x)const;
	void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right);
	void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right);
	void PreOrder(void(*Visit)(BinaryTreeNode<T>*u)){
		PreOrder(Visit, root);
	}
	void Inorder(void(*Visit)(BinaryTreeNode<T>*u)){
		Inorder(Visit, root);
	}
	void PostOrder(void(*Visit)(BinaryTreeNode<T>*u)){
		PostOrder(Visit, root);
	}
	void LevelOrder(void(*Visit)(BinaryTreeNode<T>*u));

};

template<class T>
bool BinaryTree<T>::Root(T& x)const{
	// ȡ���ڵ��data�򣬷���x�����û���򷵻�false
	if (root){
		x = root->data;
		return true;
	}
else
	return false;
}

template<class T>
void BinaryTree<T>::MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right){
	// ��left��right��element�ϲ���һ������������Ҫ��left��right��this�����ǲ�ͬ������

	// ��������
	root = new BinaryTreeNode<T>(element, left.root, right.root);

	// ��ֹ����left��right
	left.root = right.root = 0;
}

template<class T>
void BinaryTree<T>::BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right){
	// left,right ��this�����ǲ�ͬ����
	if (!root)
		// ����
		throw BadInput();

	// �ֽ���
	element = root->data;
	left.root = root->LeftChild;
	right.root = root->RightChild;

	delete root;
	root = 0;
}

template<class T>
void BinaryTree<T>::PreOrder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t){
	// ǰ�����
	if (t){
		Visit(t);
		PreOrder(Visit, t->LeftChild);
		PreOrder(Visit, t->RightChild);
	}
}

template<class T>
void BinaryTree<T>::Inorder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t){
	// �������
	if (t){
		Inorder(Visit, t->LeftChild);
		Visit(t);
		Inorder(Visit, t->RightChild);
	}
}

template<class T>
void BinaryTree<T>::PostOrder(void(*Visit)(BinaryTreeNode<T>*u), BinaryTreeNode<T>* t){
	// �������
	if (t){
		PostOrder(Visit, t->LeftChild);
		PostOrder(Visit, t->RightChild);
		Visit(t);
	}
}

template<class T>
void BinaryTree<T>::LevelOrder(void(*Visit)(BinaryTreeNode<T>* u)){
	// ������
	LinkedQueue<BinaryTreeNode<T>*>Q;
	BinaryTreeNode<T> *t;
	t = root;
	while (t){
		Visit(t);
		// ��t���Һ��ӷ������
		if (t->LeftChild)
			Q.Add(t->LeftChild);
		if (t->RightChild)
			Q.Add(t->RightChild);
		// ������һ���ڵ�
		try{
			Q.Delete(t);
		}
		catch (OutOfBounds){
			return;
		}
	}
}

#endif