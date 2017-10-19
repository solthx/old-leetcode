/*
    用BFS每次找一圈自己周边的点，只要有一个0就直接break然后返回距离，
    如果周围全是1，那么距离就加1
*/
class Solution {
public:
    vector<vector<int>> ans;
    int xz[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    bool v[100][100];
    int bfs(vector<vector<int>>& matrix, int i,int j){
        queue<pair<int,int> > q;
        pair<int,int> cur;
        int cnt=1,r,c,flag=0;
        q.push(make_pair(i,j));
        while( !q.empty() && !flag ){
            int s=q.size();
            for ( int x=0; x<s; ++x ){ //扫描这一圈
                cur = q.front();
                q.pop();
                int min_ = 0x3f3f3f3f;
                for ( int y=0; y<4; ++y ){ //每一圈上某个位置的上下左右
                    r = cur.first+xz[y][0];
                    c = cur.second+xz[y][1];
                    if ( r>=0 && c>=0 && r<matrix.size() &&c<matrix[0].size()  ){
                        if ( matrix[r][c] )
                            q.push(make_pair(r,c));
                        else {
                            flag=1;
                            break;
                        }
                    }
                }
                if ( flag ) break;
            }
            if (!flag)  cnt++;
        }
        return cnt;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if ( !matrix.size() ) return ans;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int> > a(r,vector<int>(c,0));
        this->ans = a;
        for ( int i=0; i<r; ++i ){
            for ( int j=0; j<c; ++j ){
                if ( !matrix[i][j] ) ans[i][j]=0;
                else ans[i][j] = bfs(matrix,i,j);
            }
        }
        return ans;
    }
};