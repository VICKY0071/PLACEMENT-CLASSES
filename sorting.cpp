#include <bits/stdc++.h>

using namespace std;

int getPivot(int * a, int lo, int hi){
	int pivot = a[lo];
	int i = lo;
	int j = hi;
	while(i < j){
		while(i < hi && a[i] <= pivot)	i++;
		while(j > lo && a[j] > pivot)	j--;
		if(i < j)	swap(a[i], a[j]);
	}
	swap(a[j], a[lo]);
	return j;
}

void quickSort(int * a, int lo, int hi){
	if(lo < hi){
		int pivot = getPivot(a, lo, hi);
		quickSort(a, lo, pivot - 1);
		quickSort(a, pivot + 1, hi);
	}
}

void merge(int * a, int lo, int mid, int hi){
	int t[100000];
	int i = lo;
	int k = lo;
	int j = mid + 1;
	while(i <= mid && j <= hi){
		if(a[i] < a[j]){
			t[k++] = a[i++];
		}
		else{
			t[k++] = a[j++];
		}
	}
	while(i <= mid){
		t[k++] = a[i++];
	}
	while(j <= hi){
		t[k++] = a[j++];
	}
	for(int i = lo;i<=hi;i++)	a[i] = t[i];
}

void mergeSort(int * a, int lo, int hi){
	if(lo < hi){
		int mid = (lo + hi) / 2;
		mergeSort(a, lo, mid);
		mergeSort(a, mid + 1, hi);
		merge(a, lo, mid, hi);
	}
}

void selectionSort(int * a, int n){
	int pos;
	for(int i = 0;i<n - 1;i++){
		pos = i;
		for(int j = i + 1;j<n;j++){
			if(a[j] < a[pos]){
				pos = j;
			}
		}
		if(pos != i)	swap(a[i], a[pos]);
	}
}

void bubbleSort(int * a, int n){
	for(int i= 0;i<n;i++){
		for(int j = 0;j<n - i - 1;j++){
			if(a[j] > a[j + 1])	swap(a[j], a[j + 1]);
		}
	}
}

void insertionSort(int * a, int n){
	int key, j;
	for(int i = 1;i<n;i++){
		key = a[i];
		j = i - 1;
		while(j >= 0 && key < a[j]){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void display(int * a, int n){
	for(int i= 0;i<n;i++)	cout <<a[i]<<' ';
}

int main(){
	int a[] = {12,123,423,534,645,7,4568,5678,67,9};
	int n = sizeof(a) / sizeof(int);
	mergeSort(a, 0, n - 1);
	display(a, n);
	return 0;
}