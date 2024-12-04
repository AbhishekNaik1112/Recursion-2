// 79. Word Search - https://leetcode.com/problems/word-search/description/
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 
// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.


#include<bits/stdc++.h>
using namespace std;

int m, n;

bool helper(vector<vector<char>>& board, string word, int i, int j, int index) {
    if (word.size() == index)
        return true;

    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index])
        return false;

    char temp = board[i][j];
    board[i][j] = '.';

    bool ans = helper(board, word, i - 1, j, index + 1) ||
               helper(board, word, i + 1, j, index + 1) ||
               helper(board, word, i, j - 1, index + 1) ||
               helper(board, word, i, j + 1, index + 1);

    board[i][j] = temp;

    return ans;
}

bool findAll(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0] && helper(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> board(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    cout << (findAll(board, word) ? "true" : "false") << endl;

    return 0;
}
