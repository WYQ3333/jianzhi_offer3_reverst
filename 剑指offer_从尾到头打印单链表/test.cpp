#include<iostream>
#include<vector>

using namespace std;

struct ListNode {     
	int val;      
	struct ListNode *next;
    ListNode(int x)
		:val(x), 
		next(NULL) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> arrayList;
		int i = 0;
		ListNode *pcur = head;
		ListNode *pre = head;
		while (pcur!= nullptr){
			pcur = pcur->next;
			pre->next = head->next;
			head = pre;
			pre = pcur;
			arrayList[i++] = pre->val;
		}
		return arrayList;
	}
};


int main(){
	system("pause");
	return 0;
}