#include <iostream>
using namespace std;
const int N = 1000010;
int heap[N], n, pos = 1;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insert(int x)
{
    int curr = pos++;
    heap[curr] = x;
    while (curr > 1)
    {
        int parent = curr / 2;
        if (heap[parent] < heap[curr])
        {
            swap(heap[parent], heap[curr]);
            curr = parent;
        }
        else
            break;
    }
}

void sort()
{
    for (int last = pos - 1; last >= 1; last--)
    {
        swap(heap[last], heap[1]);
        int curr = 1;
        int r = curr * 2, l = curr * 2 + 1, next;
        while (r < last || l < last)
        {
            if (r >= last)
                next = l;
            else if (l >= last)
                next = r;
            else
                next = (heap[l] <= heap[r]) ? r : l;
            if (heap[curr] < heap[next])
            {
                swap(heap[curr], heap[next]);
                curr = next;
                r = curr * 2;
                l = curr * 2 + 1;
            }
            else
                break;
        }
    }
}

int main()
{
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf(" %d", &x);
        insert(x);
    }
    sort();
    for (int i = 1; i <= n; i++)
        printf("%d\n", heap[i]);
}