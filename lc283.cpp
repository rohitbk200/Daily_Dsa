##ZEROS AT END
##2 POINTER APPROACH
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int i,j=-1,temp;
     for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
          j=i;
          break;
        } 
        if(j==-1) return ; 

     ##FIND THE INDEX OF FIRST ZERO
     }
     for(int i=j+1;i<nums.size();i++){
        if(nums[i]!=0){
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            j++;   
        }
     }
     return ;
    }

    ##SWAP WHENEVER I IS NOT ZERO
};

