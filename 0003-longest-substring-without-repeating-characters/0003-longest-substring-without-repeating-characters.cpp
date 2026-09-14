#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> last_idx(128, -1);

        int length = 0;
        int left = 0;
        for (int right = 0; right < static_cast<int>(s.length()); ++right) {
            unsigned char ch = s[right];
            if (last_idx[ch] >= left) {
                left = last_idx[ch] + 1;
            }
            last_idx[ch] = right;
            length = std::max(length, right - left + 1);
        }

        return length;
    }
};