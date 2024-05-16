#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream inputFile("errores.txt"); 
    ofstream outputFile("informe_errores.txt"); 

    string line;
    map<string, int> numerror; // Mapa para almacenar las horas totales por empleado

    // Leer el archivo línea por línea
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string nombre, tiperror;
    
        char delim;

        getline(iss, nombre, ',');
        iss >> tiperror;


        numerror[nombre] += 1;
    }

    // Escribir los resultados en el archivo de salida
    for (const auto& entry : numerror) {
        outputFile << entry.first  << entry.second << endl;
    }

    // Cerrar los archivos
    inputFile.close();
    outputFile.close();

    cout << "Ok revisar: 'informe_errores.txt'." << endl;

    return 0;
}

