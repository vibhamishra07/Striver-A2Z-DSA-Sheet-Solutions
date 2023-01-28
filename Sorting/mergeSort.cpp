class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int ls = l, rs = m + 1, k = l, ans[r + 1];
        while (ls <= m && rs <= r)
        {
            if (arr[ls] <= arr[rs])
            {
                ans[k++] = arr[ls++];
            }
            else
            {
                ans[k++] = arr[rs++];
            }
        }
        while (ls <= m)
        {
            ans[k++] = arr[ls++];
        }
        while (rs <= r)
        {
            ans[k++] = arr[rs++];
        }

        for (int i = l; i <= r; i++)
        {
            arr[i] = ans[i];
        }
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        // code here
        if (l < r)
        {
            int mid = (l + r) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};