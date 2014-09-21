#include <iostream>

using namespace std;

int factor_this;
int divided_by;
char proceed;

int main()
{
    cout << "Please enter a number to see it's factors." << endl;
    cin >> factor_this;
    for (divided_by=1;divided_by != factor_this+1;++divided_by)
        {
            if (factor_this%divided_by == 0)
            {
                cout << factor_this << " divided by " << divided_by << " is " << (factor_this/divided_by) << endl;
            }
        }
    cout << "Would you like to calculate more? Y for yes, N for no." << endl;
    cin >> proceed;
    if (proceed=='Y' || proceed=='y')
    {
        main();
    }
    if (proceed == 'N' || proceed == 'n')
    {
        cout << "I feel so, empty." <<endl;
    }
    return 0;
}
