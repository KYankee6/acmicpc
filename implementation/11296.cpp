#include <bits/stdc++.h>
using namespace std;

struct PayInfo
{
    long long price;
    int discountRatio;
    string payMethod;

    PayInfo(){};
    PayInfo(long long _price, int _discountRatio, string _payMethod) : price(_price), discountRatio(_discountRatio), payMethod(payMethod){};
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

void setDiscountRatioWithSticker(map<char, int> &discountInfo, PayInfo &payInfo, char sticker)
{
    payInfo.discountRatio = discountInfo[sticker];
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
    case 'white':
    {
        payInfo.discountRatio = 5;
        break;
    }
    }
}

long long getDiscountPrice(PayInfo &payInfo)
{
    long long discountedPrice = 0L;
    string card = "C";
    if (payInfo.discountRatio == 0)
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    }

    //if paid with card no rounds up
    if (card.compare(payInfo.payMethod) == 0)
    {
        return (1 - payInfo.discountRatio / 100) * (payInfo.price * 100);
    }
    //if paid with cash rounds up
    else
    {
        return payInfo.price * 100 * (100 - payInfo.discountRatio) / 100;
    }
}

int main()
{
    string input;
    while (cin >> input)
    {
    }
}