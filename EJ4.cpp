#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ifstream inputFile("TEMPERATURAS.txt"); 
    ofstream outputFile("maximo_minimo_temperatura.txt"); 

    string line;
    string fechaMax, fechaMin;
    float tempMax = -50;
    float tempMin = 200;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string fecha;
        float temperatura;
        char delim;

        getline(iss, fecha, ',');
        iss >> temperatura;

        if (temperatura > tempMax) {
            tempMax = temperatura;
            fechaMax = fecha;
        }
        if (temperatura < tempMin) {
            tempMin = temperatura;
            fechaMin = fecha;
        }
    }

    outputFile << "Fecha con temperatura máxima: " << fechaMax << "  -  " << tempMax << endl;
    outputFile << "Fecha con temperatura mínima: " << fechaMin << "  -  " << tempMin << endl;

    inputFile.close();
    outputFile.close();

    cout << "Ok revisar: 'maximo_minimo_temperatura.txt'." << endl;

    return 0;
}

