#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Customer
{
public:
    int id;
    string name, email, phone;
    double bill;

    Customer(int id, const string &name, const string &email, const string &phone, double bill);

    void show() const;
};

void loadFile(vector<Customer> &customers);
void saveFile(const vector<Customer> &customers);
void add(vector<Customer> &customers);
void view(const vector<Customer> &customers);
void change(vector<Customer> &customers, int id);
void remove(vector<Customer> &customers, int id);
void sortName(vector<Customer> &customers);
void searchName(const vector<Customer> &customers, const string &name);

#endif // CUSTOMER_H
