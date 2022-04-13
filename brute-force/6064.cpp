// 2022-04-13 18:11:08 문제 이해 시작
// 2022-04-13 18:14:41 문제 이해 완료
// 2022-04-13 18:17:48 해결 방법 고안 시작
//                     M, N <40,000, 40K * 40 K = 160 M 16초? 시간 제한 1초인데..
//                     nlogn 방법을 찾아야 하나?
//                     일단 시간 초과나도 구현해봐야겠다.
// 2022-04-13 18:19:14 코드 작성 시작
// 2022-04-13 18:37:59 1차 제출 메모리 초과(40,000 * 40,000 * 4B = 160 MB * 4라서 초과인듯)
// 2022-04-13 18:39:03 그럼 Map으로 해보자
//                     메모리 초과;
// 그럼 x,y까지만 해놓고 그 뒤는 내가 연산해서 +X년 식으로 해볼까,, 똑같이 초과나려나?
// int를 쓰지말고 short 써볼까 안됨
// 저장하지말고 그냥 돌리자
// 2022-04-13 18:50:32 이젠 시간초과가 나네요 ^
// 2022-04-13 18:56:00 자료구조 꺾어 써보자(2차원 v -> 1차원 pair v)
//                     시간초과는 어떻게 막나,, 저장할 필요는 없다.
// x,y부터 거꾸로 가면 조금 나을려나,, 똑같음
// 4만 이상의 값은 안나올 것 같다로 가볼끄아,,,, 두수의 GCD인거같은데 (2022-04-13 19:37:34 LCM임)
// 2022-04-13 19:23:26 포기
// 2022-04-13 19:37:10 LCM으로 해도 시간초과가 뜬다  허허
// 첫번째를 고정시키고 다음거를 추가하는 방법은,,, 다음에,,,,
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int GCD(int a, int b) { return a == 0 ? b : b == 0 ? a
                                                   : GCD(b, a % b); }

int LCM(int a, int b) { return (a != 0 && b != 0) ? a / GCD(a, b) * b : 0; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        int t1 = 1;
        int t2 = 1;
        long long answer = 1;
        bool endseq = false;
        for (long long i = 1; i <= LCM(M,N); )
        {
            t1 = t1+(M-N);
        }
    return 0;
}