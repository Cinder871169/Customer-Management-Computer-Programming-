#include "Customer.h"

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
