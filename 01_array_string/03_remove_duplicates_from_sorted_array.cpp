// Given an integer array nums sorted in non-decreasing order, remove the
// duplicates in-place such that each unique element appears only once. The
// relative order of the elements should be kept the same. Then return the
// number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you
// need to do the following things:
//     Change the array nums such that the first k elements of nums contain the
//     unique elements in the order they were present in nums initially. The
//     remaining elements of nums are not important as well as the size of nums.
//     Return k.

// Custom Judge:
// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }

// If all assertions pass, then your solution will be accepted.

// Example:
// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements
// of nums being 1 and 2 respectively. It does not matter what you leave beyond
// the returned k (hence they are underscores).

// Constraints:
//     1 <= nums.length <= 3 * 10^4
//     -100 <= nums[i] <= 100
//     nums is sorted in non-decreasing order.

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

    for (size_t i{1U}; i < nums.size(); ++i)
    {
      if (nums.at(i) != nums.at(static_cast<size_t>(k)))
      {
        nums.at(static_cast<size_t>(++k)) = nums.at(i);
      }
    }

    return k + 1;
  }
};

int main(int, char**)
{
  vector<int> nums{1, 1, 2};

  vector<int> solution_nums{1, 2};
  int solution_k{2};

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
