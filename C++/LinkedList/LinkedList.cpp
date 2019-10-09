#include<iostream>
#include<string.h>
using namespace std;

template <class T>//Using generics to use linked list with any data type.

struct Node//Structure of Node of Linked List. 
{
	T value;
	//Add more variables here according to need.
	Node<T> *prev=NULL;//Pointer to previous element in the list
	Node<T> *next=NULL;//Pointer to next element in the list
};

template<class T>
class LinkedList//Blueprint of linked list class.
{
	private:
	
		Node<T> * head;
		Node<T> * tail;
		int len;
	
	public:
	
		LinkedList<T>()
		{
			head=NULL;
			tail=NULL;
			len=0;
		}

		bool isEmpty();
		int length();
		void display();
		void append_front(T value);
		void append_back(T value);
		void delete_element(T v);//Will delete first occurence of element containing v as value
		// Declare more methods here according to need
};

template<class T>
bool LinkedList<T>::isEmpty()//Check if list is empty or not
{
	return len==0;
}

template<class T>
int LinkedList<T>::length()//Returns length of linked list
{
	return len;
}

template<class T>
void LinkedList<T>::append_front(T value)//Append in head of linked list
{
	Node<T> *node=new Node<T>;
	node->value=value;

	if(len==0)
	{
		head=node;
		tail=node;
	}
	else
	{
		node->next=head;
		node->prev=NULL;
		head->prev=node;
		head=node;
		node=NULL;
	}
	len++;
}

template<class T>
void LinkedList<T>::append_back(T value)//Append in tail of linked list
{
	Node<T> *node=new Node<T>;
	node->value=value;

	if(len==0)
	{
		head=node;
		tail=node;
	}
	else
	{
		node->next=NULL;
		node->prev=tail;
		tail->next=node;
		tail=node;
		node=NULL;
	}
	len++;
}

template<class T>
void LinkedList<T>::display()//To display element in linked list
{
	Node<T> *node=new Node<T>;
	node=head;
	while(node->next!=NULL)
	{
		cout<<"-->"<<node->value;
		node=node->next;
	}
	cout<<"-->"<<node->value<<endl;
}

template<class T>
void LinkedList<T>::delete_element(T v)//Delete a node with value v from linked list(Only first occurence)
{
	Node<T> * temp=new Node<T>;
	temp=head;
	
	while(temp->next!=NULL)
	{
		if(temp->value==v)
		{
			if(temp==head)
			{
				head=head->next;
			}
			else
			{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
			}
			len--;
			free(temp);
			break;//Remove this break to remove only to first occurence from the front of linked list.
		}
		temp=temp->next;
	}
	if(temp->value==v)
	{	
		tail=temp->prev;
		temp->prev->next=NULL;
		len--;
		free(temp);
	}
}

int main()
{
	LinkedList<string> list;
	list.append_front("Aaa");
	list.append_front("Bbb");
	list.append_front("Ccc");
	list.append_front("Ddd");
	list.display();
	list.delete_element("Aaa");
	list.display();
	return 0;
}