// C++ Solution

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;                // Next position for a 0 (red)
        int mid = 0;                // Current element index
        int high = nums.size() - 1;   // Next position for a 2 (blue)
        
        // Process until mid pointer passes the high pointer.
        while (mid <= high) {
            if (nums[mid] == 0) {          // If the element is red
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {   // If the element is white
                mid++;
            } else {                       // If the element is blue
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
