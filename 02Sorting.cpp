#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n) {
	/*
	when we need to sort n elements we need to swap n-1 elements as the last
	element
	will automatcally come at the correct position
	for ex: to sort [   N    ] elements
	                [ 1 ][ N-1 ] so shifting n-1 elements will make array
	                sorted

	in each iteration one element is getting sorted and at the end of the array
	so we need n-i-1 iterations which is excluding the sorted part of the array

					for(n-1 times){
						for(0 to n-1-times)
					}
	*/

	for (int i = 0; i < n - 1; i++) {
		// repeated swapping of adjacent elements
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}


void insertion_sort(int a[], int n) {
	/*
	Considering the first element of array as sorted then iterating in the
	unsorted part of array which is 1 to n-1 and shifting each elemnt to
	its correct position in sorted part.
	ex:-
	arr = [4, 3, 1, 2];
	| 4 | 3 | 1 | 2 |
	  ^
	(sorted)
	now we will iterate from 1 to n-1 and in every iteration we will
	store the ith element in "current" variable.
	and will initialize an index prev = i - 1, which points to the previous
	element of the ith element
	whenever the previous element is greater than the current element we will
	shift previous element to the right side and decrement prev by 1.
	the loop will run untill all the previous elements greater than current
	are shifted or the value of previous is less than 0.
	now we will store the current eleemnt to its correct position after the loop
	which is (prev + 1)
	*/

	for (int i = 1; i < n; i++) {
		int current = a[i];
		int prev = i - 1;
		while (prev >= 0 && a[prev] > current) {
			a[prev + 1] = a[prev];
			prev--;
		}

		a[prev + 1] = current;

	}

}

void selection_sort(int a[], int n) {
	/*
	We selects ith element of the array and compare it to the i+1 to n elements
	of the array and whenever a smaller element is encountered swapping is done
	By doing this we are getting the smallest element of the array to the first
	position
	when i = 0, then the smallest element of the array comes at the 0th index
	when i = 1, then the smallest element in array part from 1 to n-1 comes at
				1st position which is the second smaalest in the whole array
	*/


	for (int i = 0; i < n - 1 ; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i])
				swap(a[j], a[i]);
		}
	}


	/*
	To avois multiple swappings performed inside the loop we can find the
	index of minimum element and then swap it with the current element
	outside the inner loop.
		for(int i = 0; i < n - 1; i++){
			int min_pos = i;
			for(int j = pos + 1; j < n; j++){
				if(a[j] < a[min_pos]) min_pos = j;
			}
			swap(a[min_pos], a[i]);
		}
	*/
}


void counting_sort(int a[], int n) {

	/*
	Finding the maximum element in the array by considering all the
	elements as positive
	this maximum elements defines the range of the count array
	*/

	int maximum = -1;
	for (int i = 0; i < n; i++)
		maximum = max(maximum, a[i]);

	// Dynamic Creation of the count array

	int *count = new int[maximum + 1];

	// Mapping the frequencies of the elements occuring in the array

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	// Updating the initial array with sorted values with the help of count

	int j = 0;   //index for iterating in initial array

	for (int i = 0; i < maximum + 1; i++) {
		/*
		Running a loop for range of frequencies of the element to update
		them in initial array
		*/
		while (count[i]--) {
			a[j] = i;
			j++;
		}
	}


}



int main() {
	int a[] = {2, 1, 5, 4, 1, 4, 2, 6, 8, 3, 1};
	int n = sizeof(a) / sizeof(a[0]);
	counting_sort(a, n);
	for (int x : a) {
		cout << x << " ";
	}
}