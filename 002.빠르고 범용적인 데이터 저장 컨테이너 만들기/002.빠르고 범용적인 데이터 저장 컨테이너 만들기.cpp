// 002.빠르고 범용적인 데이터 저장 컨테이너 만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <array>
#include <type_traits>



template<typename ... Args>
auto build_array(Args&&... args)->std::array<typename std::common_type<Args...>::type, sizeof...(Args) >
{
    using commonType = typename std::common_type<Args...>::type;    // 공통 타입
    return { std::forward<commonType>((Args&&)args)... };
}
// 더 유연하고 향상된 기능 필요하면 vector 이용


int main()
{
    auto data = build_array(1, 0u, 'a', 3.2f, false);
    //auto data2 = build_array(1, "Packt", 2.0);  // 공통타입 변환 불가 에러

    for (auto i : data)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

