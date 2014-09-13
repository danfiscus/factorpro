#include <iostream>

using namespace std;

int main()
{
    float factor_this;
    int divided_by, up_to;
    char proceed;
    begin:
    cout << "How many factors do you want listed?" << '\n';
    cin >> up_to >> '\n';
    up_to = up_to + 1;
    cout << "Next, please enter a number to see it's factors." << '\n';
    cin >> factor_this >> '\n';
    for (divided_by=1; divided_by < up_to;)
        {cout << factor_this << " divided by " << divided_by << " is " << (factor_this/divided_by) << '\n'; ++divided_by;}
    cout << "Would you like to calculate more? Y for yes, N for no." << '\n';
    cin >> proceed >>'\n';
    if (proceed=='Y' || proceed=='y')
    {
        goto begin;
    }
    return 0;
}
