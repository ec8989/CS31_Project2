

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string assetName;
    double valueInThousands;
    string category;
    
    cout << "Asset name: ";
    getline(cin, assetName);
    cout << "Value (in thousands): ";
    cin >> valueInThousands;
    cin.ignore(10000, '\n');
    cout << "Category: ";
    getline(cin, category);
    cout << "---" << endl;
    
    if (assetName.length() == 0)
    {
        cout << "You must enter an asset name.";
        return 0;
    }
    if (valueInThousands < 0)
    {
        cout << "The asset value must be nonnegative.";
        return 0;
    }
    if (category.length() == 0)
    {
        cout << "You must enter an asset category.";
        return 0;
    }
    
    double trusteeFee = 0;
    
    if (valueInThousands <= 1000)
    {
        trusteeFee = 0.013 * valueInThousands * 1000;
    }
    
    if (valueInThousands > 1000 && valueInThousands <= 10000)
    {
        if (category == "mutual fund" || category == "royalty")
        {
            trusteeFee = ((.013 * 1000 * 1000) + (0.002 * ((valueInThousands - 1000) * 1000)));
        }
        else
        {
            trusteeFee = ((.013 * 1000 * 1000) + ((valueInThousands - 1000) * 0.01 * 1000));
        }
    }
   
    if (valueInThousands > 10000)
    {
        
        if (category == "mutual fund" || category == "royalty")
        {
            trusteeFee = (.013 * 1000 * 1000) + (0.002 * 9000 * 1000) + (0.009 * ((valueInThousands - 10000) * 1000));
        }
        else
        {
            trusteeFee = (.013 * 1000 * 1000) + (0.01 * 9000 * 1000) + (0.009 * ((valueInThousands - 10000) * 1000));
        }
    }

    cout << "The trustee fee for " << assetName << " is $" << trusteeFee << ".";
}
