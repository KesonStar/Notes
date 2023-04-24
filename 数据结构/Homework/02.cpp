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

void Maxsubsequence(vector<int> &v)
{
    int thisSum = 0, maxSum = 0;
    int start = 0, end = 0, tmpstart = 0;
    int neg_cnt = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        if(v[i] < 0)
            neg_cnt++;
        thisSum += v[i];
        if (thisSum < 0)
        {
            thisSum = 0;
            tmpstart = i+1;
        }
        else if (thisSum > maxSum)
        {
            maxSum = thisSum;
            start = tmpstart;
            end = i;
        }
    }
    if(maxSum == 0&&neg_cnt == v.size())
        printf("%d %d %d", 0, v[0], v[v.size()-1]);
    else if(maxSum==0&&neg_cnt!=v.size())
        printf("%d %d %d", 0, 0, 0);
    else
        printf("%d %d %d", maxSum, v[start], v[end]);
}
/* Key:
    the start index of the max subsequence is the first index after thisSum is set to 0
    the end index of the max subsequence is the last index of maxSum
*/