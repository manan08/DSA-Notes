#include<bits/stdc++.h>
using namespace std;


// SPIRALISED MATRIX
vector <int> spiral_print(int matrix[][10], int r, int c) {

	vector <int> res;

	int start_row = 0;
	int start_col = 0;
	int end_row = r - 1;
	int end_col = c - 1;

	while (start_row <= end_row) {

		// start row
		for (int col = start_col; col <= end_col; col++) {
			res.push_back(matrix[start_row][col]);
		}

		// end column
		for (int row = start_col + 1; row <= end_row; row++) {
			res.push_back(matrix[row][end_col]);
		}

		// end row
		for (int col = end_col  - 1; col >= start_col; col--) {
			if (start_row >= end_row)
				break;
			res.push_back(matrix[end_row][col]);
		}

		// start column
		for (int row = end_row - 1; row >= start_row + 1; row--) {
			if (start_col >= end_col)
				break;
			res.push_back(matrix[row][start_col]);
		}

		start_row++;
		start_col++;
		end_row--;
		end_col--;
	}

	return res;

}

// ROW AND COLUMN WISE SORTED MATRIX SEARCH
pair <int, int> matrix_search(int matrix[][10], int n, int m, int item) {

	int i = 0;
	int j = m -  1;
	while (i < n and j >= 0) {
		if (item == matrix[i][j]) {
			return {i + 1, j + 1};
		}
		else if (item < matrix[i][j]) {
			j--;
		}
		else {
			i++;
		}
	}
	return { -1, -1};
}



int main() {

	// PREFIX SUM 2D ARRAY
	int arr[100][100] = {0};

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	cout << "Output Matrix\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	int preMatrix[100][100];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			preMatrix[i][j] = arr[i][j] + preMatrix[i - 1][j] + preMatrix[i][j - 1] - preMatrix[i - 1][j - 1];
		}
	}

	cout << "Output Prefix Sum Matrix\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << preMatrix[i][j] << " ";
		}
		cout << endl;
	}