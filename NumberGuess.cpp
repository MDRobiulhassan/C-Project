#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;

int NumberGenerate()
{
    srand(time(0));
    int GeneratedNumber = rand() % 100 + 1;
    return GeneratedNumber;
}

void CheckResult()
{
    vector<int> lowestattempt;
    int UserInput, attempt = 0, choice;
    do
    {
        int GeneratedNumber = NumberGenerate();
        attempt=0;
        cout << GeneratedNumber << endl;
        do
        {
            cout << "Guess a Number : ";
            cin >> UserInput;
            attempt++;
            if (UserInput == GeneratedNumber)
            {
                cout << "Mathced!" << endl
                     << "You took " << attempt << " attempt" << endl;
            }
            else if (UserInput < GeneratedNumber)
                cout << "A bit Higher" << endl;
            else
                cout << "A bit Smaller" << endl;

            lowestattempt.push_back(attempt);

        } while (UserInput != GeneratedNumber);

        cout << "1.Start Again" << endl
             << "2.End" << endl
             << "3.View Your Lowest Attempt" << endl;
        cin >> choice;

        if (choice == 3)
        {
            auto lowattempt = min_element(lowestattempt.begin(), lowestattempt.end());
            cout << "Lowest Attempt Took : " << *lowattempt << endl;
        }

    } while (choice == 1);
}

int main()
{
    cout << "\t\t\tWelcome TO Number Guessing Game" << endl;
    CheckResult();

    return 0;
}