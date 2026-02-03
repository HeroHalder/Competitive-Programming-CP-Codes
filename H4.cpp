 #include<iostream>
 using namespace std;
 int BinarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
while(start<=end){
    int mid = start + (end - start)/2;
    if (arr[mid]==key){
        return mid;
    }
    else if(arr[mid]<key){
        start = mid + 1;
    }
    else{
        end = mid -1;
    }
    
}
return -1;
}
 int main(){

    int n, key;
    cout<<"Enter the Size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Ther Elements of the Array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<< "Enter The key of The Element to be searched: ";
    cin>>key;
    int result = BinarySearch(arr, n, key);
    if(result != -1){
        cout<<"Element Found at index: "<< result<<"\n";
    }
    else{
        cout<<"Element Not Found in the Array. \n";
    }

    return 0;

 }