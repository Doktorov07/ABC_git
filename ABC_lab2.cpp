
#include <iostream>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <limits>

using namespace std;

union FloatPointer {
    float f;
    struct {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } parts;
    uint32_t raw;
};

void printIEEE754(float num) {
    FloatPointer fp;
    fp.f = num;

    cout << "shislo " << setw(10) << fp.f
        << " | znak " << fp.parts.sign
        << " | exponenta " << bitset<8>(fp.parts.exponent)
        << " | mantissa " << bitset<23>(fp.parts.mantissa)
        << " | HEX: 0x" << hex << fp.raw << dec << endl;
}

float Maximum(const vector<float>& arr) {
    if (arr.empty()) return 0.0f;

    float max = arr[0];

    for (float x : arr) {
        if (isnan(max) || x > max) {
            max = x;
        }
    }
    return max;
}

int main() {
    vector<float> data = {
        1.5f,
        -2.75f,
        10.25f,
        0.0f,
        -0.0f,
        numerlim<float>::infinity(),
        -numerlim<float>::infinity()
    };

    cout << " IEEE 754:" << endl;
    cout << string(90, '-') << endl;

    for (float n : data) {
        printIEEE754(n);
    }

    float maxres = Maximum(data);
    cout << string(90, '-') << endl;
    cout << "max masiv " << maxres << endl;
    cout << "Bitu ";
    printIEEE754(maxres);

    return 0;
}