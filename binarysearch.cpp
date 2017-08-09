#include <stdio.h>
using namespace std;

//Recursive binary search function
//Returns location of x in array, if present, or returns -1
//Array size: arr[a, b]
int binarysearch(int arr[], int a, int b, int x)
{
	while(a <= b)
	{
		//find midpoint of array
		//subtract 1 from b to account for array starting at 0
		int mid = a + (b-1)/2;
	
		//if x is present in the middle of array, return midpoint 
		if(arr[mid] == x)
			return mid;
		
		//if x is smaller than midpoint, recursively call function on left half of array
		if(arr[mid] > x)
			return binarysearch(arr, a, mid-1, x);
		
		//If previous two don't work, then x would be in right half of array
		return binarysearch(arr, mid+1, b, x);
	}
	return -1;
}

int main()
{
	int arr[] = {2, 5, 7, 14, 22};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 10;
	int result = binarysearch(arr, 0, n-1, x);
	
	if(result == -1)
		printf("Element not present in array");
	else
		printf("Element present at index %d", result);

	return 0;
}
