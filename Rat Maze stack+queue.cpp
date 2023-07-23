#include <iostream>
#include <ctime>
#include<conio.h>
#include "myconsole.h"
#include "mygraphics.h"

using namespace std;

//Linkedlist basic class which is later used in stack class as wel in queue class
class linklist
{


	class node 

	{

	public:

		node* next;

		//rows coloum for maze 
		int rows;
		int colm;
		int dataa;
		friend class linklist;

		node()
		{
			next = nullptr;
			rows = 0;
			colm = 0;
			dataa = 0;
		}
		~node()
		{
			next = nullptr;
			rows = 0;
			colm = 0;
			dataa = 0;
		}
	};
private:
	node* head;
	// Head of linked list
public:
	//linking stack class
	friend class stack;
	linklist()
	{
		head = nullptr;
	}

	void insert_at_tail(int i, int j,int val)
	{
		if (head == nullptr)
		{
			node* n = new node;
			n->next = nullptr;
			n->rows = i;
			n->colm = j;
			n->dataa = val;

			head = n;
		}
		else if(head->next == nullptr)
		{
			node* n = new node;
			n->next = nullptr;
			n->rows = i;
			n->colm = j;
			n->dataa = val;

			head->next = n;
			
		}
		else
		{
			node* curr = head;
			while (curr-> next != nullptr)
			{
				curr = curr->next;
			}

			node* n = new node;
			n->next = nullptr;
			n->rows = i;
			n->colm = j;
			n->dataa = val;

			curr->next = n;

		}
	}

	void remove_From_Tail()
	{
		if (head != nullptr)
		{
			if (head->next == nullptr)
			{
				head = nullptr;
			}
			else
			{
				node* curr = head;
				node* temp = head;
				while (curr->next != nullptr)
				{
					curr = curr->next;
					if (curr->next != nullptr)
					{
						temp = temp->next;
					}
				}

				temp->next = nullptr;
				delete curr;

			}
		}
	}

	void print()
	{

		if(head != nullptr)
		{
			if (head->next == nullptr)
			{
				cout << "i is : " << head->rows << " j is : " << head->colm << " val is : " << head->dataa << endl;
			}
			else
			{
				node* curr = head;
				while (curr != nullptr)
				{
					cout << "i is : " << curr->rows << " j is : " << curr->colm << " val is : " << curr->dataa << endl;
					curr = curr->next;
				}
			}
		}
		
	}

	void top(int& i, int& j, int& val)
	{
		if (head != nullptr)
		{
			node* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			i = curr->rows;
			j = curr->colm;
			val = curr->dataa;
		}
	}

