#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void quicksort(int * list, int low, int high)
{
    if (low >= high-2) return;
    int i = low;
    int pivot = list[high-1];
    int tmp;

    for (int j = low; j < high; j++) 
    {
        if (list[j] < pivot) {
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
            i++;
        }
    }
    list[high-1] = list[i];
    list[i] = pivot;

    quicksort(list, low, i);
    quicksort(list, i, high);
}

const int BASE_2_MASK = 0x01;

int MASK = BASE_2_MASK;

void RadixBase2(int * list, int n)
{
    // loop backwards through the bit string
    // take all other bitstrings that match and put in bucket
    // repeat
    //
    //0b0001
    //
    // 0b0101 5
    // 0b1010 10
    // 0b1111 15
    //
    // 10 5 15

    int tmp;
    int count;

    for (int i = 0; i < sizeof(int); i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (!(list[j] & MASK)) 
            {
                tmp = list[j];
                list[j] = list[count];
                list[count] = tmp;
                count++;
            }
        }
        printf("%d\n", list[i]);
    }

    int MASK = MASK << 1;
    
}
    
int main(int argc, char **argv) 
{
       
    int list[100];
    for (int i = 1; i < argc; i++) 
    {
        list[i-1] = atoi(argv[i]);
    }

    for (int i = 0; i < argc-1; i++) 
    { 
        printf("%d ", list[i]);
    }
    printf("\n");
    RadixBase2(list, 0, argc-1);

    
    for (int i = 0; i < argc-1; i++) 
    { 
        printf("%d ", list[i]);
    }
    printf("\n");

}

