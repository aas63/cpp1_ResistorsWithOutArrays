#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int value;
    int connectionType, n = 0;
    int resistor[1000];
    double totalResistance = 0;

    cout << "Select Connection: 1) Series 2) Parallel: ";
    cin >> connectionType;

    cout << "Enter the number of resistors connected: ";
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        
        cout << "Enter the value for each resistor " << i + 1 << ": ";
        cin >> value;
        resistor[i] = value;

        
        if (value == 0)
        {
            cout << "A resistor value cannot be 0." << endl;
            return 1; 
        }
    }


    if (connectionType == 1) 
    {
        for (int i = 0; i < n; i++)
        {
            totalResistance += resistor[i];
        }
    }
    else if (connectionType == 2)
    {
        for (int i = 0; i < n; i++)
        {
            totalResistance += 1 / (double)resistor[i];
        }

        totalResistance = 1 / totalResistance;
    }
    else
    {
        cout << "Invalid connection type. (Must be 1 or 2)" << endl;
        return 1;
    }

    if (totalResistance < 1000)
    {
        cout << "Total Resistance: " << (int)totalResistance << " Ohm" << endl;
    }
    else
    {
        cout << fixed << setprecision(3);
        cout << "Total Resistance: " << (totalResistance / 1000) << " KOhm" << endl;
    }

    return 0;
}
