#include<iostream>
#include<ctime>
#include"xcept.h"
#include"Stack.h"
#include"llist.h"
#include"LinkedStack.h"
#include"Hanoi.h"

using std::cout;
using std::endl;
using std::cin;

void testStack(){
	Stack<int> stack1(10);
	cout << "show a empty stack\n";
	cout << stack1;
	for (int i = 0; i < 10; i++)
		stack1.Add(i + 2);
	cout << "stack is Full?\n";
	if (stack1.IsFull())
		cout << "Yes\n";
	else
		cout << "No\n";
	cout << "show Stack1\n";
	cout << stack1;
	
	int x;
	stack1.Delete(x);
	cout << "pop stack1, it is " << x << ".The remain elements are\n";
	cout << stack1;

}

void testLinkedStack(){
	LinkedStack<int> stack1;
	cout << "show a empty stack\n";
	cout << stack1;
	for (int i = 0; i < 10; i++)
		stack1.Add(i + 5);
	cout << "stack is Full?\n";
	if (stack1.IsFull())
		cout << "Yes\n";
	else
		cout << "No\n";
	cout << "show Stack1\n";
	cout << stack1;

	int x;
	stack1.Delete(x);
	cout << "pop stack1, it is " << x << ".The remain elements are\n";
	cout << stack1;

}

// �����ַ�������
const int MaxLength = 100;
// ����ƥ��
void PrintMatchedPairs(char* expr){
	Stack<int> s(MaxLength);
	int j, length = strlen(expr);
	for (int i = 1; i <= length; i++){
		// ������ɨ���ַ���
		if (expr[i - 1] == '(')
			// ջ����������ŵ�λ������ֵ
			s.Add(i);
		else if (expr[i - 1] == ')'){
			try{
				s.Delete(j);
				cout << j << " " << i << endl;
			}
			catch (OutOfBounds){
				cout << "No match for right parenthesis" << " at " << i << endl;
			}
		}	
	}
	// ��ջ��ʣ�µ�( ����δƥ���
	while (!s.IsEmpty()){
		s.Delete(j);
		cout << "No match for left parenthesis at " << j << endl;
	}
}

void testMathedParis(){
	// ��������ƥ��
	char expr[MaxLength];
	cout << "Type an expression of length at most " << MaxLength << endl;
	cin.getline(expr, MaxLength);
	cout << "The pairs of matching parentheses in " << endl;
	puts(expr);
	cout << "are" << endl;
	PrintMatchedPairs(expr);
}

// ��ŵ������,��n�����Ӵ���x�ƶ�����y���ɽ�������z
void TowersOfHanoi(int n, int x, int y, int z){
	if (n > 0){
		TowersOfHanoi(n - 1, x, z, y);
		cout << "Move top disk from tower " << x << " to top of tower " << y << endl;
		TowersOfHanoi(n - 1, z, y, x);
	}
}

void testTowersOfHanoi(){
	useTowersOfHanoi(2);
}

int main(){

	testTowersOfHanoi();

	system("pause");
	return 0;
}

