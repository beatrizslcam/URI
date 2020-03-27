#include <iostream>

using namespace std;

int main()
{
    float A, B;
    cin >> A >> B;
    cout.precision(5);
    cout << "MEDIA = " << (A * 3.5 + B * 7.5) / 11 << endl;

    return 0;
}