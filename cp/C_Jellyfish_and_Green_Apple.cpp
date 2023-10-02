#include <iostream>
using namespace std;
void solvemerge(int arr[], int s, int e) {
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k];
        k++;
    }

    int leftindex = 0;
    int rightindex = 0;
    int mainindex = s;

    while (leftindex < len1 && rightindex < len2) {
        if (left[leftindex] < right[rightindex]) {
            arr[mainindex] = left[leftindex];
            mainindex++;
            leftindex++;
        } else {
            arr[mainindex] = right[rightindex];
            mainindex++;
            rightindex++;
        }
    }

    while (leftindex < len1) {
        arr[mainindex] = left[leftindex];
         mainindex++;
        leftindex++;
    }

    while (rightindex < len2) {
        arr[mainindex] = right[rightindex];
         mainindex ++;
        rightindex++;
    }
}

void solve(int arr[], int s, int e) {
    // base case..
    if (s >= e) {
        return;
    }
    int mid = s + (e - s) / 2;

    solve(arr, s, mid);

    solve(arr, mid + 1, e);

    solvemerge(arr, s, e);
}
int main() {
    int arr[5] = {3, 5, 1, 9, 7};
    int n = 5;
    int s = 0;
    int e = n - 1;
    solve(arr, s, e);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}