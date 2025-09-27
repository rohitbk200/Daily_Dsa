class Solution {
public:
    long long cnt = 0;

    int reversePairs(vector<int>& nums) {
        if (nums.size() > 1) ms(nums, 0, (int)nums.size() - 1);
        return (int)cnt;
    }

    void countCross(const vector<int>& a, int low, int mid, int high) {
        int right = mid + 1;
        for (int left = low; left <= mid; ++left) {
            while (right <= high && (long long)a[left] > 2LL * a[right]) ++right;
            cnt += (right - (mid + 1));
        }
    }

    void merge(vector<int>& a, int low, int mid, int high) {
        vector<int> tmp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (a[left] <= a[right]) tmp.push_back(a[left++]);
            else                     tmp.push_back(a[right++]);
        }
        while (left <= mid)  tmp.push_back(a[left++]);
        while (right <= high) tmp.push_back(a[right++]);
        for (int i = low; i <= high; ++i) a[i] = tmp[i - low];
    }

    void ms(vector<int>& a, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        ms(a, low, mid);
        ms(a, mid + 1, high);
        countCross(a, low, mid, high);
        merge(a, low, mid, high);
    }
};
