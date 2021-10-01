#include<bits/stdc++.h>
using namespace std;

// LINEAR SEARCH
int linear_search(int *a, int n, int item) {
    for (int i = 0; i < n; i++) {
        if (a[i] == item)
            return i;
    }
    return -1;
}

// BINARY SEARCH
int binary_search(int *a, int n, int item) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == item)
            return mid;
        else if (a[mid] > item)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// REVESRING AN ARRAY
void array_reverse(int *a, int n) {
    int s = 0;
    int e = n - 1;
    while (s < e) {
        swap(a[s], a[e]);
        s++;
        e--;
    }
}


// PRINT ALL PAIRS OF AN ARRAY
void printAllpairs(int *a, int n) {
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j++) {
            cout << a[i] << " " << a[j] << "   ";
        }
        cout << endl;
    }
}

void printSubarrays(int a[], int n) {
    for (int i = 0; i < n ; i++) {
        for (int j = i; j < n ; j++) {
            for (int k = i; k <= j; k++) {
                cout << a[k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// PRINT SUM OF EACH SUBARRAY AND RETURN MAXIMUM OF IT
int subarraysum(int a[], int n) {
    int sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            cout << sum << " ";
            max_sum = max(sum, max_sum);
        }
        cout << endl;
    }
    return max_sum;
}

// PREFIX SUM APPROACH : PRINT SUM OF SUBARRAY
int printSubarraysum(int a[], int n) {

    // CALCULATING PREFIX SUM

    /*taking one based indexing in prefix sum array so that no error occurs
    -1 index and eventually it will be 0th index in prefix sum array (1-1 = 0)*/

    int pre[n + 1] = {0};
    for (int i = 1; i <= n ; i++) {
        pre[i] = a[i - 1] + pre[i - 1];
    }

    int max_sum = INT_MIN;

    for (int i = 1; i <= n ; i++) {
        for (int j = i; j <= n; j++) {
            int sum = pre[j] - pre[i - 1];
            cout << sum << " ";
            max_sum = max(sum, max_sum);
        }
        cout << endl;
    }

    return max_sum;
}

// KADANS'S ALGORITHM TO FIND MAXIMUM SUB ARRAY SUM
int max_sunbarray_sum(int a[], int n) {
    int curr_sum = 0;
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++) {
        curr_sum += a[i];
        if (curr_sum < 0)
            curr_sum = 0;
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

int main() {
    int arr[] = {1, -5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = max_sunbarray_sum(arr, n);
    cout << "Maximum Sum: " << ans;


}