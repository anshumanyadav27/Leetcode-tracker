class Solution {
public:

    struct Node {
        int prod;
        array<int, 5> pref;

        Node() {
            prod = 1;
            pref.fill(0);
        }
    };

    int k;
    vector<Node> tree;

    Node mergeNode(const Node& left, const Node& right) {

        Node ans;

        // Complete product
        ans.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            ans.pref[r] += left.pref[r];
        }

        // Prefixes that enter the right part
        for (int r = 0; r < k; r++) {

            if (right.pref[r] == 0)
                continue;

            int rem = (left.prod * r) % k;

            ans.pref[rem] += right.pref[r];
        }

        return ans;
    }

    void build(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            tree[n + i].prod = nums[i] % k;

            tree[n + i].pref[nums[i] % k] = 1;
        }

        for (int i = n - 1; i >= 1; i--) {

            tree[i] = mergeNode(tree[2 * i],
                                tree[2 * i + 1]);
        }
    }

    void update(int n, int pos, int value) {

        pos += n;

        tree[pos] = Node();

        tree[pos].prod = value % k;
        tree[pos].pref[value % k] = 1;

        pos /= 2;

        while (pos >= 1) {

            tree[pos] = mergeNode(tree[2 * pos],
                                  tree[2 * pos + 1]);

            pos /= 2;
        }
    }

    Node query(int n, int l, int r) {

        // [l, r)
        Node leftResult;
        Node rightResult;

        l += n;
        r += n;

        while (l < r) {

            if (l % 2 == 1) {

                leftResult = mergeNode(leftResult,
                                       tree[l]);

                l++;
            }

            if (r % 2 == 1) {

                --r;

                rightResult = mergeNode(tree[r],
                                        rightResult);
            }

            l /= 2;
            r /= 2;
        }

        return mergeNode(leftResult, rightResult);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->k = k;

        int n = nums.size();

        tree.resize(2 * n);

        build(nums);

        vector<int> ans;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update nums[index]
            update(n, index, value);

            // Get nums[start ... n-1]
            Node temp = query(n, start, n);

            // Number of prefixes having remainder x
            ans.push_back(temp.pref[x]);
        }

        return ans;
    }
};