#ifndef SKIPLIST_H_
#define SKIPLIST_H_
#include<iostream>

template<class E, class K>
class SkipList;

template<class E, class K>
class SkipNode{
	friend SkipList<E, K>;
private:
	SkipNode(int size){
		link = new SkipNode<E, K>*[size];
	}
	~SkipNode() { delete[] link; }
	K key;
	E data;
	// һάָ������
	SkipNode<E, k> **link;
};

template<class E,class K>
class SkipList{
private:
	int Level();
	SkipNode<E, K>* SaveSearch(const K& k);
	// ������������
	int MaxLevel;
	// ��ǰ�ǿ����ĸ���
	int Levels;
	// ����ȷ������
	int CutOff;
	// һ���ܴ��keyֵ
	K TailKey;
	// ͷ�ڵ�ָ��
	SkipNode<E, K>* head;
	// β�ڵ�ָ��
	SkipNode<E, K>* tail;
	// ָ������
	SkipNode<E, K>** last;

public:
	SkipList(K Large, int MaxE = 10000, float p = 0.5);
	~SkipList();
	bool Search(const K&k, E&e)const;
	SkipList<E, K>& Insert(const E& e);
	SkipList<E, K>& Delete(const K&k, E&e);
};



#endif