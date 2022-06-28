#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<bool> switches;

void boyAction(int number)
{
    for (int i = number - 1; i < N; i += number)
    {
        switches[i] = !switches[i];
    }
}

void girlAction(int number)
{
    switches[number - 1] = !switches[number - 1];
    int l = number - 2, r = number;
    while (l >= 0 && r < N)
    {
        if (switches[l] != switches[r])
            break;
        switches[l] = !switches[l];
        switches[r] = !switches[r];
        l--;
        r++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    switches.resize(N, false);
    for (int i = 0; i < N; i++)
    {
        int bit;
        cin >> bit;
        switches[i] = bit;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int gender, number;
        cin >> gender >> number;
        if (gender == 1)
        {
            boyAction(number);
        }
        else
            girlAction(number);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cout << switches[i] << " ";
        cnt++;
        if (cnt == 20)
        {
            cout << endl;
            cnt = 0;
        }
    }
    return 0;
}