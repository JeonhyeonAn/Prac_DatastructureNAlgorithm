
#include <iostream>
#include <forward_list>
#include <vector>

int main()
{
	/// <summary>
	/// vector
	/// </summary>
	/// <returns></returns>
	std::vector<std::string> vec = {
		"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
		"Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
		"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
	};

	auto it = vec.begin();// 상수 시간
	std::cout << "가장 최근 우승자: " << *it << std::endl;
	
	it += 8;
	std::cout << "8년 전 우승자: " << *it << std::endl;

	advance(it, -3);
	std::cout << "그 후 3년 뒤 우승자 " << *it << std::endl;




	/// <summary>
	/// forward_list
	/// </summary>
	/// <returns></returns>
	std::forward_list<std::string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	std::cout << "가장 최근 우승자: " << *it1 << std::endl;
	
	advance(it1, 5); // 선형 시간
	std::cout << "5년 전 우승자 " << *it1 << std::endl;

	// advance(it1, -2); forward_list 는 순방향 이동만 가능

}