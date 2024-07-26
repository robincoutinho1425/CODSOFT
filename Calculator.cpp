#include <iostream>
#include <stdexcept> 
#include <limits>    

using namespace std;

// Function to perform the arithmetic operation
double performOperation(double num1, double num2, char operation) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                throw runtime_error("Division by zero is not allowed.");
            }
            return num1 / num2;
        default:
            throw invalid_argument("Invalid operation.");
    }
}

int main() {
    // Main function starting
    double num1, num2;
    char operation;

    cout << "Welcome to the Basic Calculator!" << endl;

    // Input first number
    while (true) {
        cout << "Enter first number: ";
        cin >> num1;
        // handling the invalid inputs
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
             // Ignore invalid input
            cout << "Invalid input. Please enter a numeric value." << endl;
        } else {
            break;
        }
    }

    // Input second number
    while (true) {
        cout << "Enter second number: ";
        cin >> num2;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            // Ignore invalid input
            cout << "Invalid input. Please enter a numeric value." << endl;
        } else {
            break;
        }
    }

    // Input operation
    while (true) {
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            break;
        } else {
            cout << "Invalid operation. Please enter one of +, -, *, /." << endl;
        }
    }

    // Performing the operarions and handling errors 
    try {
        double result = performOperation(num1, num2, operation);
        cout << "Result: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    } catch (...) {
        cout << "An unexpected error occurred." << endl;
    }

    return 0;
}
