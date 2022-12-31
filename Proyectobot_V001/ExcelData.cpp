#include <iostream>
#include<fstream>
#include<sstream>
#include "TradingBot_V001.h"

using namespace std;
using namespace TradingBot;

string TradingBot_getSpecificValue::getSpecificValue(string string_actual_time) {

    string line, FECHA, PRINCIPAL,SUPERIOR,INFERIOR,ACTUAL,EN_VENTA,EN_COMPRA;
    int aux;
    ifstream myfile("TradingBotPrice.csv");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            FECHA = line;
            aux = FECHA.size();
            FECHA = FECHA.erase(8, aux) + "\n";
            if (FECHA == string_actual_time) {
                //Extract the price values
                PRINCIPAL = line.substr(9, 13);
                SUPERIOR = line.substr(23, 13);
                INFERIOR = line.substr(37, 13);
                FECHA = FECHA.erase(8, 2);
                cout << "Fecha actual:     " + FECHA << endl;
                cout << "Precio principal: " + PRINCIPAL << endl;
                cout << "Precio superior:  " + SUPERIOR << endl;
                cout << "Precio inferior:  " + INFERIOR << endl;
                break;
            }
        }
        myfile.close();
    }
    return PRINCIPAL;
}