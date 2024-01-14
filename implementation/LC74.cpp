#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int nm = n * m -1;
    int l = 0, r = nm;
    if (nm == 0)
    {
        if (target == matrix[0][0])
            return true;
        else
            return false;
    }
    bool found = false;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (matrix[mid / m][mid % m] == target)
        {
            return true;
        }
        else if (matrix[mid / m][mid % m] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> ma = {{1,1}};
    int t = 2;

    searchMatrix(ma,t);

}
