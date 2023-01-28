class Solution
{
    public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for(int i=1; i<n; i++){
           int temp=arr[i];
           int idx=i-1;
           while(idx>=0 && arr[idx]>temp){
               arr[idx+1]=arr[idx];
               idx--;
           }
           arr[idx+1]=temp;
       }
    }
};