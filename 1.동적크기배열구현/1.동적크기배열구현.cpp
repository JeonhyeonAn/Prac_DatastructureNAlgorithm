// 1.동적크기배열구현.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>

#include <sstream>
#include <algorithm>

using namespace std;

template <size_t N>
void print(const std::array<int, N>& arr)
{
	for (auto ele : arr)
		cout << ele << ", ";

	cout << endl;
}

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
			data[i] = other[i];
	}

	T& operator[](int index)
	{
		return data[index];
	}
};





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







#pragma endregion


}

 
