#include <bits/stdc++.h>
using namespace std;

class Customer
{
public:
    int id;
    string name, email, phone;
    double bill;

    Customer(int id, const string &name, const string &email, const string &phone, double bill)
        : id(id), name(name), email(email), phone(phone), bill(bill) {}

    void show() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Email: " << email
             << ", Phone: " << phone << ", Bill: " << bill << endl;
    }
};

void loadFile(vector<Customer> &customers)
{
    ifstream in("data.txt");
    if (!in)
    {
        cerr << "ERROR loading file!" << endl;
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
        cerr << "ERROR saving file!" << endl;
        return;
    }
    for (const auto &x : customers)
    {
        out << x.id << "\n"
            << x.name << "\n"
            << x.email << "\n"
            << x.phone << "\n"
            << x.bill << "\n";
    }
    out.close();
}

void add(vector<Customer> &customers)
{
    int id;
    string name, email, phone;
    double bill;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Enter Phone: ";
    getline(cin, phone);
    cout << "Enter Bill: ";
    cin >> bill;
    customers.push_back(Customer(id, name, email, phone, bill));
    cout << "Customer added successfully.\n";
}

void view(const vector<Customer> &customers)
{
    if (customers.empty())
    {
        cout << "No data available.\n";
        return;
    }

    for (const auto &x : customers)
    {
        x.show();
    }
}

void change(vector<Customer> &customers, int id)
{
    for (auto &x : customers)
    {
        if (x.id == id)
        {
            cin.ignore();
            cout << "Enter new Name: ";
            getline(cin, x.name);
            cout << "Enter new Email: ";
            getline(cin, x.email);
            cout << "Enter new Phone: ";
            getline(cin, x.phone);
            cout << "Enter new Bill: ";
            cin >> x.bill;
            cout << "Customer modified successfully.\n";
            return;
        }
    }
    cout << "Customer not found!\n";
}

void remove(vector<Customer> &customers, int id)
{
    auto it = remove_if(customers.begin(), customers.end(), [id](const Customer &c)
                        { return c.id == id; });
    if (it != customers.end())
    {
        customers.erase(it, customers.end());
        cout << "Customer removed successfully.\n";
    }
    else
    {
        cout << "Customer not found!\n";
    }
}

bool cmpName(const Customer &a, const Customer &b)
{
    return a.name < b.name;
}

void sortName(vector<Customer> &customers)
{
    sort(customers.begin(), customers.end(), cmpName);
    cout << "Customers sorted by name.\n";
}

void searchName(const vector<Customer> &customers, const string &name)
{
    for (const auto &x : customers)
    {
        if (x.name == name)
        {
            x.show();
            return;
        }
    }
    cout << "Customer not found!\n";
}

int main()
{
    vector<Customer> customers;
    loadFile(customers);

    int option;
    do
    {
        cout << "\nMENU:\n";
        cout << "1. Add Customer\n";
        cout << "2. View Customers\n";
        cout << "3. Modify Customer\n";
        cout << "4. Remove Customer\n";
        cout << "5. Sort by Name\n";
        cout << "6. Search by Name\n";
        cout << "7. Save to File\n";
        cout << "8. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            add(customers);
            break;
        case 2:
            view(customers);
            break;
        case 3:
        {
            int id;
            cout << "Enter Customer ID to modify: ";
            cin >> id;
            change(customers, id);
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter Customer ID to remove: ";
            cin >> id;
            remove(customers, id);
            break;
        }
        case 5:
            sortName(customers);
            break;
        case 6:
        {
            string name;
            cout << "Enter Name to search: ";
            cin.ignore();
            getline(cin, name);
            searchName(customers, name);
            break;
        }
        case 7:
            saveFile(customers);
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "INVALID CHOICE\n";
            break;
        }
    } while (option != 8);

    return 0;
}
