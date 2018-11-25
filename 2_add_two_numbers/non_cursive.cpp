/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdio>
#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printListNode(ListNode* l) {
	for ( ; NULL != l; l = l->next) {
		if (NULL != l->next) {
			printf("%d -> ", l->val);
		} else {
			printf("%d\n", l->val);
		}
	}
}

ListNode* buildList(vector<int> nums) {
	ListNode* result = NULL;
	ListNode* ptr = NULL;

	for (int i = 0; i < nums.size(); i ++) {
		if (0 == i) {
			result = new ListNode(nums[i]);
			ptr = result;
		} else {
			ptr->next = new ListNode(nums[i]);
			ptr = ptr->next;
		}
	}

	return result;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result = NULL;
		ListNode* ptr = NULL;
		int carry = 0;

		while (carry || NULL != l1 || NULL != l2) {
			ListNode* currentNode = addTwoNodes(l1, l2, carry);
#ifdef DEBUG
			printf("%d + %d = %d, carry = %d\n", getDigit(l1), getDigit(l2), getDigit(currentNode), carry);
#endif
			if (NULL == result) {
				result = currentNode;
				ptr = result;
			} else {
				ptr->next = currentNode;
				ptr = ptr->next;
			}

			l1 = NULL != l1 ? l1->next : l1;
			l2 = NULL != l2 ? l2->next : l2;
		}

		if (NULL != l1) {
			ptr->next = l1;
		} else {
			ptr->next = l2;
		}

		return result;
    }

private:
	ListNode* addTwoNodes(ListNode* n1, ListNode* n2, int& carry) {
		int digit = getDigit(n1) + getDigit(n2) + carry;
		if (digit > 9) {
			digit -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
		return new ListNode(digit);
	}


	int getDigit(ListNode* n) {
		if (NULL == n) {
			return 0;
		} else {
			return n->val;
		}
	}

};

int main() {
	/*
	vector<int> num1 = {1, 2, 4, 3};
	vector<int> num2 = {5, 6, 4};
	*/
	
	vector<int> num1 = {5};
	vector<int> num2 = {5};

	Solution s;
	ListNode* l1 = buildList(num1);
	ListNode* l2 = buildList(num2);

	printListNode(l1);
	printListNode(l2);

	printListNode(s.addTwoNumbers(l1, l2));
	return 0;
}
