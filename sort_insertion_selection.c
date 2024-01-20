# include<stdio.h>
#define max 7 

void insertion_sort( int arr[] , int size){
    for ( int i = 1 ; i < size ; i++){
        int key = arr[i];
        int j = i-1 ;
         while( j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
         }
         arr[j+1]=key;
    }
}



void print_arr( int arr[] , int n ){
    for (int i = 0 ; i <n ; i++){
        printf("%d \t"  , arr[i]);
    }
}

int smallest_num( int arr[] ,int k , int n ){
int small= arr[k];
int pos = k; 
 for ( int i = k+1 ; i < n ; i++) {
    if( arr[i]<small){
        small=arr[i] ; 
        pos=i ; 
    }
 }
return pos ; 
}

void selection_sort(int arr[], int n){ 
    for ( int k = 0 ; k < n  ; k++){
        int pos=smallest_num( arr , k , n);
        int temp=arr[k];
        arr[k]=arr[pos];
        arr[pos]=temp ;
    }
}
int main(){
 int arr[max]={21 , 78 , 12 , 2 , 78, 6 , 69};
 int size = max ;
 //insertion_sort(arr , size);
 selection_sort( arr , size);
 print_arr(arr , size);
return 0 ;
}