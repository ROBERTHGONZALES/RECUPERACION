#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ifstream inputFile("VENTAS.txt"); 
    ofstream outputFile("DATOS_FINAL.txt"); 

    string line;
    string fechaMax, fechaMin;
    float VENTMAX = -1;
    float VENTMIN = 99999999;
    float suma=0;
    int rango=0;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string fecha;
        float VENTAS;
        char delim;

        getline(iss, fecha, ',');
        iss >> VENTAS;
        suma+=VENTAS;
        if (VENTAS > VENTMAX) {
            VENTMAX = VENTAS;
            fechaMax = fecha;
        }
        if (VENTAS < VENTMIN) {
            VENTMIN = VENTAS;
            fechaMin = fecha;
        }
        rango++;
    }

    outputFile << "Fecha con temperatura m�xima: " << fechaMax << "  -  " << VENTMAX << endl;
    outputFile << "Fecha con temperatura m�nima: " << fechaMin << "  -  " << VENTMIN << endl;
    outputFile << "VENTAS TOTALES " << suma << endl;
    outputFile << "promedio de ventas " << suma/rango << endl;
    
    inputFile.close();
    outputFile.close();

    cout << "Ok revisar: 'DATOS_FINAL.txt'." << endl;

    return 0;
}

