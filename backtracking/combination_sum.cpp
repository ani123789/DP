// User function template for C++

class Solution {
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    void backtrack(int start, vector<int>& arr, int target, vector<int>& comb, vector<vector<int>>& res){
        if(target==0){
            res.push_back(comb);
            return;
        }
        
        for(int i = start;i<arr.size();i++){
            if(arr[i] <= target){
                
                comb.push_back(arr[i]);
                backtrack(i,arr,target-arr[i],comb,res);
                
                comb.pop_back(); // this is used for pop the excedding elements so that we get ouptut
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(0,arr,target,comb,res);
        return res;
        
    }
};