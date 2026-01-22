#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int operations = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int targetIdx = -1;

            // 1. Find the leftmost pair with the minimum sum
            for (int i = 0; i < (int)nums.size() - 1; ++i) {
                // Use long long if sums could exceed INT_MAX
                int currentSum = nums[i] + nums[i + 1]; 
                if (currentSum < minSum) {
                    minSum = currentSum;
                    targetIdx = i;
                }
            }

            // 2. Replace the pair with their sum
            nums[targetIdx] = minSum;
            nums.erase(nums.begin() + targetIdx + 1);
            
            operations++;
        }

        return operations;
    }

private:
    bool isNonDecreasing(const std::vector<int>& nums) {
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }
};