class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=bsearch(0,nums.size()-1,nums,target);
        return ans;
        
    }
    int bsearch(int low,int high,vector<int>& nums,int target){
        if(high<low)return-1;
        int mid=(high+low)/2;
        if(nums[mid]==target)return mid;
        if (nums[mid] < target)
            return bsearch(mid + 1, high, nums, target);   // go right
        else
            return bsearch(low, mid - 1, nums, target);    // go left
    }
};
