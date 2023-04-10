// 실습 01.음악 재생 목록 구현하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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


	// 반복자 정의
	struct cir_list_it
	{
	private:
		node_ptr ptr;

	
	public:
		cir_list_it(node_ptr p) : ptr(p) {}

		// 원소 데이터 접근 함수
		T& operator*()
		{
			return *(ptr->data);
		}
		

		node_ptr get()
		{
			return ptr;
		}


		// ++ 연산자 (선행, 후행)
		cir_list_it& operator++()
		{
			ptr = ptr->next;
			return *this;
		}

		cir_list_it operator++(int)
		{
			cir_list_it it = *this;
			++(*this);
			return it;
		}

		// -- 연산자
		cir_list_it& operator--()
		{
			ptr = ptr->prev;
			return *this;
		}

		cir_list_it operator--(int)
		{
			cir_list_it it = *this;
			--(*this);
			return it;
		}
					
		// 반복자 비교 연산자 
		friend bool operator==(const cir_list_it& it1, const cir_list_it& i + 2)
		{
			return it1.ptr == it2.ptr;
		}
		friend bool operator!=(const cir_list_it& it1, const cir_list_it& i + 2)
		{
			return it1.ptr != it2.ptr;
		}


		// begin(), end() 
		cir_list_it begin()
		{
			return cir_list_it {head};
		}

		cir_list_it begin() const 
		{
			return ctir_list_it {head};
		}

		cir_list_it end()
		{
			return cir_list_it{ head->prev };
		}

		cir_list_it end() const
		{
			return cir_list_it { head->prev };
		}
	};
};




int main()
{


}

