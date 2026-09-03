class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        bool hasOdd = false;
        bool hasEven = false;

        for (int x : nums1) {
            if (x % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        // Already same parity
        if (!hasOdd || !hasEven)
            return true;

        // Minimum element cannot be changed.
        // If minimum is odd, we can make all elements odd.
        if (mn % 2 == 1)
            return true;

        // Minimum is even and there is an odd element.
        return false;
    }
};