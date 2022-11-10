// 1.동적크기배열구현.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>


using namespace std;

template <size_t N>
void print(const std::array<int, N>& arr)
{
	for (auto ele : arr)
		cout << ele << ", ";

	cout << endl;
}

int main()
{

	array<int, 10> arr1;

	arr1[0] = 1;

	cout << "arr1 배열의 첫 번째 원소: " << arr1[0] << endl;


	//
	array<int, 4> arr2 = { 1, 2, 3, 4 };
	cout << "arr2 모든 원소: ";

	for (int element : arr2)
	{
		cout << element << " ";
	}
	cout << endl;



	// 배열 index 접근[]은 빠른 동작을 위해 인덱스가 배열 크기보다 작은지 검사 x, at() 을 이용하면 조금 느리지만 적절하게 예외처리 가능
	std::array<int, 4> arr3 = { 1, 2, 3, 4 };

	try
	{
		cout << arr3.at(3) << endl;
		cout << arr3.at(4) << endl;
	}
	catch (const std::out_of_range& ex)
	{
		std::cerr << ex.what() << endl;
	}


	//
	array<int, 5> arr5 = { 1, 2, 3, 4, 5 };
	cout << "arr5: ";
	print(arr5);

	array<int, 10> arr6 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "arr6: ";
	print(arr6);
}

 
