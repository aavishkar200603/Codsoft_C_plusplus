#include <bits/stdc++.h>
using namespace std;

class Calculator {
public:
    float add(float num1, float num2) {
        return num1 + num2;
    }

    float subtract(float num1, float num2) {
        return num1 - num2;
    }

    float multiply(float num1, float num2) {
        return num1 * num2;
    }

    float divide(float num1, float num2) {
        if (num2 != 0) {
            return num1 / num2;
        } else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

float getInput() {
    float num;
    cout << "Enter a number: ";
    cin >> num;
    return num;
}

void performCalculations() {
    Calculator calc;
    float num1, num2, res;
    int choice;

    do {
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n\n";
        cout << "Enter Your Choice (1-5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            num1 = getInput();
            num2 = getInput();
        }

        switch (choice) {
            case 1:
                res = calc.add(num1, num2);
                cout << "\nResult = " << res;
                break;
            case 2:
                res = calc.subtract(num1, num2);
                cout << "\nResult = " << res;
                break;
            case 3:
                res = calc.multiply(num1, num2);
                cout << "\nResult = " << res;
                break;
            case 4:
                res = calc.divide(num1, num2);
                break;
            case 5:
                return;
            default:
                cout << "\nWrong Choice!";
                break;
        }

        if (choice != 5) {
            cout << "\n------------------------\n";
        }

    } while (choice != 5);
}

int main() {
    performCalculations();
    return 0;
}
