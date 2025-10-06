#include<iostream>
using namespace std;
#include<fstream>
#include<string>

int main() {
    ifstream myfile("test.txt");
    string line;

    cout << "Content of the file:\n";
    while (getline(myfile, line)) {
        cout << line << endl;
    }
    myfile.close();

    ifstream infile("test.txt");
    ofstream outfile("encrypted.txt");
    char key = 'c';
    cout << "Encrypted File content:\n";
    while (getline(infile, line)) {
        for (char &ch : line) {
            ch = ch ^ key;
        }
        cout << line << endl;
        outfile << line << endl;
    }
    infile.close();
    outfile.close();

    return 0;
}