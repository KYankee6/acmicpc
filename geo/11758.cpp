#include <bits/stdc++.h>
using namespace std;

int comp(double p1, double p2)
{
    if (abs(p1) > abs(p2))
    {
        return -1;
    }
    else
        return 1;
}

int main()
{
    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    x2 -= x1;
    x3 -= x1;
    y2 -= y1;
    y3 -= y1;
    if (x2 == 0 && x3 == 0)
    {
        cout << "0";
    }
    else
    {
        double lean1 = (double)y2 / x2;
        double lean2 = (double)(y3) / (x3);
        if (lean1 == lean2)
            cout << "0";
        else if (lean1 >= 0 && lean2 >= 0)
        {
            cout<<comp(lean1,lean2);
        }
        else if (lean1 >= 0 && lean2 <= 0)
        {
        }
        else if (lean1 <= 0 && lean2 >= 0)
        {
            cout<<comp(lean1,lean2);
        }
        else if (lean1 <= 0 && lean2 <= 0)
        {
        }
    }
    return 0;
}