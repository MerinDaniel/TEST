void printarr(int arr[])
{
    printf("\n the array is\n");
    int i;
    for(i=0;i<5;i++)
        printf("%5d",arr[i]);
}
void findpos(int arr[],int left,int right)
{

    int pivot=arr[left],l=left,r=right,i;

        while(l<r)
        {

            while(arr[r]>pivot)
                r--;
            swap(arr,l,r);
            printarr(arr);

            while(arr[l]<pivot)
                l++;
            swap(arr,l,r);
            printarr(arr);
        }
        if(l-left>1)
            findpos(arr,left,l-1);
        if(right-r>1)
            findpos(arr,r+1,right);

}
void swap(int arr[],int l,int r)
{
    int temp=arr[l];
    arr[l]=arr[r];
    arr[r]=temp;
}
void main()
{

    int arr[5]={50,39,4,56,10};
    printarr(arr);
    findpos(arr,0,4);
}
