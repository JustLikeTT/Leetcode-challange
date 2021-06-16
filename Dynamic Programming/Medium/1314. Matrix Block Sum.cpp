/**
Runtime: 16 ms, faster than 34.25% of C++ online submissions for Matrix Block Sum.
Memory Usage: 9.7 MB, less than 14.32% of C++ online submissions for Matrix Block Sum.

https://computersciencesource.wordpress.com/2010/09/03/computer-vision-the-integral-image/
https://en.wikipedia.org/wiki/Summed-area_table
*/

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
      int m = mat.size();
      int n = mat[0].size();
      vector<vector<int> > sum(m+1, vector<int>(n+1, 0));

      for(size_t row=0; row<m; row++){
          if(row == 0){
              sum[row+1][1] = mat[row][0];
          }
          else{
              sum[row+1][1] = sum[row][1] + mat[row][0];
          }


          for(size_t col=1; col<n; col++){
              if(row == 0){
                  sum[row+1][col+1] = sum[row+1][col] + mat[row][col];
              }
              else{
                  sum[row+1][col+1] = sum[row][col+1] + sum[row+1][col] - sum[row][col] + mat[row][col];
              }
          }
      }
      for(int row=0; row<m+1; row++){
          for(int col=0; col<n+1; col++){
              cout << setw(3) << sum[row][col];
          }
          cout << endl;
      }
      cout << endl;

      vector<vector<int> > blockSum(m, vector<int>(n, 0));
      int r1=0,c1=0,r2=0,c2=0;

      for(int row=0; row<m; row++){
          for(int col=0; col<n; col++){
              r1 = max(row-k, 0);
              c1 = max(col-k, 0);
              r2 = min(row+k+1, m);
              c2 = min(col+k+1, n);
              blockSum[row][col] = sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1];
              cout << setw(3) << blockSum[row][col];
          }
          cout << endl;
      }
      return blockSum;
  }
