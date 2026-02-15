#include <iostream>
#include <string>
using namespace std;
string tobin(int n) {
    if (n == 0) return "0";

    string binary = "";
    while (n > 0) {
        binary = char('0' + (n % 2)) + binary;
        n /= 2;
    }
    return binary;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int ten, tenn;

    cout << "Число в десятичной: ";
    cin >> ten;
    tenn = ten << 1;

    cout << "В двоичной: " << tobin(ten) << endl;
    cout << "После сдвига = " << tobin(tenn);

    return 0;
}