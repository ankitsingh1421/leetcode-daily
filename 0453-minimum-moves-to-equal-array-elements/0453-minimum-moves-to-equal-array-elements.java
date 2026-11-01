class Solution {
    public int minMoves(int[] nums) {
        int min = nums[0];
        for(int num : nums){
            min = Math.min(min,num);
        }
        int count = 0;
        for(int num : nums){
            count += num - min;
        }
        return count;
    }
}