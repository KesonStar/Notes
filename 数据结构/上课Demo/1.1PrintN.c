#include <stdio.h>
void PrintN(int n)
{
    if (n)
    {
        PrintN(n - 1);
        printf("%d ", n);
    }
    return;
}
int main()
{
    PrintN(10e3);
    return 0;
}