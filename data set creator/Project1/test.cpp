#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	 a = b;
	 b = temp;
}
void alpha(int arr[])//arr[], low, high)
{
	//int arr[] 
	int low = 0;
	int high = 4;
	
	// pivot (Element to be placed at right position)
	int pivot = arr[high];

	int i = (low - 1);  // Index of smaller element

		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than or
			// equal to pivot
			if (arr[j] <= pivot)
			{
				i++;    // increment index of smaller element
				swap(arr[i], arr[j]);
			}
		}
	swap(arr[i + 1], arr[high]);
	for (int j = low; j <= high; j++)
		cout << arr[j] << " ";
	//cin.get();
	//return 0;
}
