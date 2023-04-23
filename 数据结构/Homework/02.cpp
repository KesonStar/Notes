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
    int end = 0, cnt = 0;
    int neg_cnt = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        thisSum += v[i];
        if(v[i] < 0)
            neg_cnt++;
        if (thisSum < 0)
        {
            thisSum = 0;
        }
        else if (thisSum > maxSum)
        {
            end = i;
            maxSum = thisSum;
        }
    }

    if (maxSum != 0)
    {
        int sum = maxSum;
        for (int i = end; i >= 0; i--)
        {
            if (sum - v[i] != 0)
            {
                sum -= v[i];
                cnt++;
            }
            else
                break;
        }
        if(end-cnt-1>=0&&v[end-cnt-1]==0)
            printf("%d %d %d", maxSum, 0, v[end]);
        else
            printf("%d %d %d", maxSum, v[end - cnt], v[end]);
    }
    else if (neg_cnt == v.size())
        printf("%d %d %d", maxSum, v[0], v[v.size() - 1]);
    else if(maxSum == 0 && neg_cnt != v.size())
    {
        size_t zero_pos = 0;
        for(size_t i = 0; i < v.size(); i++)
        {
            if(v[i] == 0)
            {
                zero_pos = i;
                break;
            }
        }
        printf("%d %d %d", maxSum, v[zero_pos], v[zero_pos]);
    }
}

//One WA: 
//Input: 5
// 0 0 1 -1 2
// AC: 2 0 2
// WA: 2 2 2