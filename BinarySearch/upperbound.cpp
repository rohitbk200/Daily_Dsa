#include <vector>
using namespace std;

int lowerBound(const vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;                           // default: not found → position n

    while (low <= high) {
        int mid = low + (high - low) / 2;  // avoid overflow
        if (arr[mid] > x) {               // maybe an answer
            ans = mid;
            high = mid - 1;                // look for a smaller index on the left
        } else {
            low = mid + 1;                 // look on the right
        }
    }
    return ans;
}
