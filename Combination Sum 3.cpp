// Combination Sum III - https://leetcode.com/problems/combination-sum-iii/description/

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.
// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

// Constraints:

// 2 <= k <= 9
// 1 <= n <= 60

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;

void helper(vector<int>& temp, int k, int n, int curr) {
    if (n < 0 || temp.size() > k)
        return;
    if (n == 0 && temp.size() == k) {
        res.push_back(temp);
        return;
    }
    for (int i = curr; i <= 9; ++i) {
        temp.push_back(i);
        helper(temp, k, n - i, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> findAll(int k, int n) {
    vector<int> temp;
    helper(temp, k, n, 1);
    return res;
}

int main() {
    int k, n;
    cin>>k>>n;
    vector<vector<int>> sols = findAll(k, n);
    for (const auto& sol : sols) {
        for (int i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

