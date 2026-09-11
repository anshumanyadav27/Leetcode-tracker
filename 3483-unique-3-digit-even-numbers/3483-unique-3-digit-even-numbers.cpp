#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNumbers;
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue; // Leading digit cannot be 0

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue;

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                    if (num % 2 == 0) {
                        uniqueNumbers.insert(num);
                    }
                }
            }
        }

        return uniqueNumbers.size(); // Correctly placed inside totalNumbers()
    }
};