// Check if there exists a subsequence with sum K - https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/0

// Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals the given target sum(k).


// Example:

// Input:  arr = [10,1,2,7,6,1,5], k = 8.
// Output:  Yes
// Explanation:  Subsequences like [2, 6], [1, 7] sum upto 8

// Input:  arr = [2,3,5,7,9], k = 100. 
// Output:  No
// Explanation:  No subsequence can sum upto 100
// Your Task:
// You don't need to read or print anything. Your task is to complete the boolean function checkSubsequenceSum() which takes N, arr and K as input parameter and returns true/false based on the whether any subsequence with sum K could be found.


// Expected Time Complexity: O(N * K).
// Expected Auxiliary Space: O(N * K).


// Constraints:
// 1 <= arr.length <= 2000.
// 1 <= arr[i] <= 1000.
// 1 <= target <= 2000.


#include <iostream>
#include <vector>
using namespace std;

bool helper(int n, int i, vector<int>& arr, int k) {
    if (k == 0) return true;
    if (i == n || k < 0) {
        return false;
    }
    bool l = false; 
    if (arr[i] <= k) {
        l = helper(n, i + 1, arr, k - arr[i]);
        if (l) return true;
    }
    bool r = helper(n, i + 1, arr, k);
    if (r) return true;
    return l || r;
}

bool findAll(int n, vector<int>& arr, int k) {
    int i = 0;
    return helper(n, i, arr, k);
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    if (findAll(n, arr, k)) {
        cout << "Yes"<< endl;
    } else {
        cout << "No"<< endl;
    }
    return 0;
}
