#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <iostream>

template <class T>
class Node 
{
	public:
		Node<T>(T value)
		:value(value)
		{}
		T getValue()
		{
			return value;
		}
		Node<T>* prev = NULL;
		Node<T>* next = NULL;
	private:
	 	const T value;
};

template <class T>
class LinkedList
{
	public:
		~LinkedList()
		{
			Node<T> *current = head;
			while(current){
				Node<T>* tmp = current->next;
    			delete(current);
				current = tmp;
			} 
		}
		
		void insert(T value)
		{
			if (!head){
				head = new Node<T>(value);
				tail = head;
			} else {
				auto node = new Node<T>(value);
				node->prev = tail;
				node->prev->next = node;
				tail = node;
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
		{
			Node<T> *current = list.head;
			while(current){
    			os << current->getValue() << " ";
				current = current->next;
			}
			// Node<T> *current = list.tail;
			// while(current){
    		// 	os << current->getValue() << " ";
			// 	current = current->prev;
			// }  			

    		return os;
		}
	
	private:
		Node<T>* head = NULL;
		Node<T>* tail = NULL;
};

#endif