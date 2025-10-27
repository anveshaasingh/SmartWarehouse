// warehouse.cpp
#include "warehouse.h"

Warehouse::Warehouse(int rCount, int rCap) {
    rackCount = rCount;
    rackCapacity = rCap;
    racks.resize(rCount);
}

void Warehouse::addItem() {
    Item item;
    cout << "Enter SKU: ";
    cin >> item.sku;
    
     if (inventory.find(item.sku) != inventory.end()) {
        cout << " Error: SKU '" << item.sku << "' already exists for item '"
             << inventory[item.sku].name << "' (Quantity: "
             << inventory[item.sku].quantity << ").\n";
        return;
    }


    cout << "Enter Item Name: ";
    cin >> item.name;
    cout << "Enter Quantity: ";
    cin >> item.quantity;
    item.rackNo = -1;
    inventory[item.sku] = item;
    cout << "Item added successfully!\n";
}

void Warehouse::storeItem() {
    string sku;
    cout << "Enter SKU to store: ";
    cin >> sku;

    if (inventory.find(sku) == inventory.end()) {
        cout << "Item not found in inventory!\n";
        return;
    }

    if (inventory[sku].rackNo != -1) {
        cout << " Item with SKU '" << sku << "' is already stored in Rack "
             << inventory[sku].rackNo << ".\n";
        return;
    }

    for (int i = 0; i < rackCount; i++) {
        if (racks[i].size() < rackCapacity) {
            racks[i].push_back(sku);
            inventory[sku].rackNo = i;
            cout << "Item stored in Rack " << i << "\n";
            return;
        }
    }

    cout << "All racks are full!\n";
}

void Warehouse::retrieveItem() {
    string sku;
    cout << "Enter SKU to retrieve: ";
    cin >> sku;

    if (inventory.find(sku) == inventory.end()) {
        cout << "Item not found!\n";
        return;
    }

    int rackNo = inventory[sku].rackNo;
    if (rackNo == -1) {
        cout << "Item is not stored in any rack.\n";
        return;
    }

    auto &rack = racks[rackNo];
    for (auto it = rack.begin(); it != rack.end(); ++it) {
        if (*it == sku) {
            rack.erase(it);
            inventory[sku].rackNo = -1;
            cout << "Item retrieved successfully from Rack " << rackNo << "!\n";
            return;
        }
    }

    cout << "Error retrieving item.\n";
}

void Warehouse::searchItem() {
    string sku;
    cout << "Enter SKU to search: ";
    cin >> sku;

    if (inventory.find(sku) == inventory.end()) {
        cout << "Item not found!\n";
        return;
    }

    Item it = inventory[sku];
    cout << "Item Name: " << it.name
         << "\nQuantity: " << it.quantity
         << "\nRack No: " << (it.rackNo == -1 ? -1 : it.rackNo)
         << "\n";
}

void Warehouse::listItems() {
    cout << "\n--- Inventory List ---\n";
    for (auto &pair : inventory) {
        cout << "SKU: " << pair.second.sku
             << ", Name: " << pair.second.name
             << ", Qty: " << pair.second.quantity
             << ", Rack: " << (pair.second.rackNo == -1 ? -1 : pair.second.rackNo)
             << "\n";
    }

    cout << "\n--- Racks ---\n";
    for (int i = 0; i < rackCount; i++) {
        cout << "Rack " << i << ": ";
        for (string s : racks[i]) cout << s << " ";
        cout << "\n";
    }
}
