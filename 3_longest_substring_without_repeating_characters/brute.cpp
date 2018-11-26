#include <cstdio>
#include <string>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) {
			return 0;
		}

		int startIndex = 0;
		int endIndex = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j < s.size(); j++) {
				if (isInCurrentSubstring(s, i, j, s[j])) {
					break;
				} else {
					if (j - i > endIndex - startIndex) {
						startIndex = i;
						endIndex = j;
					}
				}
			}
		}

        return endIndex - startIndex + 1;
    }

private:
	bool isInCurrentSubstring(string& s, int startIndex, int endIndex, char c) {
		for (int i = startIndex; i < endIndex; i++) {
			if (s[i] == c) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution s;
	const int testCaseNum = 4;
	string test[testCaseNum] = {"abcabcbb", "bbbbb", "pwwkew", ""};
	for (int i = 0; i < testCaseNum; i++) {
		printf("%s: %d\n", test[i].c_str(), s.lengthOfLongestSubstring(test[i]));
	}
	return 0;
}
