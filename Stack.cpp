//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//
//template <class T>
//class Stack
//{
//private:
//	T* data;
//	int top;
//	const int MAX_SIZE;
//
//public:
//	Stack(const int MAX_SIZE = 0);
//	~Stack();
//
//	void push(T newItem); 
//	T pop(); 
//	T Top(); 
//	void clear();
//
//	bool isEmpty() const;
//	bool isFull() const; 
//	void showStructure() const;
//};
//
//
//template<typename T>
//Stack<T>::Stack(const int MAX_SIZE):MAX_SIZE(MAX_SIZE)
//{
//	top = -1;
//	data = new T[MAX_SIZE];
//}
//
//template<typename T>
//Stack<T>::~Stack()
//{
//	if (data != NULL)
//		delete[] data;
//	data = NULL;
//	top = -1;
//}
//
//template<typename T>
//void Stack<T>::push(T newItem)
//{
//	if (isFull() == false)
//		data[++top] = newItem;
//	else
//    	cout << "Stack is Full\n";
//}
//
//template<typename T>
//T Stack<T>::pop()
//{
//	if (isEmpty() == false)
//		return data[top--];
//	else
//		cout << "Stack is Empty\n";
//}
//
//template<typename T>
//T Stack<T>::Top()
//{
//	if(isEmpty()==false)
//	   return data[top];
//}
//
//template<typename T>
//void Stack<T>::clear()
//{
//	top = -1;
//}
//
//template<typename T>
//bool Stack<T>::isEmpty() const
//{
//	if (top == -1)
//		return true;
//	return false;
//}
//
//
//template<typename T>
//bool Stack<T>::isFull() const
//{
//	if (top == (MAX_SIZE - 1))
//		return true;
//	return false;
//}
//
//template<typename T>
//void Stack<T> :: showStructure() const
//{
//	cout << "top --> ";
//	for (int i = top; i >= 0; i--)
//		cout << setw(4)<< data[i]<<"\n\t";
//	cout << endl;
//
//}
//
//
//int main()
//{
//	int n = 5;
//	Stack<double> stack(n);
//	stack.push(5.0);
//	stack.push(6.5);
//	stack.showStructure();
//
//	stack.push(-3.0);
//	stack.push(-8.0);
//	stack.showStructure();
//	
//	stack.pop();
//	stack.pop();
//	stack.showStructure();
//
//	stack.clear();
//	stack.showStructure();
//}