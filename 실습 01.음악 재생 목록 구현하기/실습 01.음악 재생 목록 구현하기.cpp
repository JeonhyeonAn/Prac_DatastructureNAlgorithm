﻿// 실습 01.음악 재생 목록 구현하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


template <typename T>
struct cir_list_node
{
	T* data;
	cir_list_node* next;
	cir_list_node* prev;

	~cir_list_node()
	{
		delete data;
	}
};


template<typename T>
struct cir_list
{
public:
	using node = cir_list_node<T>;
	using node_ptr = node*;

private:
	node_ptr head;
	size_t n;
	
public:
	cir_list() : n(0)
	{
		head = new node { NULL, NULL, NULL };
		head->next = head;
		head->prev = head;
	}

	size_t size() const
	{
		return n;
	}


	void insert(const T& value)
	{
		node_ptr newNode { new T(value), NULL, NULL };
		n++;
		auto dummy = head->prev;
		dummy->next = newNode;
		newNode->prev = dummy;
		if (head == dummy)
		{
			dummy->next = head;
			newNode->next = dummy;
			head = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}



	void erase(const T& value)
	{
		auto cur = head, dummy = head->prev;
		while (cur != dummy)
		{
			if(*(cur->data) == value)
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				if(cur == head)
					head = head->next;
				delete cur;
				n--;
				return;
			}

			cur = cur->next;
		}
	}
};


int main()
{


}

