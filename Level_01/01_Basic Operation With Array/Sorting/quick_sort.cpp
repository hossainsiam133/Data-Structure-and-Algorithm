#include <bits/stdc++.h>
using namespace std;

// Function to find pivot element for quicksort
int pivot(int a[], int low, int high)
{
	int i, j, t;
	int piv = a[high];

	// Partitioning the array
	for (i = low - 1, j = low; j < high; j++)
	{
		if (a[j] < piv)
		{
			i++;
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	}

	t = a[high];
	a[high] = a[i + 1];
	a[i + 1] = t;

	return i + 1;
}

// Recursive function to perform quicksort
void quick(int a[], int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int p = pivot(a, low, high);

	quick(a, low, p - 1);
	quick(a, p + 1, high);
}

int main()
{
	int n = 12;
	int a[n] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
	int b[n];		   // Copy array
	copy(a, a + n, b); // Copying array

	quick(a, 0, n - 1);

	cout << "Before Sorting\t\tAfter Quick Sort: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "] = " << b[i] << "\t\t"
			 << "A[" << i << "] = " << a[i] << endl;
	}

	return 0;
}
