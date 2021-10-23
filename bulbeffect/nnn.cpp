#include <bits/stdc++.h>

using namespace std;

void rotate(int arr[],int first,int last){
        while(first<last){
                arr[first] = arr[first]^arr[last];
                arr[last] = arr[first]^arr[last];
                arr[first] = arr[first]^arr[last];
                first++;
                last--;
            }
    }

int finPosition(int x, int arr[], int n){
    for(int i = 0; i<n; i++){
        if(arr[i]==x) return i;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    int* maxElem = std::max_element(arr, arr + n);
    int* minElem = std::min_element(arr, arr + n);
    
    int maxPos = finPosition(*maxElem, arr, n);
    int minPos = finPosition(*minElem, arr, n);
    
    int res = *maxElem - *minElem;
    if(maxPos>minPos){
        rotate(arr, 0, res - 1);
        rotate(arr, res, n - 1);
	    rotate(arr, 0, n - 1);
    }
    else{
        rotate(arr, 0, n - 1);
        rotate(arr, 0, res - 1);
	    rotate(arr, res, n - 1);
    }
    
    for(int i = 0 ;i<n; i++){
        cout<<arr[i]<<" ";
    }
}