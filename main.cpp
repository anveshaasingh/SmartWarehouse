// main.cpp
#include "warehouse.h"

int main() {
    Warehouse wh;  // default 3 racks, capacity 5 each
    int choice;

    do {
        cout << "\n==== SMART WAREHOUSE MENU ====\n";
        cout << "1. Add Item\n";
        cout << "2. Store Item in Rack\n";
        cout << "3. Retrieve Item\n";
        cout << "4. Search Item\n";
        cout << "5. List All Items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: wh.addItem(); break;
            case 2: wh.storeItem(); break;
            case 3: wh.retrieveItem(); break;
            case 4: wh.searchItem(); break;
            case 5: wh.listItems(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
