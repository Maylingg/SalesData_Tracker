#include <iostream>
#include <string>
using namespace std;

const int NUM_SALSA_TYPES = 5;

void printReport(string salsa_names[], int jars_sold[])
{
    // Calculate total sales
    int total_sales = 0;
    for (int i = 0; i < NUM_SALSA_TYPES; ++i)
    {
        total_sales += jars_sold[i];
    }

    // Find highest and lowest selling products
    int max_sales = jars_sold[0];
    int min_sales = jars_sold[0];
    int max_index = 0;
    int min_index = 0;

    for (int i = 1; i < NUM_SALSA_TYPES; ++i)
    {
        if (jars_sold[i] > max_sales)
        {
            max_sales = jars_sold[i];
            max_index = i;
        }
        if (jars_sold[i] < min_sales)
        {
            min_sales = jars_sold[i];
            min_index = i;
        }
    }

    // Print sales report
    cout << "\nSales Report:\n";
    cout << "-------------\n";
    for (int i = 0; i < NUM_SALSA_TYPES; ++i)
    {
        cout << salsa_names[i] << ": " << jars_sold[i] << " jars\n";
    }
    cout << "\nTotal Sales: " << total_sales << " jars\n";
    cout << "Best selling product: " << salsa_names[max_index] << " (" << max_sales << " jars)\n";
    cout << "Worst selling product: " << salsa_names[min_index] << " (" << min_sales << " jars)\n";
}

int main()
{
    string salsa_names[NUM_SALSA_TYPES] = {"mild", "medium", "sweet", "hot", "zesty"};
    int jars_sold[NUM_SALSA_TYPES] = {0};

    // Prompt user to enter sales data
    for (int i = 0; i < NUM_SALSA_TYPES; ++i)
    {
        while (true)
        {
            cout << "Enter number of jars sold for " << salsa_names[i] << ": ";
            cin >> jars_sold[i];
            if (jars_sold[i] >= 0)
            {
                break;
            }
            else
            {
                cout << "Number of jars sold cannot be negative. Please enter a valid number.\n";
            }
        }
    }

    // Print the report
    printReport(salsa_names, jars_sold);

    return 0;
}