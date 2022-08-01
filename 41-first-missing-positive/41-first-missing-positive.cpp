class Solution {
public:
    int findMiss(vector<int> &nums, int lo, int hi)
    {   
        while(lo<hi)
        {
            // if next element is plus one the current element.
            if(nums[lo+1] == nums[lo] + 1 || nums[lo+1] == nums[lo])
                lo++;
            
            // if next element is not plus one the current element, then ans is plus one the current element.
            else if(nums[lo+1] != nums[lo] + 1 && nums[lo+1] != nums[lo])
                return (nums[lo] + 1);
        }
        
        // if no results found inside array. Case : nums[] = {1,2,0};
        return -1;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if(n==1 && nums[0] == 1)  // case : nums[] = {1};
            return 2;
        
        
        int start = 0;
        
        // reach the first element that is gretaer than 0.
        for(int i=0; i<n; i++)
        {
            start = i;
            if(nums[i] > 0)
                break;
        }
        
        int end = n-1;
        
        // if first element > 0 is not 1 then return 1.
        if(nums[start] != 1)
            return 1;
        
        int ans = findMiss(nums, start, end);
        
        // Case : nums[] = {1,2,0};
        if(ans == -1)
            return (nums[n-1] + 1);
        
        return ans;
    }
};