#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int hw3_primes_binary_search(int arr[], int n, int target);

int main(void) {
    // read the array (length and items)

    //hw3_primes_binary_search(0, 0, 27);

    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int *arr = (int*) malloc(sizeof(int) * n);
    if (!arr) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return 1;
        }
    }
    int target;
    if (scanf("%d", &target) != 1) {
        free(arr);
        return 1;
    }

    printf("%d", hw3_primes_binary_search(arr, n, target));
    free(arr);
    return 0;
}

/* Your code here */

int findK(int num)
{
    int k = 0;

    while(num > 0)
    {
        if(num % 3 == 0)
        {
            k++;
            num = num / 3;
            continue;
        }
        break;
    }
    return k;
}

int hw3_primes_binary_search(int arr[], int n, int target) {
    int right = n, left = 0,mid = right/2, target_k = findK(target),K_mid;


    while (left < right)
    {
        K_mid = findK(arr[mid]);
        if(K_mid < target_k)
        {
            left = mid;
            mid = left + (right - left) / 2 ;
        }
        else if(K_mid == target_k)
        {
            if(arr[mid] == target)
            {
                return mid;
            }
            if(target < arr[mid])
            {
                right = mid;
                mid = left + (right - left) / 2;
            }

            if(target > arr[mid])
            {
                left = mid;
                mid = left + (right - left)/2;
            }
        }
        if(K_mid > target_k)
        {
            right = mid;
            mid = left + (right - left)/2;
        }
    }
    return -1;
}












