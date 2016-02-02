#include <iostream>
#include <math.h>
#include <ctype.h>
#include <string>
using namespace std;

int factor_this;    //The number to factor
int how_many;       //How many factors the user wants listed (or -1 for all)
char proceed;       //Whether or not to run the program again
int factors;        //Tracks the number of factors a number has (caps out if limit mode is on)
bool doexit;        //If true, exit the program next time main is finished running
bool dofactorcount; //If true, tracks the number of factors a number has
int inputconvert(string); //Convert raw string input to int
void helptext();
void limitmode();
void dofactors();
void about();


int main()
{
        string rawinput;
        cout << "Welcome to Factor Pro!" << endl;
        helptext();
        do {
                how_many = -1;
                cout << "Please enter a number to see its factors. (Alternatively, you can enter special commands here. For more info, type \"help\" without quotes.)" << endl;
                cin >> rawinput; //Inputting as string is safer because non-int inputs don't break the program
                factor_this = inputconvert(rawinput); //Convert raw input to int and set as factor_this
                dofactors();

        }
        while(!doexit);
        cout << "I feel so... empty." <<endl; //Easter egg
        return 0;
}

int inputconvert(string rawinput) {
        if(rawinput=="help") {helptext(); }
        if(rawinput=="about") {about(); }
        if(rawinput=="bill o'reilly"||rawinput=="bill oreilly"||rawinput=="o'reilly"||rawinput=="oreilly") {cout << "You already are \"The Factor\"! At least, according to you." << endl; }
        if(rawinput=="limit") {limitmode(); }
        if(rawinput=="count") {cout<<"Count mode enabled. Returning to main prompt."<<endl; dofactorcount=true; }//Tell the user so they know to re enter their number at the prompt and that the mode is persistent
        if(rawinput=="nocount") {cout<<"Count mode disabled. Returning to main prompt."<<endl; dofactorcount=false; }
        if(rawinput=="exit") {
                doexit = true;
                cout << "The program will exit at the end of this run." << endl;
        }
        int result=0;
        if(!(rawinput=="help"||rawinput=="about"||rawinput=="bill o'reilly"||rawinput=="bill oreilly"||rawinput=="o'reilly"||rawinput=="oreilly"||rawinput=="limit"||rawinput=="exit"||rawinput=="count"||rawinput=="nocount"))
        {
                //OMG C++ CONVERTS STRINGS TO INTS NOW WITHOUT STUPID ASCII TABLES THAT ONLY WORK ON WINDOWS! WOOHOOOO!
                try{
                        result = stoi (rawinput);
                }
                catch(...) {    //Catches all exceptions for now
                        cout << "Error: Invalid input. Did you accidentally enter a non-number character?" << endl;
                }
        }
        return result;
}

void helptext() {
        cout << "How to use Factor Pro: To factor a number, simply enter the number at the prompt.\nTo limit the output to a certain number of factors, type \"limit\" (without quotes)\nwhen prompted for a number to factor. If you accidentally enter limit mode, simply\ntype -1 for the number of factors and the program will output all factors. To exit\nthe program, type \"exit\" at any time (without quotes.) The program will finish\nrunning before exiting after being given this command. For information about this\nprogram, type about. To see this help text again, type help at the main prompt." << endl;
}
void about() {
        cout << "Programmers:\nDan Fiscus\nChris King\nSource code available at:\nhttp://www.github.com/danfiscus/factorpro\n";
        //Eventually, replace string copyrightsym with a char that holds the actual symbol. Until then...
        string copyrightsym = "\u00A9";
        cout << copyrightsym << "2014-2016 Dan Fiscus" << endl;
}
void dofactors() {
        if (how_many == -1)
        {
                how_many = factor_this; //Theorem: the number of factors a number has is less than itself
        }
        for (int divided_by=1; (how_many!=0)&&(divided_by <= factor_this)&&(divided_by<=factor_this/divided_by); ++divided_by)
        {
                if (factor_this%divided_by == 0)
                {
                        cout << factor_this << " divided by " << divided_by << " is " << (factor_this/divided_by) << endl;
                        how_many-=1;
                        if(dofactorcount) {factors+=2; }//Theorem: Each output displays two new factors
                }
        }
        if(dofactorcount) {cout << factor_this << " has " << factors << " factors." << endl; }
}

void limitmode() {
        string rawinput;
        cout << "How many factors do you want listed?" << endl;
        cin >> rawinput;
        how_many = inputconvert(rawinput);
        cout << "What number would you like to see factored?" << endl;
        cin >> rawinput;
        factor_this = inputconvert(rawinput);
        dofactors();
}
