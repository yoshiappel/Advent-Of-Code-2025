#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();

    string input;
    ifstream File("input.txt");

    string temp1;
    string temp2;

    int_fast64_t num1;
    int_fast64_t num2;
    int_fast64_t count = 0;

    while (getline (File, input, ',')) {
        int pos = input.find("-");

        temp1 = input.substr(0, pos);
        temp2 = input.substr(pos + 1);

        num1 = stoll(temp1);
        num2 = stoll(temp2);

        string tempVar1;
        string tempVar2;

        if (num1 != 0) {
            for (int_fast64_t i = num1; i <= num2; i++) {
                string p = to_string(i);
                
                if (p.length() % 2 == 0) {
                    int_fast64_t half = p.length() / 2;
                    tempVar1 = p.substr(0, half);
                    tempVar2 = p.substr(half, half);
                    if (tempVar1 == tempVar2) {
                        count += stoll(p);
                    } 
                }
            }
        }
    }

    File.close(); 

    cout << "= " << count << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << duration.count() << endl;
    return 0;
}