class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high)
        {
            int pI = partition(arr, low, high);
            quickSort(arr, low, pI - 1);
            quickSort(arr, pI + 1, high);
        }
    }

public:
    int partition(int arr[], int low, int high)
    {
        // Your code here
        int l = low, j = high;
        int pivot = arr[low];
        while (l < j)
        {
            while (arr[l] <= pivot)
                l++;
            while (arr[j] > pivot)
                j--;
            if (l < j)
            {
                swap(arr[l], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }
};