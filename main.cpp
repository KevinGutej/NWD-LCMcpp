#include <iostream>

using namespace std;

int findGreatestCommonDivisor(int firstNumber, int secondNumber) {
    while (firstNumber != secondNumber) {
        if (firstNumber > secondNumber) {
            firstNumber -= secondNumber;
        } else {
            secondNumber -= firstNumber;
        }
    }
    return firstNumber;
}

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

int findLeastCommonMultiple(int firstNumber, int secondNumber) {
    int maxVal = (firstNumber > secondNumber) ? firstNumber : secondNumber;
    int step = maxVal;
    while (true) {
        if (maxVal % firstNumber == 0 && maxVal % secondNumber == 0) {
            return maxVal;
        }
        maxVal += step;
    }
}

int findLeastCommonMultipleOld(int firstNumber, int secondNumber) {
    int largestValue = (firstNumber > secondNumber) ? firstNumber : secondNumber;
    while (true) {
        int temp = largestValue;
        while (temp >= firstNumber) {
            temp -= firstNumber;
        }
        if (temp == 0) {
            temp = largestValue;
            while (temp >= secondNumber) {
                temp -= secondNumber;
            }
            if (temp == 0) {
                return largestValue;
            }
        }
        largestValue++;
    }
}

int main() {
    int firstNumber, secondNumber;

    cout << "Enter two positive numbers: ";
    cin >> firstNumber >> secondNumber;

    if (firstNumber <= 0 || secondNumber <= 0) {
        cout << "Error: Please enter positive, non-zero numbers." << endl;
        return 1;
    }

    cout << "Old Greatest Common Divisor: " << findGreatestCommonDivisorOld(firstNumber, secondNumber) << endl;
    cout << "New Greatest Common Divisor: " << findGreatestCommonDivisor(firstNumber, secondNumber) << endl;
    cout << "Old Least Common Multiple: " << findLeastCommonMultipleOld(firstNumber, secondNumber) << endl;
    cout << "New Least Common Multiple: " << findLeastCommonMultiple(firstNumber, secondNumber) << endl;

    return 0;
}
