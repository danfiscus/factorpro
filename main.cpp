#include <iostream>

using namespace std;

int factor_this;    //The number to factor
int how_many;       //How many factors the user wants listed (or -1 for all)
char proceed;       //Whether or not to run the program again

int main()
{
    cout << "Please enter a number to see it's factors." << endl;
    cin >> factor_this;

    cout << "How many factors do you want listed?" << endl;
    cin >> how_many;
    if (how_many == -1)
    {
        how_many == factor_this; //Theorem: the number of factors a number has is less than itself
    }
    for (int divided_by=1; (how_many!=0)&&(divided_by <= factor_this); ++divided_by)
    {
        if (factor_this%divided_by == 0)
        {
            cout << factor_this << " divided by " << divided_by << " is " << (factor_this/divided_by) << endl;
            how_many-=1;
        }
    }
    cout << "Would you like to calculate more? Y for yes, N for no." << endl;
    cin >> proceed;
    if (proceed == 'N' || proceed == 'n')
    {
        cout << "I feel so, empty." <<endl; //Easter egg
        return 0;
    }
    main();
}
