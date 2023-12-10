using namespace std;

long long gcd(int a, int b){
    if(a%b == 0){
        return b;
    }
    else return gcd(b,a%b);
}

long long solution(int w,int h) {
    long long answer = 1;
    long long g = gcd(w,h);
    answer = (long long)w*(long long)h - ((long long)w/g + (long long)h/g - 1)*g;
    return answer;
}
