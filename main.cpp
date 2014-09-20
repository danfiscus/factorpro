#include <iostream>

using namespace std;

int factor_this;
int divided_by, up_to;
char proceed;

int main()
{

    begin:
    cout << "How many factors do you want listed?" << '\n';
    cin >> up_to;
    up_to = up_to + 1;
    cout << "Next, please enter a number to see it's factors." << '\n';
    cin >> factor_this;
    for (divided_by=1; (divided_by < up_to) && (divided_by < factor_this);)
        {
            if (factor_this%divided_by == 0)
            {
                cout << factor_this << " divided by " << divided_by << " is " << (factor_this/divided_by) << '\n';
            }
             ++divided_by;
        }
    cout << "Would you like to calculate more? Y for yes, N for no." << '\n';
    cin >> proceed;
    if (proceed=='Y' || proceed=='y')
    {
        main();
    }
    if (proceed == 'N' || proceed == 'n')
    {
        cout << "I feel so, empty.";
    }
    return 0;
}
