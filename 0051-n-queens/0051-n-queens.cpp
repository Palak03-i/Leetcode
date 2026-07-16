class Solution {
public:
    vector<vector<string>> ans; 
    vector<int> x;
    bool place(int k, int i) {
        for (int j = 0; j < k; j++) {
            if (x[j] == i)
                return false;

            if (abs(k - j) == abs(i - x[j]))
                return false;
        }
        return true;
    }
        void NQueen(int k, int n) {
        for (int i = 0; i < n; i++) {

            if (place(k, i)) {

                x[k] = i;

                if (k == n - 1) {

                    vector<string> board(n, string(n, '.'));

                    for (int r = 0; r < n; r++)
                        board[r][x[r]] = 'Q';

                    ans.push_back(board);
                }
                else {
                    NQueen(k + 1, n);
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        x.resize(n);
        NQueen(0, n);
        return ans;
    }
};