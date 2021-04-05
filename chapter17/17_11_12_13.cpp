#include <bitset>
#include <iostream>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;

template <size_t N>
class Quiz;

template <size_t M>
std::ostream &operator<<(std::ostream &os, const Quiz<M> &q);

template <size_t M>
size_t grade(const Quiz<M> &corAns, const Quiz<M> &stuAns);

template <size_t N>
class Quiz {
  friend std::ostream &operator<<<N>(std::ostream &, const Quiz<N> &);
  friend size_t grade<N>(const Quiz<N> &, const Quiz<N> &);

 public:
  Quiz() = default;
  Quiz(const std::string &s) : bitquiz(s) {}

  void update(std::pair<size_t, bool>);

 private:
  std::bitset<N> bitquiz;
};

template <size_t M>
std::ostream &operator<<(std::ostream &os, const Quiz<M> &q) {
  os << q.bitquiz;
  return os;
}

template <size_t M>
size_t grade(const Quiz<M> &corAns, const Quiz<M> &stuAns) {
  auto res = ~(stuAns.bitquiz ^ corAns.bitquiz);
  return res.count();
}

template <size_t N>
void Quiz<N>::update(std::pair<size_t, bool> p) {
  bitquiz.set(p.first, p.second);
}

int main() {
  // Ex17_11
  Quiz<10> quiz("1010101");
  std::cout << quiz << std::endl;

  // EX17_12
  quiz.update(std::make_pair(1, true));
  std::cout << quiz << std::endl;

  // Ex17_13
  std::string answer = "10011";
  std::string stu_answer = "11001";
  Quiz<5> ans(answer), stu_ans(stu_answer);
  std::cout << grade(ans, stu_ans) << std::endl;
  return 0;
}