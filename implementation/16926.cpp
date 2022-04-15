#include <bits/stdc++.h>
using namespace std;

int N, M, R;
vector<vector<int>> v;

void print_vector()
{
    for (auto vs : v)
    {
        for (auto e : vs)
        {
            cout << e << " ";
        }
        cout << "\n";
    }

}

void rv()
{
    int T = R;

    while (T--)
    {
        int start_row = 0;
        int end_row = N - 1;
        int start_col = 0;
        int end_col = M - 1;
        int inner_loop_cnt = min(N,M)/2;
        while (inner_loop_cnt--)
        {
            {
                end_row = (N - 1) - start_row;
                end_col = (M - 1) - start_col;
                vector<int> first_col, last_col;
                vector<int> first_row, last_row;
                for (int i = start_col; i <= end_col; i++)
                {
                    first_row.push_back(v[start_row][i]);
                    last_row.push_back(v[end_row][i]);
                }

                for (int i = start_row; i <= end_row; i++)
                {
                    first_col.push_back(v[i][start_col]);
                    last_col.push_back(v[i][end_col]);
                }
                int p1 = first_row[1];           // 1,1
                int p2 = last_col[1];            // 1,2
                int p3 = *(first_col.end()-2); // 2,1
                int p4 = *(last_row.end()-2);  // 2,2
                rotate(first_row.begin(), first_row.begin() + 1, first_row.end());
                rotate(last_row.rbegin(), last_row.rbegin() + 1, last_row.rend());
                rotate(first_col.rbegin(), first_col.rbegin() + 1, first_col.rend());
                rotate(last_col.begin(), last_col.begin() + 1, last_col.end());
                int w1=0; 
                int w2=0;
                for (int i = start_col; i <= end_col; i++)
                {
                    v[start_row][i] = first_row[w1];
                    v[end_row][i] = last_row[w1];
                    w1++;
                }
                for (int i = start_row; i <= end_row; i++)
                {
                    v[i][start_col] = first_col[w2];
                    v[i][end_col] = last_col[w2];
                    w2++;
                }
                v[start_row][start_col] = p1;
                v[start_row][end_col] = p2;
                v[end_row][start_col] = p3;
                v[end_row][end_col] = p4;
            }
            start_row++;
            start_col++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> R;
    v.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }
    rv();
    print_vector();
}