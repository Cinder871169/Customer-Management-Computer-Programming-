#include "Database.h"
#include "Customer.h"
#include <bits/stdc++.h>
using namespace std;

void loadFile(vector<Customer> &customers)
{
    ifstream in("data.txt");
    if (!in)
    {
        cerr << "ERROR! Cannot open file.\n";
        return;
    }

    customers.clear();
    int id;
    string name, email, phone;
    double bill;

    while (in >> id)
    {
        in.ignore();
        getline(in, name);
        getline(in, email);
        getline(in, phone);
        in >> bill;
        customers.push_back(Customer(id, name, email, phone, bill));
    }
    in.close();
}

void saveFile(const vector<Customer> &customers)
{
    ofstream out("data.txt");
    if (!out)
    {
        cerr << "ERROR! Cannot open file.\n";
        return;
    }

    for (const auto &c : customers)
    {
        out << c.id << "\n"
            << c.name << "\n"
            << c.email << "\n"
            << c.phone << "\n"
            << c.bill << "\n";
    }
    out.close();
}

void add(vector<Customer> &customers)
{
    int id;
    string name, email, phone;
    double bill;

    cin >> id;
    cin.ignore();
    getline(cin, name);
    getline(cin, email);
    getline(cin, phone);
    cin >> bill;

    customers.push_back(Customer(id, name, email, phone, bill));
    cout << "DONE\n";
}

void view(const vector<Customer> &customers)
{
    if (customers.empty())
    {
        cout << "NO DATA\n";
        return;
    }

    for (const auto &c : customers)
    {
        c.show();
    }
}

void change(vector<Customer> &customers, int id)
{
    for (auto &c : customers)
    {
        if (c.id == id)
        {
            cin.ignore();
            getline(cin, c.name);
            getline(cin, c.email);
            getline(cin, c.phone);
            cin >> c.bill;
            cout << "DONE\n";
            return;
        }
    }
    cout << "NOT FOUND!\n";
}

void remove(vector<Customer> &customers, int id)
{
    auto it = remove_if(customers.begin(), customers.end(), [id](const Customer &c)
                        { return c.id == id; });

    if (it != customers.end())
    {
        customers.erase(it, customers.end());
        cout << "DONE\n";
    }
    else
    {
        cout << "NOT FOUND!\n";
    }
}

bool cmpName(const Customer &a, const Customer &b)
{
    return a.name < b.name;
}

void sortName(vector<Customer> &customers)
{
    sort(customers.begin(), customers.end(), cmpName);
}

bool cmpID(const Customer &a, const Customer &b)
{
    return a.id < b.id;
}

void sortID(vector<Customer> &customers)
{
    sort(customers.begin(), customers.end(), cmpID);
}

void searchName(const vector<Customer> &customers, const string &name)
{
    for (const auto &c : customers)
    {
        if (c.name == name)
        {
            c.show();
            return;
        }
    }
    cout << "NOT FOUND\n";
}
