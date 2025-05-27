class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int PosInd=0,NegInd=1;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
        if(nums[i]>0){
            ans[PosInd]=nums[i];
            PosInd+=2;
        }
        else{
            ans[NegInd]=nums[i];
            NegInd+=2;

        }
    }
              return ans; 
    
}
};