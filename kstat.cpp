#include <vector>
#include <iostream>
#include <stdio.h>


using namespace std;

int c[] = {6,3,3,4,5,2,1,1,5,7,3};
vector<int> a(c, c + sizeof(c) / sizeof(int));

int kth(int l, int r, int k) {

	int pivot = a[l + rand() % (r - l + 1)];
	int i = l;
	int j = r;
	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (k <= j) return kth(l, j, k);
	else if (k >= i) return kth(i, r, k);
	return pivot;
}
int main() {
	//for (int i = 0; i < a.size(); i++)
	cout<<kth(0, a.size() - 1, 7);

}