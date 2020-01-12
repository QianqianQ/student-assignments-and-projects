#include <stdio.h>

int array_sum(int *array, int count)
{
    int sum = 0;
    for(int i = 0; i < count; i++) {
        sum += array[i];
    }
    return sum;
}

int array_reader(int *vals, int n)
{
    int i, v;
    for (i = 0; i < n; i++) {
        if (scanf("%d", &v) == 1) {
            vals[i] = v;
        } else {
            return i;
        }
    }
    return n;
}
int main(void)
{
    int valarray[] = { 10, 100, 1000 };
    array_sum(valarray, 3);
    int array[10];
    int n = array_reader(array, 10);
    printf("%d numbers read\n", n);
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}