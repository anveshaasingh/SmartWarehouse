// warehouse.h
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Item {
    string sku;
    string name;
    int quantity;
    int rackNo;
};

class Warehouse {
private:
    unordered_map<string, Item> inventory;
    vector<vector<string>> racks;
    int rackCount;
    int rackCapacity;

public:
    Warehouse(int rCount = 3, int rCap = 5);
    void addItem();
    void storeItem();
    void retrieveItem();
    void searchItem();
    void listItems();
};

#endif

