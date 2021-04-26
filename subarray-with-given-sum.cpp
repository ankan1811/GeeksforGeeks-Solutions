/*
Find subarray with given sum | Set 1 (Nonnegative Numbers)
Difficulty Level : Medium
Last Updated : 10 Mar, 2021
Given an unsorted array of nonnegative integers, find a continuous subarray which adds to a given number. 
Examples : 
Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Ouptut: Sum found between indexes 2 and 4
Sum of elements between indices
2 and 4 is 20 + 3 + 10 = 33
Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Ouptut: Sum found between indexes 1 and 4
Sum of elements between indices
1 and 4 is 4 + 0 + 0 + 3 = 7
Input: arr[] = {1, 4}, sum = 0
Output: No subarray found
There is no subarray with 0 sum
There may be more than one subarrays with sum as the given sum. The following solutions print first such subarray. 
*/

/* An efficient program to print
subarray with sum as given sum */
#include <iostream>
using namespace std;

/* Returns true if the there is a subarray of
arr[] with a sum equal to 'sum' otherwise
returns false. Also, prints the result */
int subArraySum(int arr[], int n, int sum)
{
	/* Initialize curr_sum as value of
	first element and starting point as 0 */
	int curr_sum = arr[0], start = 0, i;

	/* Add elements one by one to curr_sum and
	if the curr_sum exceeds the sum,
	then remove starting element */
	for (i = 1; i <= n; i++) {
		// If curr_sum exceeds the sum,
		// then remove the starting elements
		while (curr_sum > sum && start < i - 1) {
			curr_sum = curr_sum - arr[start];
			start++;
		}

		// If curr_sum becomes equal to sum,
		// then return true
		if (curr_sum == sum) {
			cout << "Sum found between indexes "
				<< start << " and " << i - 1;
			return 1;
		}

		// Add this element to curr_sum
		if (i < n)
			curr_sum = curr_sum + arr[i];
	}

	// If we reach here, then no subarray
	cout << "No subarray found";
	return 0;
}

// Driver Code
int main()
{
	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 23;
	subArraySum(arr, n, sum);
	return 0;
}
