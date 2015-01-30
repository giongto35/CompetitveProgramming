#include <vector>
#include <iostream>
#include <stdio.h>


using namespace std;

int c[] = {6,3,3,4,5,2,1,1,5,7,3};
vector<int> a(c, c + sizeof(c) / sizeof(int));

void quicksort(int l, int r) {
	if (l > r) return;
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
	quicksort(l, j);
	quicksort(i, r);
}
int main() {
	quicksort(0, a.size() - 1);
	for (int i = 0; i < a.size(); i++) cout<<a[i]<<' ';
}