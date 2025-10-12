
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;  // bad, but just to enable copy&paste into leetcode editor

class Solution
{
 public:
  int removeDuplicates(vector<int>& nums)
  {
    assert(nums.size() >= 1);
    int k{};

    int j{1};
    for (size_t i{1U}; i < nums.size(); ++i)
    {
      if (nums.at(i) != nums.at(static_cast<size_t>(k)))
      {
        nums.at(static_cast<size_t>(++k)) = nums.at(i);
        j = 1;
      }
      else if (j < 2)
      {
        nums.at(static_cast<size_t>(++k)) = nums.at(i);
        ++j;
      }
    }

    return k + 1;
  }
};

int main(int, char**)
{
  vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};

  vector<int> solution_nums{0, 0, 1, 1, 2, 3, 3};
  int solution_k{7};

  const auto result_k{Solution{}.removeDuplicates(nums)};

  const bool result{
      equal(solution_nums.cbegin(), solution_nums.cend(), nums.cbegin()) &&
      (result_k == solution_k)};

  cout << "Result: " << boolalpha << result << '\n' << "nums1   ";
  for_each_n(nums.cbegin(), result_k, [](int val) { cout << " " << val; });
  cout << "\nsolution";
  for_each(solution_nums.cbegin(),
           solution_nums.cend(),
           [](int val) { cout << " " << val; });
  cout << '\n';

  return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
