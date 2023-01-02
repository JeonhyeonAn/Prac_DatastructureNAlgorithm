// 003. 연결 리스트에서 remove_if() 함수를 이용한 조건부 원소 삭제.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 선거 기간에 일부 시민들의 정보를 이용해 선거권이 없는 사람 가려냄
// 편의상 시민 정보는 이름과 나이만 사용
// 연결 리스트를 이용해 데이터 저장, remove_if() 함수를 사용해 특정 원소를 제거
// remove_if() 함수는 삭제할 원소 위치를 명시적으로 지정하는 것이 아니라 특정 조건에 해당하는 원소를 선별적으로 삭제할 때 사용


#include <iostream>
#include <iostream>
#include <forward_list>

struct citizen
{
    std::string name;
    int age;
};

std::ostream& operator<<(std::ostream& os, const citizen& c)
{
    return (os << "[" << c.name <<", " << c.age << "]");
}

int main()
{
  std::forward_list<citizen> citizens = {{"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}};

  auto citizens_copy = citizens;


  std::cout << "전체 시민들: " ;
  for(const auto &c : citizens)
  {
    std::cout << c << " ";
  }
   std::cout << std::endl;

  citizens.remove_if([](const citizen& c) {  return (c.age < 19);   });
   std::cout << "투표권이 있는 시민들: ";
   for (const auto &c : citizens)
   {
        std::cout << c << " ";
   }
   std::cout << std::endl;


   citizens_copy.remove_if([](const citizen &c) { return (c.age != 18); });
   std::cout << "내년에 투표권이 생기는 시민들: ";
   for (const auto& c : citizens_copy)
   {
        std::cout << c << " ";
   }
   std:: cout << std:: endl;
}
