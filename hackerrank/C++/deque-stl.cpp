// But I don't use deque all the time.
// Because STL container may be time out.
#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;
void printKMax(int arr[], int n, int k){
   //Write your code here.
    int i,j,max=arr[0],p = 0;
    for (i = 1; i < k ; i++) {
        if (arr[i] > max) {
            max = arr[i];
            p = i;
        }
    }
    printf("%d ", max);
    for (j = 1; j <= n-k; j++) {
        if (p != j-1) { 
            if (max < arr[j+k-1]) {
                max = arr[j+k-1];
                p = j+k-1;
            }
        } else { 
                max=0;
         for (i = j; i < j+k ; i++) {
            if (arr[i] > max) {
             max = arr[i];
             p = i;
            }
          }
        }
        printf("%d ", max);

    }
    printf("\n");
}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
