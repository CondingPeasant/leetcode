#include <cstdio>
#include <stdexcept>
#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			map.emplace(nums[i], i);
		}

#ifdef DEBUG
		for (auto it = map.begin(); it != map.end(); it++) {
			printf("%d, %d\n", it->first, it->second);
		}
#endif

		for (int first = 0; first < nums.size(); first++) {
			auto it = map.find(target - nums[first]);
			if (it != map.end() && it->second != first) {
				return vector<int>{first, it->second};
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
