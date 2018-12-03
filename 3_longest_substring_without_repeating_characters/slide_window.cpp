#include <cstdio>
#include <string>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) {
			return 0;
		}

		int longestStart = 0;
		int longestEnd = 1;
		int windowStart = 0;
		int windowEnd = 1;
        while (windowEnd < s.size()) {
            int index = isInCurrentSubstring(s, windowStart, windowEnd, s[windowEnd]);
#ifdef DEBUG
            printf("index = %d\n", index);
#endif
            if (index < 0) {
                windowEnd++;               
                if (windowEnd - windowStart > longestEnd - longestStart) {
                    longestStart = windowStart;
                    longestEnd = windowEnd;
                }
            } else {
                windowEnd++;               
                windowStart = index + 1;
            }
		 
#ifdef DEBUG
            printf("longestStart = %d, longestEnd = %d, windowStart = %d, windowEnd = %d\n",
                    longestStart, longestEnd, windowStart, windowEnd);
            printf("Longest substring: ");
            printSubstring(s, longestStart, longestEnd);
            printf("Window substring: ");
            printSubstring(s, windowStart, windowEnd);
#endif

        }

        return longestEnd - longestStart;
    }

private:
	int isInCurrentSubstring(const string& s, int startIndex, int endIndex, char c) {
		for (int i = startIndex; i < endIndex; i++) {
			if (s[i] == c) {
				return i;
			}
		}
		return -1;
	}
#ifdef DEBUG
    void printSubstring(const string s, int startIndex, int endIndex) {
        for (int i = startIndex; i < endIndex; i++) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
#endif
};

int main() {
	Solution s;
	const int testCaseNum = 4;
	string test[testCaseNum] = {"abcabcbb", "bbbbb", "pwwkew", ""};
	for (int i = 0; i < testCaseNum; i++) {
		printf("%s: %d\n", test[i].c_str(), s.lengthOfLongestSubstring(test[i]));
		printf("****************************************\n");
	}
	return 0;
}
