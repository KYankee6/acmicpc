#include <bits/stdc++.h>
using namespace std;

struct PayInfo
{
    double price;
    int discountRatio;
    char sticker;
    char coupon;
    char payMethod;

    PayInfo(){};
    PayInfo(double _price, char _sticker, char _coupon, char _payMethod) : price(_price), sticker(_sticker), coupon(_coupon), payMethod(_payMethod){};
    PayInfo(vector<string> v)
    {
        price = stol(v[0]);
        sticker = v[1][0];
        coupon = v[2][0];
        payMethod = v[3][0];
    }
};

void initDiscountInfo(map<char, int> &discountInfo)
{
    discountInfo['R'] = 45;
    discountInfo['G'] = 30;
    discountInfo['B'] = 20;
    discountInfo['Y'] = 15;
    discountInfo['O'] = 10;
    discountInfo['W'] = 5;
}
void setDiscountRatioWithSticker(map<char, int> &discountInfo, PayInfo &payInfo)
{
    payInfo.discountRatio = discountInfo[payInfo.sticker];
}
void setDiscountRatioWithSticker(PayInfo &payInfo, char sticker)
{
    switch (sticker)
    {
    case 'R':
    {
        payInfo.discountRatio = 45;
        break;
    }
    case 'G':
    {
        payInfo.discountRatio = 30;
        break;
    }
    case 'B':
    {
        payInfo.discountRatio = 20;
        break;
    }
    case 'Y':
    {
        payInfo.discountRatio = 15;
        break;
    }
    case 'O':
    {
        payInfo.discountRatio = 10;
        break;
    }
    case 'W':
    {
        payInfo.discountRatio = 5;
        break;
    }
    }
}
double myRoundUp(double val)
{
    long long dum = floor(val * 100);
    if (dum % 10 <= 5)
    {
        return floor(val * 10) / 10;
    }
    else
        return ceil(val * 10) / 10;
}
double getDiscountPriceWithCoupon(PayInfo &payInfo)
{
    char coupon = 'C';
    if (coupon == payInfo.coupon)
    {
        return 0.95 * (payInfo.price);
    }
    return payInfo.price;
}

void printDiscountPrice(PayInfo &payInfo)
{
    double discountedPrice = 0L;
    char coupon = 'C';
    char card = 'P';
    payInfo.price = ((double)(100 - payInfo.discountRatio) / 100) * payInfo.price;

    payInfo.price = getDiscountPriceWithCoupon(payInfo);
    // if paid with card no rounds up
    if (card == (payInfo.payMethod))
    {

        cout << payInfo.price;
    }
    // if paid with cash rounds up
    else
    {
        cout << myRoundUp(payInfo.price);
    }
}

vector<string> split(string s, char delim)
{
    vector<string> result;
    stringstream ss(s);
    string temp;
    while (getline(ss, temp, delim))
    {
        result.push_back(temp);
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    map<char, int> discountInfo;
    cout << fixed;
    cout.precision(2);
    initDiscountInfo(discountInfo);
    while (T--)
    {
        string price;
        char s;
        char c;
        char pay;
        cin >> price >> s >> c >> pay;
        PayInfo payInfo(round(stod(price) * 100) / 100, s, c, pay);
        setDiscountRatioWithSticker(discountInfo, payInfo);

        cout << "$";
        printDiscountPrice(payInfo);
        cout << "\n";
    }
    return 0;
}