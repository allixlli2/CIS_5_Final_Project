#include <iostream>
#include <string>
#include <iomanip> // Required for setprecision and fixed

using namespace std;

// 1. STUCTURES
struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

// 2. FUNCTIONS (Prototypes)
void displayMenu();
void showInventory(Product arr[], int size);
void updatePrice(double &p); // 3. REFERENCES (Pass by reference)
void findCheapest(Product* arr, int size); // 4. POINTERS (Using pointer arithmetic)

int main() {
    // 5. ARRAYS (Fixed size for inventory)
    Product inventory[10]; 
    int count = 5;
    int choice;

    // PRE-LOADING THE 5 DRINKS 
    inventory[0] = {101, "Espresso", 50, 3.25};
    inventory[1] = {102, "Oat_Latte", 8, 5.50};
    inventory[2] = {103, "Cold_Brew", 15, 4.75};
    inventory[3] = {104, "Mocha", 5, 6.25};
    inventory[4] = {105, "Caramel_Mac", 20, 5.95};
    count = 5;

    cout << "--- Blush Brew Coffee Shop System ---" << endl;

    // 6. LOOPS (do-while for the menu)
    do {
        displayMenu();
        // 7. USER INPUT (cin)
        cout << "Enter your choice";
        cin >> choice;
        cin.ignore(); // 

        if (choice == 1) {
            if (count < 10) {
                cout << "Enter ID: "; cin >> inventory[count].id;
                cout << "Enter Name (No_Spaces): "; cin >> inventory[count].name;
                cout << "Enter Quantity: "; cin >> inventory[count].quantity;
                cout << "Enter Price: "; cin >> inventory[count].price;
                count++;
                cout << "Item added successfully!" << endl;
            } else {
                cout << "Inventory full!" << endl;
            }
        } 
        else if (choice == 2) {
            // 9. DISPLAY OUTPUT (cout)
            showInventory(inventory, count);
        } 
        else if (choice == 3) {
            if (count > 0) {
                // Applying a 10% discount using a reference
                for(int i = 0; i < count; i++) {
                    updatePrice(inventory[i].price);
                }
                cout << "Happy Hour! All prices discounted by 10%." << endl;
            } else {
                cout << "Inventory is empty!" << endl;
            }
        }
        else if (choice == 4) {
            findCheapest(inventory, count);
        }
        else if (choice == 5) {
            cout << "Exiting program..." << endl;
        } 
        else {
            cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

// Function Definitions
void displayMenu() {
    cout << "\n1. Add Coffee Item"
         << "\n2. View Shop Inventory"
         << "\n3. Apply Happy Hour Discount (Reference)"
         << "\n4. Find Cheapest Item (Pointer)"
         << "\n5. Exit"
         << "\nChoice: ";
}

void showInventory(Product arr[], int size) {
    cout << "\n--- Current Inventory ---" << endl;
    // 6. LOOPS (for loop)
    for (int i = 0; i < size; i++) {
        cout << "ID: " << arr[i].id 
             << " | Item: " << left << setw(15) << arr[i].name 
             << " | Stock: " << arr[i].quantity;
             
        // Logic for low stock alert
        if(arr[i].quantity < 10) {
            cout << " [LOW STOCK]";
        }

        // Formatting price to 2 decimal places using iomanip
        cout << " | Price: $" << fixed << setprecision(2) << arr[i].price << endl;
    }
}

// References
void updatePrice(double &p) {
    p = p * 0.90; // Modifies the actual price in the array directly
}

// Pointers
void findCheapest(Product* arr, int size) {
    if (size == 0) {
        cout << "No items to compare." << endl;
        return;
    }
    
    Product* cheapest = arr; // Pointer pointing to the first element
    for (int i = 1; i < size; i++) {
        // Using pointer arithmetic (arr + i) to check prices
        if ((arr + i)->price < cheapest->price) { 
            cheapest = (arr + i);
        }
    }
    cout << "The most affordable item is: " << cheapest->name 
         << " at $" << fixed << setprecision(2) << cheapest->price << endl;
}