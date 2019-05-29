#include "test.h"

std::tuple<char, int, bool> mytuple()
{
    char a = 'a';
    int i = 123;
    bool b = true;
    return std::make_tuple(a, i, b);
}

int main() {
  std::cout<<"Test: hello world!"<<std::endl;
  auto var=5;
  std::cout<<"var="<<var<<std::endl;
  int my_array[5] = {1, 2, 3, 4, 5};
  for (const auto& x : my_array) {
    std::cout<<"x*2="<<x*2<<std::endl;
  }
  //auto integer_literal = 1'000'000; // works only in C++14
  //auto [a, i, b] = mytuple(); // works only in C++17
  //
  //
  return 0;
}
