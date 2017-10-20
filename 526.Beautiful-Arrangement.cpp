/*
    给一个数字N 要求在全排列的基础上满足 (i_th % i) == ( i % i_th ) == 0
    
    简单的回溯问题，用visted记录是否选中了1~N中的某个数，然后再判断：
    如果没被选中 并且满足这个条件，就选中它继续dfs 当当前idx超过N的时候，就给个数加以1
*/

# include <cstring>
class Solution {
public:
    int cnt=0;
    int arr[17];
    
    void helper(int N,int cur){
        if ( cur>N ){
            cnt++;
            return;
        }
        for ( int i=1; i<=N; ++i ){
            if ( !arr[i] && (!(i%cur) || !(cur%i)) ){
                arr[i] = 1;
                helper(N,cur+1);
                arr[i] = 0;
            }
        }
    }
    int countArrangement(int N) {
        memset(arr,0,sizeof(arr));
        helper(N,1);
        return cnt;
    }
};