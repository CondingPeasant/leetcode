#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;

class Solution {
public:
    Solution () 
    : mSet(std::unordered_set<char>()){ }

    int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) {
			return 0;
		}

		int startIndex = 0;
		int endIndex = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j < s.size(); j++) {
				if (!addToSubString(s[j])) {
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
    bool addToSubString(char c) {
        if (mSet.find(c) != mSet.end()) {
            mSet.clear();
            return false;
        } else {
            mSet.insert(c);
            return true;
        }
    }

private:
    std::unordered_set<char> mSet;
};

int main() {
	Solution s;
    std::vector<string> testCase = {"abcabcbb", "bbbbb", "pwwkew", "", "abcdec"};
	for (int i = 0; i < testCase.size(); i++) {
		printf("%s: %d\n", testCase[i].c_str(), s.lengthOfLongestSubstring(testCase[i]));
	}
	return 0;
}
