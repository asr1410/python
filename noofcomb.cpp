#include <stdio.h>
#include <string.h>

long gcd(long a, long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to find gcd of array of
// numbers
long findGCD(long arr[], long n)
{
    long result = arr[0];
    for (long i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

long print(long *num, long n)
{
    long i = 0, j = 2, k = 0;
    long size = n / 2;
    long arr[size];
    while (i < n && j < n && k < size)
    {
        arr[k] = num[i] + num[j];
        k++;
        if (k % 2 == 0)
        {
            i = i + 3;
            j = k + 3;
        }
        else
        {
            i++;
            j++;
        }
    }
    long factor = findGCD(arr, size);
    return factor;
}
int main()
{
    long fact = 0, tempres = 0;
    long *ptr;
    long temp;
    long i, n, j;
    scanf("%ld", &n);
    long num[n];
    for (i = 0; i < n; i++)
        scanf("%ld", &num[i]);
    for (j = 1; j <= n; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            temp = num[i];
            num[i] = num[i + 1];
            num[i + 1] = temp;
            tempres = print(num, n);
            if (tempres > fact)
            {
                fact = tempres;
            }
        }
    }
    printf("%ld", fact);
    return 0;
}