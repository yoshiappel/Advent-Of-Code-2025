#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

int Check(string dir, int end, int password) {
    int max = 100;
    int min = 0;
    if (dir == "L") {
        password = password -= end;
        while (password < min) {
            int temp = 0;
            temp = abs(password);
            password = max - temp;
        }
    } else {
        password = password += end;
        while (password >= max) {
            int temp = 0;
            temp = password - max;
            password = min + temp;
        }
    }
    return password;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    int password = 50;
    int count = 0;

    string input;
    string dir;
    int pos;

    ifstream MyReadFile("input.txt");

    while (getline (MyReadFile, input)) {

        pos = input.find("L");
        dir = "L";
        if (pos < 0) {
            dir = "R";
        }

        int end = stoi(input.substr(1));
        
        password = Check(dir, end, password);

        if (password == 0) {
            count++;
        }
    }

    MyReadFile.close(); 

    cout << "het is: " << count << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << duration.count() << endl;
    return 0;
}