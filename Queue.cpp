//#include<iostream>
//using namespace std;
//
//template <class T>
//class Queue
//{
//private:
//	T* data;
//	int front;
//	int rear;
//	const int MAX_SIZE;
//
//public:
//	Queue(const int MAX_SIZE = 5);
//	~Queue();
//
//	void Enqueue(T x); 
//	T Dequeue(); 
//	void clear();
//
//	bool IsEmpty(void);
//	bool IsFull(void); 
//	void showStructure(void);
//};
//
//
//template <typename T>
//Queue<T>::Queue(const int MAX_SIZE): MAX_SIZE(MAX_SIZE)
//{
//	data = new T[MAX_SIZE];
//	front = -1;
//	rear = -1;
//}
//
//
//template <typename T>
//Queue<T>::~Queue()
//{
//	if (data != NULL)
//		delete []data;
//	front = -1;
//	rear = 1;
//}
//
//
//template <typename T>
//void Queue<T>::Enqueue(T x)
//{
//	if (IsFull() == false)
//	{
//		rear = (rear + 1) % MAX_SIZE;
//		data[rear] = x;
//		if (IsEmpty() == true)
//			front = 0;
//	}
//	else
//	    cout << "Queue Is Full\n";
//}
//
//template <typename T>
//T Queue<T>::Dequeue()
//{
//	if (IsEmpty() == false)
//	{
//		T temp = data[front];
//		front = (front + 1) % MAX_SIZE;
//		return temp;
//	}
//	cout << "Queue Is Empty\n";
//	return 0;
//}
//
//template <typename T>
//void Queue<T>::clear()
//{
//	front = -1;
//	rear = -1;
//}
//
//template<typename T>
//bool Queue<T>::IsEmpty()
//{
//	if (front == -1 )
//		return true;
//	return false;
//}
//
//template<typename T>
//bool Queue<T>::IsFull()
//{
//	if (rear == (front - 1))
//		return true;
//	return false;
//}
//
//
//template<typename T>
//void Queue<T>::showStructure()
//{
//	cout << "front -->";
//	for (int i = front;; i = ((i + 1) % MAX_SIZE))
//	{
//		cout << "\t" << data[i] ;
//		if (i == rear)
//		{
//			cout << "\t <-- rear\n";
//			break;
//		}
//		cout << "\n\t";
//	}
//	cout << endl;
//}
//
//
//int main()
//{
//	Queue<double> queue(6);
//	queue.Enqueue(5.0);
//	queue.Enqueue(6.5);
//	queue.showStructure();
//	
//	queue.Enqueue(-3.0);
//	queue.Enqueue(-8.0);
//	queue.showStructure();
//
//	queue.Dequeue();
//	queue.Dequeue();
//	queue.showStructure();
//
//	queue.clear();
//
//	queue.Enqueue(1);
//	queue.Enqueue(2);
//	queue.Enqueue(3);
//	queue.Enqueue(4);
//	queue.Enqueue(5);
//	queue.Enqueue(6);
//	queue.showStructure();
//
//	queue.Dequeue();
//	queue.Dequeue();
//	queue.showStructure();
//
//	queue.Enqueue(7);
//	queue.Enqueue(8);
//	queue.showStructure();
//}
//
