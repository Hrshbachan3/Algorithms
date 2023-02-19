#include <iostream>
using namespace std;
int main()
{
    float profits[] = {10, 5, 15, 7, 6, 18, 3};
    float weights[] = {2, 3, 5, 7, 1, 4, 1};
    float capacity = 15;
    float profit = 0;
    int n = 7;
    float p_by_w[7];
    float max = 0;
    int index;
    for (int i = 0; i < n; i++)
    {
        p_by_w[i] = profits[i] / weights[i];
    }
    while (capacity > 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << p_by_w[i] << ", ";
        }
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            if (p_by_w[i] > max)
            {
                max = p_by_w[i];
                index = i;
            }
        }
        cout << "Max Profit Right now is " << max << "  at index " << index << endl;
        if (capacity > weights[index])
        {
            capacity -= weights[index];
            profit += profits[index];
        }
        else
        {

            profit += capacity * profits[index] / weights[index];
            capacity -= capacity;
        }
        max = 0;
        cout << "Current capacity " << capacity << " and current profit is " << profit << endl;

        p_by_w[index] = 0;
    }
}