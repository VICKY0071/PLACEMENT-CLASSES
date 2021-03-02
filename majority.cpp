#include <bits/stdc++.h>

using namespace std;

// time : O(n log n) space : O(1)
int solve1(int * a, int n){
	sort(a, a + n);
	int k = n / 2;
	for(int i = 0;i<=n - k;i++){
		if(a[i] == a[i + k - 1]){
			return a[i];
		}
	}
	return -1;
}

// time : O(n) space : O(n)
int solve2(int * a, int n){
	unordered_map<int, int> x;
	for(int i = 0;i<n;i++){
		x[a[i]]++;
	}
	for(auto i : x){
		if(i.second >= (n / 2)){
			return i.first;
		}
	}
	return -1;
}

int solve3(int * a, int n)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < n; i++) {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    int x = 0;
    for(int i = 0;i<n;i++){
    	if(a[maj_index] == a[i]){
    		x++;
    	}
    }
    return x > (n / 2);
}

int main(){
	int a[] = {1, 5, 5, 3, 4, 5, 1, 1, 1};
	int n = sizeof(a) / sizeof(a[0]);
	cout <<(solve1(a, n) == -1 ? "no\n" : "yes\n"); 
	cout <<(solve2(a, n) == -1 ? "no\n" : "yes\n"); 
	cout <<(solve3(a, n) == -1 ? "no\n" : "yes\n"); 
	return 0;
}