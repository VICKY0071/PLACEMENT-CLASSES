#include <bits/stdc++.h>

using namespace std;

// time : O(n log n) in best and worst case
int solve1(int * a, int n){
	sort(a, a + n);
	return (n % 2) ? a[n / 2] : (a[n / 2] + a[(n / 2) - 1]) / 2;
}

int getPivot(int * a, int lo, int hi){
	int randIdx = lo + (rand() % (hi - lo + 1));
	swap(a[lo], a[randIdx]);
	int i = lo;
	int j = hi;
	int pivot = a[lo];
	while(i < j){
		while(a[i] <= pivot)	i++;
		while(a[j] > pivot)	j--;
		if(i < j)	swap(a[i], a[j]);	
	}
	swap(a[j], a[lo]);
	return j;
}

// time is O(n) in best and average and very less chances of getting O(n log n).
void solve2(int * a, int lo, int hi, int n, int& x, int& y){
	if(lo <= hi){
		int pivot = getPivot(a, lo, hi);
		if(pivot == (n / 2)){
			y = a[pivot];
			if(x != -1)	return;
		}
		if(pivot == (n / 2) - 1){
			x = a[pivot];
			if(y != -1)	return;
		}
		if(pivot < (n / 2)){
			return solve2(a, pivot + 1, hi, n, x, y);
		}
		else	return solve2(a, lo, pivot - 1, n, x, y);
	}
	return;
}

int main(){
	int a[] = {2,5,5,7,1,2};
	int n = sizeof(a) / sizeof(a[0]);
	cout <<"Median by sorting method in O(n log n) time : "<<solve1(a, n)<<'\n';
	int x = -1, y = -1;
	solve2(a, 0, n - 1, n, x, y);
	cout <<"Median in O(n) time with very low probablity of getting O(n log n) time using quick select : ";
	if(n % 2){
		cout <<y<<'\n';
	}
	else{
		cout <<(x + y) / 2<<'\n';
	}
	return 0;
}