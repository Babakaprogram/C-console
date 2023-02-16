#include <bits/stdc++.h>
#include <fstream>
using namespace std;

double currentIncome = 0, currentExpense = 0;

struct Expense
{
    string date;
    double amount;
    string category;
    double totalExpense;
};

void addExpense(Expense expense[], int &size)
{
    cout << "Enter the date (dd/mm/yyyy): ";
    cin >> expense[size].date;
    cout << "Enter the amount you spend : ";
    cin >> expense[size].amount;
    cout << "Enter the category : ";
    cin >> expense[size].category;
    currentExpense += expense[size].amount;
    expense[size].totalExpense = currentExpense;
    size++;
}

void addIncome(double &currentIncome)
{
    double amount;
    cout << "Enter your Income: ";
    cin >> amount;
    currentIncome += amount;
}

void display(Expense expense[], int size)
{
    cout << "Date\t\tAmount\t\tCategory\n";
    for (int i = 0; i < size; i++)
    {
        cout << expense[i].date << "\t\t" << expense[i].amount << "\t\t" << expense[i].category << endl;
    }
}

void save(Expense expense[], int size)
{
    ofstream file("expenses.txt");
    file << "Total income: " << currentIncome << endl;
    int i;
    for (i = 0; i < size; i++)
    {
        file << expense[i].date << " " << expense[i].amount << " " << expense[i].category << endl;
    }
    file << "Total expense: " << currentExpense << endl;
    // cout<<"HIIIIIIIIIIIIIII"<<expense[i].totalExpense;
    file.close();
}

void loadexpense(Expense expense[], int &size)
{
    fstream file("expenses.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> expense[size].date >> expense[size].amount >> expense[size].category;
            size++;
        }
        file.close();
    }
}
int main()
{
    Expense expense[100];
    int option;
    int size = 0;
    loadexpense(expense, size);
    do
    {
        cout << "1. Add income" << endl;
        cout << "2. Add expense" << endl;
        cout << "3. Display expenses" << endl;
        cout << "4. Save and exit" << endl;
        cout << "Enter your option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            addIncome(currentIncome);
            break;
        case 2:
            addExpense(expense, size);
            break;
        case 3:
            display(expense, size);
            break;
        case 4:
            save(expense, size);
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while (option != 4);
    return 0;
}