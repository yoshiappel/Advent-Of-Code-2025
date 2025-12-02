#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

int Check(string dir, int end, int& password, int& count) {
    int max = 100;
    int min = 0;
    if (dir == "L") {
        password -= end;
        while (password < min) {
            if (password + end != 0)
                count++;

            int temp = abs(password);
            password = max - temp;
        }
        if (password == 0)
            count++;
    } else {
        password += end;
        while (password >= max) {
            count++;

            int temp = password - max;
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
        
        password = Check(dir, end, password, count);
    }

    MyReadFile.close(); 
    cout << count << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << duration.count() << endl;
    return 0;
}