//PROBLEM LINK
//https://leetcode.com/problems/greatest-sum-divisible-by-three/

//DO NOT SUBMIT THIS CODE, THIS IS TO LOOK, IF YOU GET STUCK SOMEWHERE

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int arr[2][3];
        arr[0][0] = arr[0][1] = arr[0][2] = 0;
        arr[1][0] = arr[1][1] = arr[1][2] = 0;

        for(int i=0;i<n;i++){

            for(int j=0;j<3;j++){
                arr[1][(arr[0][j] + nums[i])%3] = max(arr[1][(arr[0][j] + nums[i])%3], arr[0][j] + nums[i]);
            }

            for(int j=0;j<3;j++){
                arr[0][j] = arr[1][j];
            }
        }
        return arr[1][0];
    }
};
