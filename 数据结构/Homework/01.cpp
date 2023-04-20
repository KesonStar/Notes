#include <iostream>
#include <vector>
using namespace std;
void Maxsubsequence(vector<int> &v);
int main()
{
    int k, n;
    cin >> k;
    vector<int> v;
    for (int i = 0; i != k; i++)
    {
        cin >> n;
        v.push_back(n);
    }
    Maxsubsequence(v);
}

void Maxsubsequence(vector<int> &v) // ´«ÒýÓÃ±ÜÃâ¿½±´
{
    int thisSum = 0, maxSum = 0;
    for (const auto i : v)
    {
        thisSum += i;
        if (thisSum < 0)
            thisSum = 0;
        else if (thisSum > maxSum)
            maxSum = thisSum;
    }
    printf("%d", maxSum);
}
