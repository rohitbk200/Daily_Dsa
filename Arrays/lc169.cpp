class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,cm;
        for(int i=0;i<nums.size();i++){
           if(count==0){
            count=1;
            cm=nums[i];
           }
           else if(cm==nums[i])count++;
           else count--;

        }
        return cm;
    }
};