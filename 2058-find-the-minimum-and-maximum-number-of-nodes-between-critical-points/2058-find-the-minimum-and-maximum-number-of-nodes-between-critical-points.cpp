#include <vector>
#include <algorithm>
#include <climits>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        int first_cp = -1;
        int prev_cp = -1;
        int min_dist = INT_MAX;

        while (curr->next) {
            // Check for local maxima or local minima
            bool is_maxima = (curr->val > prev->val) && (curr->val > curr->next->val);
            bool is_minima = (curr->val < prev->val) && (curr->val < curr->next->val);

            if (is_maxima || is_minima) {
                if (first_cp == -1) {
                    first_cp = index;
                } else {
                    min_dist = std::min(min_dist, index - prev_cp);
                }
                prev_cp = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Fewer than 2 critical points found
        if (first_cp == -1 || prev_cp == first_cp) {
            return {-1, -1};
        }

        int max_dist = prev_cp - first_cp;
        return {min_dist, max_dist};
    }
};