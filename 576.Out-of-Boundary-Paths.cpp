/*
    在一个矩阵里给一个初始位置，再给一个步数N，要求返回在步数内能够走出矩阵的走法
    状态公式：dp[step][(当前位置)] = dp[step-1][(上下左右)]

*/

class Solution {
public:
    uint dp[51][51][51]={0};
    int ans;
    int xz[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    void Init(int m,int n){
        int ni,r,c,cur;
        for ( ni=1; ni<51; ++ni )
            for ( r=0; r<m; r++ )
                for ( c=0; c<n; ++c ){
                    for ( int k=0; k<4; ++k ){
                        int r_ = r + xz[k][0];
                        int c_ = c + xz[k][1];
                        int ni_ = ni - 1 ;
                        //boundary
                        if ( (r_<0 || c_<0 || r_>=m || c_>=n) && ni_>=0 ) cur = 1;
                        //can't go out
                        else if ( ni_<0 ) cur = 0;
                        //inside
                        else cur = dp[ni_][r_][c_];
                        dp[ni][r][c] += cur;
                        dp[ni][r][c] = dp[ni][r][c]% 1000000007;
                    }
                }
    }
    int findPaths(int m, int n, int N, int i, int j) {
        Init(m,n);
        return dp[N][i][j] ;
    }
};

/* dfs 超时
int findPaths(int m, int n, int N, int i, int j) {
        int ans=0;
        if ( (i<0 || j<0 || i>=m || j>=n ) && N>=0 ) return 1;
        if ( N<0 ) return 0;
        for ( int k=0; k<4; ++k ){
            ans += findPaths(m,n,N-1,i+xz[k][0],j+xz[k][1]);
        }
        return ans;
    }
*/