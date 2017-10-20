/*
    在矩阵中，若某个值是0，那么把它的行和列全部清0

    注意，为了保证原本为0的却因为被清0而导致无法再次访问，
    所以在清0的时候只给非0的数清0，并标记visited为true
*/

# include <cstring>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool visited[matrix.size()][matrix[0].size()];
        memset(visited,false,sizeof(visited));
        if ( !matrix.size() ) return;
        for ( int i=0; i<matrix.size(); ++i )
            for ( int j=0; j<matrix[0].size(); ++j ){
                if ( !matrix[i][j] && !visited[i][j] ){
                    visited[i][j] = true;
                    for ( int k=0; k<matrix[0].size(); ++k ){
                        if ( matrix[i][k] ){
                            visited[i][k] = true;
                            matrix[i][k]=0;
                        }
                    }
                    for ( int k=0; k<matrix.size(); ++k ){
                        if ( matrix[k][j] ){
                            matrix[k][j]=0;
                            visited[k][j]=true;
                        }
                    }
                }
            }
    }
};