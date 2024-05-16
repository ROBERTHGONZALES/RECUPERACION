#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream inputFile("horas.txt"); 
    ofstream outputFile("informe_horas_totales.txt"); 

    string line;
    map<string, int> horasTrabajadas; 


    while (getline(inputFile, line)) {
        istringstream iss(line);
        string nombre;
        int horas;
        char delim;


        getline(iss, nombre, ',');
        iss >> horas;

        horasTrabajadas[nombre] += horas;
    }

    for (const auto& entry : horasTrabajadas) {
        outputFile << entry.first << ", Horas Totales: " << entry.second << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Ok revisar: 'informe_horas_totales.txt'." << endl;

    return 0;
}

