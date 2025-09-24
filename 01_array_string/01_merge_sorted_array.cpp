// You are given two integer arrays nums1 and nums2, sorted in non-decreasing
// order, and two integers m and n, representing the number of elements in nums1
// and nums2 respectively. Merge nums1 and nums2 into a single array sorted in
// non-decreasing order. The final sorted array should not be returned by the
// function, but instead be stored inside the array nums1. To accommodate this,
// nums1 has a length of m + n, where the first m elements denote the elements
// that should be merged, and the last n elements are set to 0 and should be
// ignored. nums2 has a length of n.

// Example 1:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming
// from nums1.

// Example 2:
// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].

// Example 3:
// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there
// to ensure the merge result can fit in nums1.

// Constraints:
//     nums1.length == m + n
//     nums2.length == n
//     0 <= m, n <= 200
//     1 <= m + n <= 200
//     -10^9 <= nums1[i], nums2[j] <= 10^9

// Follow up: Can you come up with an algorithm that runs in O(m + n) time?

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;  // bad, but just to enable copy&paste into leetcode editor

class Solution
{
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
  {
    constexpr int kLowerBoundary{numeric_limits<int>::min()};
    size_t out{nums1.size() - 1U};

    while (m > 0 || n > 0)
    {
      const int nums1_value{m > 0 ? nums1[m - 1] : kLowerBoundary};
      const int nums2_value{n > 0 ? nums2[n - 1] : kLowerBoundary};

      if (nums1_value > nums2_value)
      {
        nums1[out--] = nums1_value;
        --m;
      }
      else
      {
        nums1[out--] = nums2_value;
        --n;
      }
    }
  }
};

int main(int, char**)
{
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  vector<int> nums2{2, 5, 6};
  int m{3};
  int n{3};

  vector<int> solution{1, 2, 2, 3, 5, 6};

  Solution{}.merge(nums1, m, nums2, n);

  const bool result{equal(nums1.cbegin(), nums1.cend(), solution.cbegin())};

  cout << "Result: " << boolalpha << result << '\n' << "nums1   ";
  for_each(nums1.cbegin(), nums1.cend(), [](int val) { cout << " " << val; });
  cout << "\nsolution";
  for_each(
      solution.cbegin(), solution.cend(), [](int val) { cout << " " << val; });
  cout << '\n';

  return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
