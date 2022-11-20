// 1.동적크기배열구현.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>

#include <sstream>
#include <algorithm>

using namespace std;

// template <size_t N>
// void print(const std::array<int, N>& arr)
// {
// 	for (auto ele : arr)
// 		cout << ele << ", ";
// 
// 	cout << endl;
// }

/// <summary>
/// Q
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class dynamic_array
{
	T* data;
	size_t n;

public:
	dynamic_array(int n)
	{
		this->n = n;
		data = new T[n];
	}


	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = other[i];
		}
	}

	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const
	{
		return data[index];
	}

	T& at(int index)
	{
		if (index < n)
			return data[index];
		throw "Index out of range";
	}




	size_t size() const
	{
		return n;
	}

	// 소멸자
	~dynamic_array()
	{
		delete[] data;	// 메모리 릭 방지
	}


	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	// + 연산   다시
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size() + arr2.size());
		std::copy(arr1.begin(), arr1.end(), result.begin());
		std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
	
		return result;
	}


	std::string to_string(const std::string& sep = ", ")
	{
		if (n == 0)
			return "";

		std::ostringstream os;
		os << data[0];

		for (int i = 1; i < n; i++)
			os << sep << data[i];

		return os.str();
	}
};



struct student
{
	std::string name;
	int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
	return (os << "[" << s.name << ", " << s.standard << "]");
}


int main()
{
#pragma region study
// 	array<int, 10> arr1;
// 
// 	arr1[0] = 1;
// 
// 	cout << "arr1 배열의 첫 번째 원소: " << arr1[0] << endl;
// 
// 
// 	//
// 	array<int, 4> arr2 = { 1, 2, 3, 4 };
// 	cout << "arr2 모든 원소: ";
// 
// 	for (int element : arr2)
// 	{
// 		cout << element << " ";
// 	}
// 	cout << endl;
// 
// 
// 
// 	// 배열 index 접근[]은 빠른 동작을 위해 인덱스가 배열 크기보다 작은지 검사 x, at() 을 이용하면 조금 느리지만 적절하게 예외처리 가능
// 	std::array<int, 4> arr3 = { 1, 2, 3, 4 };
// 
// 	try
// 	{
// 		cout << arr3.at(3) << endl;
// 		cout << arr3.at(4) << endl;
// 	}
// 	catch (const std::out_of_range& ex)
// 	{
// 		std::cerr << ex.what() << endl;
// 	}
// 
// 
// 	//
// 	array<int, 5> arr5 = { 1, 2, 3, 4, 5 };
// 	cout << "arr5: ";
// 	print(arr5);
// 
// 	array<int, 10> arr6 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
// 	cout << "arr6: ";
// 	print(arr6);
// 
// 
// 	// 
// 	for (auto it = arr6.begin(); it != arr6.end(); it++)
// 	{
// 		auto element = (*it);
// 		cout << element << " ";
// 	}
// 	cout << endl;
#pragma endregion


#pragma region Q
	// 학생정보 관리를 위한 간단한 응용 프로그램
	// input: 한반의 학생 수, 학생 정보
	// 학생데이터를 관리하기 위해 배열과 유사한 자료구조 사용
	// 다양한 크기 지원, 여러 반을 하나로 합치는 기능도 지원

	int nStudents;
	std::cout << "1반 학생 수를 입력하세요: ";
	std::cin >> nStudents;
	 
	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++)
	{
		std::string name;
		int standard;
		std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
		std::cin >> name >> standard;
		class1[i] = student{ name, standard };
	}


	// 배열 크기보다 큰 인덱스의 학생에 접근
	try
	{
		// 
		//class1[nStudents] = student{ "John", 8 };

		class1.at(nStudents) = student{ "John", 8 };
	}
	catch (const std::exception&)
	{
		std::cout << "예외 발생!" << std::endl;
	}
	catch (...)
	{
		std::cout << "예외 발생!" << std::endl;
	}


	// 깊은 복사
 	auto class2 = class1;
	std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;

	// 두 학급을 합ㄹ쳐서 새로운 큰 학급을 생성
	auto class3 = class1 + class2;
	std::cout << "1반과 2반을 합쳐 3반 생성: " << class3.to_string() << std::endl;

	return 0;

#pragma endregion


}

 
