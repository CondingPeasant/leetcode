#include <cstdio>
#include <stdexcept>
#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map<int, int> map;

		for (int first = 0; first < nums.size(); first++) {
			map.emplace(nums[first], first);
			auto it = map.find(target - nums[first]);
			if (it != map.end() && it->second != first) {
				return vector<int>{it->second, first};
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
