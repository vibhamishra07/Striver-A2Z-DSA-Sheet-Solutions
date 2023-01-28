class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here 
        int i=0;
        while(i<n){
            int idx=0;
            for(int j=i+1; j<n; j++){
                if(arr[idx]<arr[j]){
                    idx=j;
                }
            }
            int temp=arr[n-1];
            arr[--n]=arr[idx];
            arr[idx]=temp;
        }
    }
};