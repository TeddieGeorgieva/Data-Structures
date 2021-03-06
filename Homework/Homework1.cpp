#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
void maxHeapify(vector<int>& arr, int n, int i)
{
	int largest = i; // Initialize largest as root
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 

	//left child is larger than root
	if (left < n && arr[left] > arr[largest])
		largest = left;

	//right child is larger than largest so far
	if (right < n && arr[right] > arr[largest])
		largest = right;

	//largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}
void heapSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		maxHeapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];  
	int i = low;  

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[high]);
	return i;
}

void quickSort(int arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int pi = partition(arr, startIndex, endIndex);
		quickSort(arr, startIndex, pi - 1);
		quickSort(arr, pi + 1, endIndex);
	}
}


int main()
{
	vector<int> v;
	v.push_back(12);
	v.push_back(11);
	v.push_back(13);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	heapSort(v);

	cout << "Sorted array is:" << endl;
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);

	cout << "Sorted array is:" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

