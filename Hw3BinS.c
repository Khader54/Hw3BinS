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
    while(num % 3 == 0 && num > 0)
    {
            k++;
            num = num / 3;
    }
    return k;
}

int hw3_primes_binary_search(int arr[], int n, int target) {

    int right = n, left = 0,mid , k_target = findK(target),k_mid;



    while (left <= right)
    {

        mid = left + (right - left) / 2 ;
        k_mid = findK(arr[mid]);

        if(k_mid < k_target)
        {
            left = mid + 1;
        }
        else if(k_mid > k_target)
        {
            right = mid - 1;
        }

        else if(k_mid == k_target)
        {
            if(arr[mid] == target)
            {
                if(mid == 0 || arr[mid -1] != target)
                {
                    return mid;
                }
            }
            right = mid - 1;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;



}












