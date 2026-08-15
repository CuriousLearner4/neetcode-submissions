class NumMatrix {
    vector<vector<int>> ps;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        ps.assign(rows,vector<int>(cols,0));
        for(int i = 0; i < rows;i++){
            for(int j = 0; j <cols;j++){
                ps[i][j] = matrix[i][j];
                if(i>0) ps[i][j] += ps[i-1][j];
                if(j>0) ps[i][j] += ps[i][j-1];
                if(i>0&&j>0) ps[i][j] -=ps[i-1][j-1];
            }
        }
    }
    
 int sumRegion(int row1, int col1, int row2, int col2) {
    int total = ps[row2][col2];
    int above = (row1 > 0) ? ps[row1 - 1][col2] : 0;
    int left  = (col1 > 0) ? ps[row2][col1 - 1] : 0;
    int topLeft = (row1 > 0 && col1 > 0) ? ps[row1 - 1][col1 - 1] : 0;

    return total - above - left + topLeft;
}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 [3,3,4]
 [8,14,18]
 [9,17,21]
  21-9-4+3=11
  ps[row2][col2]-ps[row2][col1-1]-ps[row1][col2]+ps[row-1][col-1]
 ]
 */