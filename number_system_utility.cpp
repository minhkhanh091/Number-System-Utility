#include <iostream>
#include <algorithm>
#include <string>

class Convert {
public:
    std::string toBinary(uint64_t userInput) {
        if (userInput == 0) return "0";

        std::string binaryString = "";
        while (userInput > 0) {
            binaryString += (userInput % 2) ? '1' : '0';
            userInput /= 2;
        }
        std::reverse(binaryString.begin(), binaryString.end());
        return binaryString;
    }

    std::string toHexadecimal(uint64_t userInput) {
        if (userInput == 0) return "0";
        
        std::string hex = "";
        const char* hexDigits = "0123456789ABCDEF";

        while (userInput > 0) {
            hex += hexDigits[userInput % 16];
            userInput /= 16;
        }

        std::reverse(hex.begin(), hex.end());
        return hex;
    }
};

int menuSelector() {
    int userOptions_selected = -1;

    std::cout << "\nBinary Calculator" << std::endl;
    std::cout << "1. Decimal to Binary" << std::endl;
    std::cout << "2. Decimal to Hexadecimal" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> userOptions_selected;

    return userOptions_selected;
}

int main() {
    Convert converter;
    int choice;
    uint64_t userInput;

    while ((choice = menuSelector()) != 0) {
        std::cout << "Enter a decimal number: ";
        std::cin >> userInput;

        switch (choice) {
            case 1:
                std::cout << "Binary: " << converter.toBinary(userInput) << std::endl;
                break;
            case 2:
                std::cout << "Hexadecimal: " << converter.toHexadecimal(userInput) << std::endl;
                break;
            default:
                std::cout << "Invalid option." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
