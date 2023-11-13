#include <iostream>
#include <string>
#include <vector>

struct Item {
    std::string code;
    std::string description;
    double price;
};

double calculatePrice(std::vector<Item>& items) {
    double total = 200; // cost of basic components
    for (const auto& item : items) {
        total += item.price;
    }
    return total;
}

int main() {
    std::vector<Item> items = {
        {"A1", "Compact", 75.00},
        {"A2", "Tower", 150.00},
        {"B1", "8 GB", 79.99},
        {"B2", "16 GB", 149.99},
        {"B3", "32 GB", 299.99},
        {"C1", "1 TB HDD", 49.99},
        {"C2", "2 TB HDD", 89.99},
        {"C3", "4 TB HDD", 129.99},
        {"D1", "240 GB SSD", 59.99},
        {"D2", "480 GB SSD", 119.99},
        {"E1", "1 TB HDD", 49.99},
        {"E2", "2 TB HDD", 89.99},
        {"E3", "4 TB HDD", 129.99},
        {"F1", "DVD/Blu-Ray Player", 50.00},
        {"F2", "DVD/Blu-Ray Re-writer", 100.00},
        {"G1", "Standard Version", 100.00},
        {"G2", "Professional Version", 175.00}
    };

    std::vector<Item> chosenItems;
    std::string code;
    std::cout << "Enter item codes (enter 'done' when finished): ";
    while (std::cin >> code && code != "done") {
        for (const auto& item : items) {
            if (item.code == code) {
                chosenItems.push_back(item);
                break;
            }
        }
    }

    double price = calculatePrice(chosenItems);
    std::cout << "The price of the computer is: $" << price << std::endl;

    // Ask the customer if they want to purchase any additional items
    std::cout << "Do you want to purchase any additional items? (yes/no): ";
    std::string response;
    std::cin >> response;
    if (response == "yes") {
        std::cout << "Enter item codes (enter 'done' when finished): ";
        while (std::cin >> code && code != "done") {
            for (const auto& item : items) {
                if (item.code == code) {
                    chosenItems.push_back(item);
                    break;
                }
            }
        }

        // Update the price of the computer
        price = calculatePrice(chosenItems);
        std::cout << "The new price of the computer is: $" << price << std::endl;
    }

    // Apply a discount if applicable
    double discount = 0;
    if (chosenItems.size() == 1) {
        discount = 0.05; // Apply a 5% discount
    }
    else if (chosenItems.size() >= 2) {
        discount = 0.10; // Apply a 10% discount
    }
    double savings = price * discount;
    price -= savings;
    std::cout << "You saved: $" << savings << std::endl;
    std::cout << "The final price of the computer after the discount is: $" << price << std::endl;

    return 0;
}
