// 1498. Number of Subsequences That Satisfy the Given Sum Condition - https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

// Example 1:

// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)
// Example 2:

// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
// Example 3:

// Input: nums = [2,3,3,4,6,7], target = 12
// Output: 61
// Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
// Number of valid subsequences (63 - 2 = 61).
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= target <= 106


// GIVES TLE

#include <bits/stdc++.h>
using namespace std;

int findAll(int index, int n, int sum, int target, vector<int>& nums, vector<int>& subseq) {
    if (index == n) {
        if (!subseq.empty()) {
            int minEl = *min_element(subseq.begin(), subseq.end());
            int maxEl = *max_element(subseq.begin(), subseq.end());
            if (maxEl + minEl <= target) 
                return 1;
        }
        return 0;
    }

    subseq.push_back(nums[index]);
    sum += nums[index];
    int lSum = findAll(index + 1, n, sum, target, nums, subseq);
    subseq.pop_back();
    sum -= nums[index];
    int rSum = findAll(index + 1, n, sum, target, nums, subseq);

    return lSum + rSum;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> subseq;
    cout << findAll(0, n, 0, target, nums, subseq) << endl;

    return 0;
}
