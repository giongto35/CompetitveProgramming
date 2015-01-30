#include <bits/stdc++.h>

using namespace std;
class IntNode {
	public:
		IntNode() {}
		IntNode(int d, IntNode* n) {
			data = d;
			next = n;
		}

		IntNode* getNext() {
			return next;
		}

		int getData() {
			return data;
		}

		void setNext(IntNode* n) {
			next = n;
		}

	private:
		int data;
		IntNode *next;
};

void addToList(IntNode* &list, int n) {
	IntNode* current = list;
	if (current == NULL) {
		list = new IntNode(n, NULL);
		return;
	}

	while (current->getNext() != NULL) {
		current = current->getNext();
	}
	current->setNext(new IntNode(n, NULL));
}

void printList(IntNode *list3) {
while(list3 != NULL) {
cout<<list3->getData()<<"\t";
list3 = list3->getNext();
}
cout<<endl;
}

IntNode* mergeLists(IntNode* &list1, IntNode* &list2) {
    IntNode* dummyList3 = new IntNode(0, NULL);
    IntNode* list3 = dummyList3;
    while (list1 != NULL && list2 != NULL) {
        if (list1->getData() < list2->getData()) {
            list3->setNext(list1);
            list1 = list1->getNext();
        } else {
            list3->setNext(list2);
            list2 = list2->getNext();
        }
        list3 = list3->getNext();
    }

    if (list1 != NULL) list3->setNext(list1);
    if (list2 != NULL) list3->setNext(list2);

    return dummyList3->getNext();
}

int main() {
	IntNode *list1 = NULL;
	addToList(list1, 1);
	addToList(list1, 3);
	addToList(list1, 4);
	addToList(list1, 6);
	printList(list1);
	IntNode *list2 = NULL;
	addToList(list2, 2);
	addToList(list2, 3);
	addToList(list2, 7);
	printList(list2);
	IntNode* list3 = mergeLists(list1, list2);
	printList(list3);
	//Note that you might want to test your function with different cases to make sure the merging is correct
}
