/*
    给一个位置，返回能够流入大西洋和太平洋的点的集合
    Given the following 5x5 matrix:

      Pacific（太平洋） ~   ~   ~   ~   ~ 
          ~  1   2   2   3  (5) *
          ~  3   2   3  (4) (4) *
          ~  2   4  (5)  3   1  *
          ~ (6) (7)  1   4   5  *
          ~ (5)  1   1   2   4  *
              *   *   *   *   * Atlantic(大西洋)

    Return:
    [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

*/

# include <cstring>
class Solution {
public:    
    vector<pair<int, int>> ans;
    bool prac,atlc;
    bool visited[151][151];
    int xz[4][2] = {{0,1},{1,0},{-1,0},{0,-1}}; 
    void dfs(vector<vector<int>>& matrix,int i,int j){
        if ( prac && atlc ) return;
        int row = matrix.size();
        int col = matrix[0].size();
        int r,c;
        visited[i][j] = true;
        for ( int m=0; m<4; ++m){
            r = i + xz[m][0];
            c = j + xz[m][1];
            if ( r>=0 && c>=0 && r<row && c<col && !visited[r][c] && matrix[r][c]<=matrix[i][j] ){
                dfs(matrix,r,c);
            }else{
                if ( r<0 || c<0 ) prac = true;
                if ( r>=row || c>=col ) atlc = true;
            }
            if ( prac && atlc ){
                visited[i][j] = false;
                return;
            }
        }
        visited[i][j] = false;
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if ( !matrix.size() ) return ans;
        int r = matrix.size();
        int c = matrix[0].size();
        
        memset(visited,false,sizeof(visited));
        for ( int i=0; i<r; ++i ){
            for ( int j=0; j<c; ++j ){
                prac=false;
                atlc=false;
                dfs(matrix,i,j);
                if ( prac && atlc ) ans.push_back(make_pair(i,j));
            }
        }
        return ans;
    }
};
