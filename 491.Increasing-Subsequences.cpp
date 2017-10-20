/*
    求出所有非递减的序列，最少长度为2
    dfs+set
*/

# define Inf 0x3f3f3f3f
class Solution {
public:
    vector<vector<int>> ans; 
    set<vector<int> > set_;
    void dfs(vector<int>& nums, int l, int pre, int cnt, vector<int> tmp ){    
        if ( l==nums.size() ) return;
        for ( int i=l; i<nums.size(); ++i ){
            if ( pre<=nums[i] ){
                cnt++;
                tmp.push_back(nums[i]);
                if ( cnt>=2 ){
                    set_.insert(tmp);
                }
                dfs(nums,i+1,nums[i],cnt,tmp);
                while( i<nums.size() && nums[i]==nums[i+1]  ) i++;
                if ( i==nums.size()-1 ) return;
                cnt--;
                tmp.pop_back();
            }else  dfs(nums,i,-Inf,0,vector<int>());
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if ( !nums.size() ) return ans;
        dfs(nums,0,-Inf,0,vector<int>());
        for ( auto it=set_.begin(); it!=set_.end(); ++it  )
            ans.push_back(*it);
        return ans;
    }
};