/**
 * @file binary_search_iterative.c
 * @brief Binary Search with VLA and overflow protection.
 */

#include <stdio.h>

int main() {
    int n;
    printf("Enter Number of Elements for the Array: ");
    scanf("%d",&n);

    int Array[n];
    printf("Enter Elements in Array: \n");
    for(int i=0 ; i<n ; i++){
        printf("%d Element: ",i+1);
        scanf("%d",&Array[i]);
    }
    printf("\n");
    int key;
    printf("Enter Element to be found: ");
    scanf("%d",&key);

    int low = 0 , high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2; // To prevent the overflow of 32 bit signed integers

        if(Array[mid] == key){
            printf("Element %d found at %d Position\n",key,mid+1);
            return 0;
        }

        else if(key > Array[mid]){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }

    printf("Element %d was not found\n",key);
    return 0;
}