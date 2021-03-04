#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int t[MAX];

int merge(int * a, int lo, int mid, int hi){
    int inversions = 0;
    int i = lo, k = lo, j = mid + 1;
    while(i <= mid && j <= hi){
        if(a[i] < a[j]) t[k++] = a[i++];
        else{
            inversions += (mid - i + 1);
            t[k++] = a[j++];
        }
    }
    while(i <= mid) t[k++] = a[i++];
    while(j <= hi)  t[k++] = a[j++];
    for(int i = lo;i<=hi;i++)   a[i] = t[i];
    return inversions;
}

int mergeSort(int * a, int lo, int hi){
    int inversions = 0;
    if(lo < hi){
        int mid = lo + (hi - lo) / 2;
        inversions += mergeSort(a, lo, mid);
        inversions += mergeSort(a, mid + 1, hi);
        inversions += merge(a, lo, mid, hi);
    }
    return inversions;
}

int solve2(int * a, int n){
    int inversions = 0;
    for(int i = 0;i<n - 1;i++){
        for(int j = i + 1;j<n;j++){
            if(a[i] > a[j])    inversions++;
        }
    }
    return inversions;
}

int main(){
    int a[] = {8, 4, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    printf("The number of inversions %d\nThe number of inversions with unoptimized version : %d\n", mergeSort(a, 0, n - 1), solve2(a, n));
    return 0;
}