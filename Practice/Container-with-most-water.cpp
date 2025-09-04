#include <iostream>
using namespace std;
#include <vector>

int maxArea(const std::vector<int>& height) {
    int maxwater = 0;
    int n = height.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int w = j - i;
            int minh = min(height[i], height[j]);
            int currentwater = w * minh;
            maxwater = std::max(maxwater, currentwater);
        }
    }
    return maxwater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max area: " << maxArea(height) << std::endl;
    return 0;
}