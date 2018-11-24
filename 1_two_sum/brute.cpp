#include <cstdio>
#include <stdexcept>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	for(int first = 0; first < nums.size(); first++) {
			for (int second = first + 1; second < nums.size(); second++) {
				if (target == nums[first] + nums[second]) {
					return vector<int>{first, second};
				}
			}
		}
		throw std::invalid_argument("Invalid input");
    }
};

int main() {
	auto il = {2, 8, 11, 15, 7};
	vector<int> input = vector<int>(il);
	int target = 9;
	Solution s;
	vector<int> result = s.twoSum(input, target);
	printf("[%d, %d]\n", result[0], result[1]);
	return 0;
}
