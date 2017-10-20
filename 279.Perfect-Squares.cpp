/*
    给一个数，找出最少的“平方和为此数”的集合
    For example, given n = 12, return 3 because 12 = 4 + 4 + 4;
    given n = 13, return 2 because 13 = 4 + 9. 

    思路：
        对于给定的n , n一定能以 b*b+c的形式表示出来
        所以b从 1到b*b<n 遍历一遍找最小值(min(min_cur,dp[l*l]+dp[n-l*l]))。
        复杂度为nlogn 

    2017.10.20 11:10
*/

# include <cmath>
# include <cstring>
class Solution {
public:
    int cnt=1;
    int s[10000];
    
    void Init(int end){
        s[0]=0;s[1]=1;s[2]=2;s[3]=3;
        cnt = 4;
        for ( int i=4; i<=end; ++i  ){
            int t = (int)sqrt(i);
            if ( t*t == i ) s[cnt++] = 1;
            else{
                int l=1,min_=0x3f3f3f3f;
                while( l*l<i ){
                    min_ = min(min_,s[l*l]+s[i-l*l]);
                    l++;
                }
                s[cnt++] = min_;
            }
        }
    }
    
    int numSquares(int n) {
        memset(s,-1,sizeof(s));
        if ( s[n]!=-1 ) return s[n];
        Init(n);
        return s[n];
    }
};

