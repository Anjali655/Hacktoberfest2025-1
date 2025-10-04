class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        // Skip duplicate elements for the first number
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        
        // Initialize two pointers
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            long long sum = (long long)nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                // Triplet found
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                
                // Skip duplicate elements for the second and third numbers
                while (j < k && nums[j] == nums[j-1]) {
                    j++;
                }
                while (j < k && nums[k] == nums[k+1]) {
                    k--;
                }
            }
        }
    }
    
    return ans;
    }
};
