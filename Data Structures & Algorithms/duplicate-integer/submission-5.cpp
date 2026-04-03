class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //bool basic = false;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        //vector<int> nance(n,0);
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[i+1]){
                return true; 
            }
            

        }
        return false; 
    }
};