	bool is_emp()
	{
		if (head == nullptr)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	~linklist()
	{
		node* current = head;
		while (current != nullptr) 
		{
			node* next = current->next;
			delete current;
			current = next;
		}
		head = 0;
		cout << "\nGame END\n\n";;
	}
};


//The stack class
class stack
{
private:
	//aggregation
	linklist link;
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="i"></param>
	/// <param name="j"></param>
	/// <param name="val"></param>
	// Stack functions
	void push(int i,int j, int val)
	{
		link.insert_at_tail(i,j,val);
	}
	void pop()
	{
		link.remove_From_Tail();
	}
	void s_data(int& i, int& j, int& val)
	{
		link.top(i, j, val);
	}
	void show()
	{
		link.print();
	}
	bool is_emp()
	{
		if (link.is_emp())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};
class queue {
	int front;
	int rear;
	int* arr;
	int maxsize;
public:
	queue(int size) {
		maxsize = size;
		arr = new int[size];
		front = -1;
		rear = -1;
	}
	int atfront() {
		return front;
	}
	int atrear() {
		return rear;
	}
	void enqueue(int value) {
		if (isfull()) {
			return;
		}
		else if (isempty()) { //check if queue is empty
			front = 0;
			rear = 0;
			arr[rear] = value;
		}
		else {
			rear = (rear + 1) % maxsize;
			arr[rear] = value;
		}
	}
	void dequeue() {
		if (isempty())  // condition to check queue is empty  
		{
			cout << "\nQueue is empty\n";
		}
		else if (front == rear) //to check if there is only one element
		{
			cout << "\nThe dequeued element is: " << arr[front] << endl;
			front = -1;
			rear = -1;
		}
		else
		{
			cout << "\nThe dequeued element is: " << arr[front] << endl;
			front = (front + 1) % maxsize;
		}
	}
	void print() {
		if (front != -1 && rear != -1) {
			for (int i = front; i < maxsize; i++) {
				cout << arr[i] << endl;
			}
		}
	}
	bool isfull() {
		if ((rear + 1) % maxsize == front) { //check if queue is full
			cout << "queue is full\n";
			return 1;
		}
		return 0;
	}
	bool isempty() {
		if (front == -1 && rear == -1)
			return 1;
		return 0;
	}
};
// friend functions

stack s;
void show(int**& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void allocate(int **&arr, int size)
{
	srand(time(0));
	arr = new int*[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 2;
		}
		i++;
	}
}

void movement(int**& arr, int size, int i, int j,int x , int y)
{
	int val = 1;
	int flag = 0;
	int t_i = 0;
	int t_ii = 0;
	s.push(i, j, 1);
	while (arr[i][j] != arr[x][y] && s.is_emp() != 1)
	{

		if (j + 1 < size && arr[i][j + 1] != 1 && arr[i][j + 1] != 4 && arr[i][j + 1] != 2)
		{
						j++;
						s.push(i, j, 1);
						arr[i][j] = 4;
		}
		else if (i + 1 < size && arr[i + 1][j] != 1 && arr[i + 1][j] != 4 && arr[i + 1][j] != 2)
		{
					i++;
					s.push(i, j, 1);
					arr[i][j] = 4;
		}
		else if (j - 1 >= 0 && arr[i][j - 1] != 1 && arr[i][j - 1] != 4 && arr[i][j - 1] != 2)
		{
					j--;
					s.push(i, j, 1);
					arr[i][j] = 4;
		}
		else if (i - 1 >= 0 && arr[i - 1][j] != 1 && arr[i - 1][j] != 4 && arr[i - 1][j] != 2)
		{
					i--;
					s.push(i, j, 1);
					arr[i][j] = 4;
		}
		//else if (arr[i][j] == 4 && (arr[i - 1][j] != 1 || arr[i][j - 1] != 1 || arr[i + 1][j] != 1 || arr[i][j + 1] != 1) )
		//{

		//}
		else
		{
				arr[i][j] = val;
				s.pop();
				s.s_data(i, j, val);
			//arr[i][j] = val;
		}


		drawboard(arr, size);
		if (arr[i][j] == arr[x][y])
		{
			cout << "PATH FOUND : ";
			flag = 1;
			while (s.is_emp() != 1)
			{
				arr[i][j] = 2;
				s.s_data(i, j, val);
				s.pop();
				drawboard(arr, size);
			}
			break;
		}

		if (s.is_emp() == 1)
		{
			cout << "\nPATH NOT FOUND\n";
		}

		Sleep(30);
		//ClearScreen();
	}
}
void welcome()
{
	// welcome page
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t ~~~  RAT MAZE GAME BY FAZEEL KHALID 21L-7736 ~~~";
	cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tPRESS C TO CONTINUE\n\n";
	char x = _getch();
	if (x == 'c')
	{
		system("CLS");
		return;
	}
}

int main()
{
	maximized();

	welcome();


	cout << "ENTER THE SIZE OF MAZE (ixj) : ";
	int size = 0;
	cin >> size;
	int** arr = nullptr;
	allocate(arr,size);
	//show(arr,size);
	drawboard(arr, size);

	int i = 0, x = 0;
	int j = 0, y = 0;
	int flag = 0, flagi = 0;
	cout << "Enter starting Row i : ";
	cin >> i;
	cout << "Enter starting Coloum j : ";
	cin >> j;
	if (i > size || j > size || arr[i][j] == 1)
	{
		cout << " \nUnsuccessfull Path Due To  Hurdle Blue color \n\n";
		flag = 0;
	}
	else
	{
		arr[i][j] = 2;
		flag = 1;
	}

	cout << "Enter Maze Ending row i : ";
	cin >> x;
	cout << "Enter Maze Ending coloum j : ";
	cin >> y;
	if (i > size || j > size || arr[x][y] == 1)
	{
		cout << " \nUnsuccessfull Path Due to Hurdle\n\n";
		flagi = 0;
	}
	else
	{
		arr[x][y] = 3;
		flagi = 1;
	}

	drawboard(arr, size);
	//show(arr,size);

	movement(arr,size,i,j,x,y);



	return 0;
}