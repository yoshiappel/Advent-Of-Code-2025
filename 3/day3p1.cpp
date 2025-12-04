#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();

    string flinput;
    ifstream File("flinput.txt");

    int final = 0;

    while (getline(File, flinput))
    {
        int temp = 0;
        int high = 0;
        for (int i = 0; i < flinput.length(); i++) {
            int tempinput = flinput[i] - '0';
            if (i == flinput.length() - 1 && temp < tempinput)
            {
                temp = tempinput;
                break;
            }
            
            if (tempinput > high)
            {
                high = tempinput;
                temp = 0;
            } else if (tempinput > temp) {
                temp = tempinput;
            }
        }
        final += high * 10 + temp; 
    }

    cout << final << "is" << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << duration.count() << " microseconds" << " or " << duration.count() / 1000000.0 << " seconds" << endl;
    return 0;
}