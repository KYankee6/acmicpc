// 2022-04-25 18:30:54 문제 이해
// 2022-04-25 18:48:03 구현시작
// 1. 식이 주어졌을때, 왼쪽부터 계산하기 시작하는 함수.
// 2. 괄호안을 먼저 계산하는 로직
// 3. combination이나 연속된 컴비네이션이면 안되는 컴비네이션.

// 2022-04-25 19:10:19 디버깅시작
#include <bits/stdc++.h>

using namespace std;

bool in_condition(vector<bool> op_fixer)
{
    bool can_go = true;
    bool is_prev_on = op_fixer[0];
    for (int i = 1; i < op_fixer.size(); i++)
    {
        if (is_prev_on)
        {
            if (op_fixer[i])
            {
                can_go = false;
                break;
            }
            else
                is_prev_on = false;
        }
        else
        {
            if (op_fixer[i])
                is_prev_on = true;
        }
    }
    return can_go;
}

long long calculate_vectors(vector<int> &numbers, vector<int> &ops)
{
    long long result = numbers[0];
    for (int i = 0; i < ops.size(); i++)
    {
        int op = ops[i];
        switch (op)
        {
        case (0):
            result *= numbers[i + 1];
            break;
        case (1):
            result += numbers[i + 1];
            break;
        case (2):
            result -= numbers[i + 1];
            break;
        }
    }
    return result;
}

int calculate_expression(string expression)
{
    int first_operand = -1;
    int second_operand = -1;
    int op = -1;
    int result = 0;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == -1)
            continue;
        if (first_operand == -1)
        {
            int walker = i;
            while (expression[walker] != '*' && expression[walker] != '-' && expression[walker] != '+' && walker != expression.size())
                walker++;
            first_operand = stoi(expression.substr(i, walker - i));
        }
        else if (op == -1)
        {
            if (expression[i] == '*')
                op = 0;
            else if (expression[i] == '+')
                op = 1;
            else if (expression[i] == '-')
                op = 2;
        }
        else if (second_operand == -1)
        {
            int walker = i;
            while (expression[walker] != '*' && expression[walker] != '-' && expression[walker] != '+' && walker != expression.size())
                walker++;
            second_operand = stoi(expression.substr(i, walker - i));
            switch (op)
            {
            case (0):
                first_operand = first_operand * second_operand;
                break;
            case (1):
                first_operand = first_operand + second_operand;
                break;
            case (2):
                first_operand = first_operand - second_operand;
                break;
            }
            op = -1;
            second_operand = -1;
        }
    }
    result = first_operand;
    return result;
}

int main()
{
    int N;
    cin >> N;
    string expression = "";
    cin >> expression;
    long long answer = INT_MIN;
    if(N==1) {
        cout<<expression;
        return 0;
    }
    vector<bool> op_fixer(N / 2, false);
    for (int r = 0; r < op_fixer.size(); r++)
    {
        op_fixer[r] = true;
        do
        {
            int op_walker = 0;
            bool first_exp = true;
            vector<int> numbers;
            vector<int> visited(N, 0);
            vector<int> ops;
            string result_exp = "";
            if (!in_condition(op_fixer))
                continue;
            for (int i = 0; i < op_fixer.size(); i++)
            {
                if (!op_fixer[i])
                {
                    int op = -1;
                    if (expression[i * 2 + 1] == '*')
                        op = 0;
                    else if (expression[i * 2 + 1] == '+')
                        op = 1;
                    else if (expression[i * 2 + 1] == '-')
                        op = 2;
                    ops.push_back(op);
                }
                else
                {
                    visited[i * 2] = 1;
                    visited[i * 2 + 1] = -1;
                    visited[i * 2 + 2] = 1;
                }
            }
            for (int i = 0; i < N; i++)
            {
                if (visited[i] == 0 && i%2==0) 
                {
                    numbers.push_back(expression[i] - '0');
                }
                else if (visited[i] == -1)
                {
                    numbers.push_back(calculate_expression(expression.substr(i - 1, 3)));
                }
            }

            answer = max(answer, calculate_vectors(numbers, ops));
        } while (prev_permutation(op_fixer.begin(), op_fixer.end()));
    }
    cout << answer;
    return 0;
}