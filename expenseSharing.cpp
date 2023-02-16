#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

map<string, float> expenses;
vector<string> participants;

void split(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

void addExpense()
{
    string name;
    float amount;
    cout << "Enter the participant name: ";
    cin >> name;
    cout << "Enter the expense amount: ";
    cin >> amount;
    expenses[name] += amount;
}

void showExpenses()
{
    cout << "Expenses:" << endl;
    for (const auto &expense : expenses)
    {
        cout << expense.first << ": " << expense.second << endl;
    }
}

void settleUp()
{
    // float totalExpense = accumulate(expenses.begin(), expenses.end(), 0.0f,
    //     [](float a, const pair<string, float> &b) {
    //         return a + b.second;
    //     });
    float totalExpense = 0;
    for (auto it : expenses)
    {
        totalExpense += it.second;
    }
    cout << "Lambda function: " << totalExpense;
    float share = totalExpense / participants.size();
    for (const auto &participant : participants)
    {
        cout << participant << " owes " << expenses[participant] - share << endl;
    }
}

int main()
{
    cout << "Enter the names of participants separated by comma: ";
    string line;
    getline(cin, line);
    participants = split(line, ',');
    for (const auto &participant : participants)
    {
        expenses[participant] = 0;
    }
    while (true)
    {
        cout << "Enter command (add, show, settle, quit): ";
        string command;
        cin >> command;
        if (command == "add")
        {
            addExpense();
        }
        else if (command == "show")
        {
            showExpenses();
        }
        else if (command == "settle")
        {
            settleUp();
        }
        else if (command == "quit")
        {
            break;
        }
        else
        {
            cout << "Unknown command" << endl;
        }
    }
    return 0;
}
