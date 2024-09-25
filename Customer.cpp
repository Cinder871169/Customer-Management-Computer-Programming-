#include "Customer.h"

Customer::Customer(int id, const string &name, const string &email, const string &phone, double bill)
    : id(id), name(name), email(email), phone(phone), bill(bill) {}

void Customer::show() const
{
    cout << "ID: " << id << ", Name: " << name << ", Email: " << email
         << ", Phone: " << phone << ", Bill: " << bill << endl;
}

void loadFile(vector<Customer> &customers)
{
    ifstream in("data.txt");
    if (!in)
    {
        cerr << "ERROR loading file!" << endl;
        return;
    }

    customers.clear(); // Clear existing data
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
    cin.ignore(); // Clear the input buffer
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
            cin.ignore(); // Clear the input buffer
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

void sortName(vector<Customer> &customers)
{
    sort(customers.begin(), customers.end(), [](const Customer &a, const Customer &b)
         { return a.name < b.name; });
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
