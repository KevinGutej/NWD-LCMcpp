#include <iostream>

using namespace std;

int findGreatestCommonDivisorOld(int firstNumber, int secondNumber) {
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

int findLeastCommonMultipleOld(int firstNumber, int secondNumber) {
    int largestValue = (firstNumber > secondNumber) ? firstNumber : secondNumber;
    while (true) {
        if (largestValue % firstNumber == 0 && largestValue % secondNumber == 0) {
            return largestValue;
        }
        largestValue++;
    }
}

int findGreatestCommonDivisor(int firstNumber, int secondNumber) {
    while (secondNumber != 0) {
        int temp = secondNumber;
        secondNumber = firstNumber % secondNumber;
        firstNumber = temp;
    }
    return firstNumber;
}

int findLeastCommonMultiple(int firstNumber, int secondNumber) {
    return (firstNumber * secondNumber) / findGreatestCommonDivisor(firstNumber, secondNumber);
}

int main() {
    int firstNumber, secondNumber;

    cout << "Enter two numbers: ";
    cin >> firstNumber >> secondNumber;

    if (firstNumber <= 0 || secondNumber <= 0) {
        cout << "Please enter positive non-zero numbers." << endl;
        return 1;
    }

    cout << "Old Greatest Common Divisor: " << findGreatestCommonDivisorOld(firstNumber, secondNumber) << endl;
    cout << "Old Least Common Multiple: " << findLeastCommonMultipleOld(firstNumber, secondNumber) << endl;

    int gcd = findGreatestCommonDivisor(firstNumber, secondNumber);
    int lcm = findLeastCommonMultiple(firstNumber, secondNumber);

    cout << "New Greatest Common Divisor: " << gcd << endl;
    cout << "New Least Common Multiple: " << lcm << endl;

    return 0;
}
