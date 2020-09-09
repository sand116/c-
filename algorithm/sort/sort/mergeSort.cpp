#include <iostream>
using namespace std;
int *sorted;
void merge(int *unsorted, int first,int mid, int end) {
	int cnt = first;
	int i = first;
	int j = mid;
	while (i < mid && j < end) {
		if (unsorted[i] <= unsorted[j]){
			sorted[cnt] = unsorted[i];
			i++;
			cnt++;
			}
		else {
			sorted[cnt] = unsorted[j];
			j++;
			cnt++;
		}
	}
	if (j == end) {
		while (i < j) {
			sorted[cnt] = unsorted[i];
			cnt++;
			i++;
		}
	}
	else if(i==mid){
		while (j < end) {
			sorted[cnt] = unsorted[j];
			cnt++;
			j++;
		}
	}
	for (int i = first; i < end; i++) {
		unsorted[i] = sorted[i];
	}
}
void mergeSort(int *unsorted, int first, int end) {
	int mid = (end+first)/2;
	int cnt = 0;
	//end- first 는 배열의 길이고 아래조건문은 배열이 2개 이상일때만 작동한다는 의미이다
	if (first < end) {
		mergeSort(unsorted, first, mid);// 동적할당한 배열을 반환
		mergeSort(unsorted, mid, end);
		merge(unsorted,first,mid, end);
	}
	return;
}
int main(void) {
	int unsorted[10] = { 0,100,3,2,67,5,4,8,9,22 };
	sorted = new int[10];
	mergeSort(unsorted,0,10);
	for (int i = 0; i < 10 ; i++) {
		cout << unsorted[i] << endl;
	}
	return 0;
}