#include <iostream>

using namespace std;

int findGreatestCommonDivisor(int firstNumber, int secondNumber) {
    while (secondNumber != 0) {
        int temporaryValue = firstNumber;
        while (temporaryValue >= secondNumber) {
            temporaryValue -= secondNumber;
        }
        firstNumber = secondNumber;
        secondNumber = temporaryValue;
    }
    return firstNumber;
}

int findLeastCommonMultiple(int firstNumber, int secondNumber) {
    int largestValue = (firstNumber > secondNumber) ? firstNumber : secondNumber;
    while (true) {
        if (largestValue % firstNumber == 0 && largestValue % secondNumber == 0) {
            return largestValue;
        }
        largestValue++;
    }
}

int main() {
    int firstNumber, secondNumber;
    cout << "Enter two numbers: ";
    cin >> firstNumber >> secondNumber;

    cout << "Greatest common divisor: " << findGreatestCommonDivisor(firstNumber, secondNumber) << endl;
    cout << "Least common multiple: " << findLeastCommonMultiple(firstNumber, secondNumber) << endl;

    return 0;
}
