#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Product {
    string name;
    int quantity;
};

vector<Product> inventory = {
    {"Keyboard", 10},
    {"Mouse", 15},
    {"Laptop", 5}
};

void listAll() {
    for (size_t i = 0; i < inventory.size(); i++) {
        cout << inventory[i].name << " = " << inventory[i].quantity << "\n";
    }
    return;
}

void badInputs() {
    char uInp;
    cin >> uInp;

    if (uInp != 'B') {
        while (uInp != 'B') {
            cout << "Please enter a valid input: ";
            cin >> uInp;
        }
    }

    return;
}

void viewInventory() {
    listAll();

    cout << "Enter 'B' to go back to menu.\n";
    badInputs();

    return;
}

void addStock() {
    cout << "What product would you like to add: \n";

    string usrAdd;
    cin >> usrAdd;
    bool found = false;
    for(size_t i = 0; i < inventory.size(); i++) {
       if(inventory[i].name == usrAdd){
        found = true;
        cout << "Enter an amount: \n";
       int usrAmt = 0;
    cin >> usrAmt;
    for (size_t i = 0; i < inventory.size(); i++) {
      if (inventory[i].name == usrAdd) {
      inventory[i].quantity = inventory[i].quantity + usrAmt;
      }
    }
       }
    }
  
  if(found == false){
  cout << "There is no Product in our inventory, would you like to add it? \n" << "1.Yes \n" << "2.No \n";
  int yn = 0;
  cin >> yn;
  if(yn == 1){
  cout << "Enter an amount: \n";
       int usrAmt = 0;
    cin >> usrAmt;
    inventory.push_back({usrAdd, usrAmt});
  }

  if(yn == 2) {
    cout << "Understood please try again: \n";
    addStock();
  }
  
  }

    cout << "Added! What would you like to do next?\n"
         << "1.Back to menu\n"
         << "2.Add more stocks\n"
         << "3.View current inventory\n";

    int uInp = 0;
    cin >> uInp;
    if (uInp == 1) {
        return;
    }
    else if (uInp == 2) {
        addStock();
    }
    else {
        listAll();
        cout << "\n";
        cout << "Enter 'B' when you are finished! \n";
        badInputs();
        return;
    }
}

void removeStock() {
    cout << "What product would you like to remove: \n";

    string usrRem;
    cin >> usrRem;

    cout << "How many items would you like to remove? ";

    int usrNum;
    cin >> usrNum;

    for (size_t i = 0; i < inventory.size(); i++) {

        if (inventory[i].name == usrRem) {

            while (usrNum > inventory[i].quantity || usrNum < 1) {
                cout << "Number exceeds inventory or is invalid. There are only "
                     << inventory[i].quantity
                     << " Products. Please try again. \n";
                cin >> usrNum;
            }

            inventory[i].quantity = inventory[i].quantity - usrNum;
        }
    }
    cout << "Done! \n";
}

void searchProduct() {
       string uInput;
       cin >> uInput;
       bool found = false;
       for(size_t i = 0; i < inventory.size(); i++) {
        if(inventory[i].name == uInput) {
          found = true;
          cout << "We have " << inventory[i].quantity << " in stock!";
          cout << "\n";
          cout << "Enter 'B' when you are finished!";
          badInputs();
          return;
        }
       }
         if(found == false){
          cout << "There is no Product in our inventory, please try again. \n";
          searchProduct();
         }
  }
void mainMenu() {
    int userInput = 0;
    while (userInput != 5) {
    cout << "===== INVENTORY SYSTEM =====\n"
         << "1. View inventory\n"
         << "2. Add stock\n"
         << "3. Remove stock\n"
         << "4. Search product\n"
         << "5. Exit\n"
         << "Choose an option: ";
        cin >> userInput;
        if (userInput == 1) {
          cout << "===== Inventory List ===== \n";
            viewInventory();
        }

        if (userInput == 2) {
          cout << "===== Add Stock ===== \n";
            addStock();
        }

        if (userInput == 3) {
          cout << "===== Remove Stock ===== \n";
            removeStock();
        }

        if(userInput == 4) {
            cout << "===== Serarch for a Product! ===== \n"
       << "Please enter the Product you are looking for: \n";
          searchProduct();
        }
    }
   cout << "Thank you for your time!";
    return;
}

int main() {
    mainMenu();

    return 0;
}
