#include <iostream>
#include<fstream>

#include <string>
//#include<sstream>
#include "TradingBot_V001.h"
//#include "windows.h"
//#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <chrono>

using namespace std;
using namespace TradingBot;

void TradingBot_HitBTCDriver::erasePreviousBalance() {
    ifstream myfile("BalancesList.txt");
    myfile.close();
    if (myfile.is_open()) {
        cout << "No se puede cerrar el archivo de BalancesList:  " << endl;
    }
    else {
        remove("BalancesList.txt");
        cout << "\nArchivo BalancesList.txt borrado\n" << endl;
    } 
    //Sleep(1500);
}

void TradingBot_HitBTCDriver::getBalance() {
    string line, aux_line, aux_allText;
    int i = 0;

    system("curl -u hxQscgPuAp4sBh1y4scQ0rik5YhSpeZn:hj9pcr3d0I8-_bdGMBkvyDBjfGKY68jG https://api.hitbtc.com/api/3/spot/balance > BalancesListAux.txt");
    cout << "Nuevo archivo BalancesListAux.txt creado\n" << endl;
    //Sleep(1500);
    fstream myfile("BalancesListAux.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            aux_line = line;
            //Converting one line into various
            for (i = 0; i <= line.length(); i++) {
                if (line[i] == '}' && line[i + 1] == ',') {
                    aux_line[i] = '\r';
                    aux_line[i + 1] = '\n';
                }
            }
            //Writing in archive BalancesList.txt
            myfile.close(); while (i < 10000)i++;
            fstream myfile("BalancesListAux.txt", ios::out | ios::trunc);
            line = aux_line;
            myfile << aux_line;
            myfile.close(); while (i < 10000)i++;
            line = "";
            //Putting everything clean from BalancesList.txt to cout
            myfile.open("BalancesListAux.txt");
            aux_allText = "BALANCES\n";
            while (getline(myfile, line)) {
                size_t pos = line.find(":");           // position of ":" in line
                line.erase(0, pos + 2); while (i < 10000)i++;
                pos = line.find(","); while (i < 10000)i++;
                line.erase(pos - 1, 3); while (i < 10000)i++;
                pos = line.find(":"); while (i < 10000)i++;
                line.erase(pos - 1, 3); while (i < 10000)i++;
                pos = line.find(","); while (i < 10000)i++;
                line.erase(pos - 1, 3); while (i < 10000)i++;
                pos = line.find(":"); while (i < 10000)i++;
                line.erase(pos - 1, 3); while (i < 10000)i++;
                pos = line.find(","); while (i < 10000)i++;
                line.erase(pos); while (i < 10000)i++;
                aux_allText = aux_allText + line + '\n';
            }
            myfile.close(); while (i < 10000)i++;
            myfile.open("BalancesListAux.txt"); while (i < 10000)i++;
            //Deleting and writing the final data of Balances
            myfile.close(); while (i < 10000)i++;
            myfile.open("BalancesListAux.txt", std::ofstream::out | std::ofstream::trunc); while (i < 10000)i++;
            myfile << aux_allText + '\n';
            myfile.close(); while (i < 10000)i++;
            myfile.open("BalancesListAux.txt"); while (i < 10000)i++;
            string aux_allText2 = "";
            while (getline(myfile, line)) {
                if (line.length() > 9) {
                    //Space bar btween currency and available
                    size_t pos = line.find("available");           // position of ":" in line
                    aux_line = line.substr(0, pos);
                    for (i = pos; i <= 6; i++) {

                        aux_line = aux_line + " ";
                    }
                    aux_line = aux_line + "Av: ";
                    //Finding .
                    pos = line.find("reserved");
                    size_t pos2 = line.find(".");
                    if (line[pos2 - 2] == 'd' || line[pos2 - 3] == 'd' || line[pos2 - 4] == 'd' || line[pos2 - 5] == 'd'
                        || line[pos2 - 6] == 'd' || line[pos2 - 7] == 'd'|| line[pos2 - 8] == 'd') {
                        aux_line = aux_line + "     0";
                    }
                    else if(line[pos2 - 2] == 'e') {
                        aux_line = aux_line + "     " + line.substr(pos2 - 1, pos - pos2 + 1);
                        if (aux_line.length() > 24) {
                            aux_line.erase(24);
                        }
                    }
                    else if (line[pos2 - 3] == 'e') {
                        aux_line = aux_line + "    " + line.substr(pos2 - 2, pos - pos2+2);
                        if (aux_line.length() > 24) {
                            aux_line.erase(24);
                        }
                    }
                    else if (line[pos2 - 4] == 'e') {
                        aux_line = aux_line + "   " + line.substr(pos2 - 3, pos - pos2+3);
                        if (aux_line.length() > 24) {
                            aux_line.erase(24);
                        }
                    }
                    else if (line[pos2 - 5] == 'e') {
                        aux_line = aux_line + "  " + line.substr(pos2 - 4, pos - pos2+4);
                        if (aux_line.length() > 24) {
                            aux_line.erase(24);
                        }
                    }
                    else {
                        aux_line = aux_line + " " + line.substr(pos2 - 5, pos - pos2+5);
                        if (aux_line.length() > 24) {
                            aux_line.erase(24);
                        }
                    }
                    while (aux_line.length() < 30) {
                        aux_line = aux_line + " ";
                    }
                    aux_line = aux_line + "Res: ";

                    //Finding d
                    pos = line.find("d");
                    if (line[pos + 1] == '0' && line[pos + 2] == '"') {
                        aux_line = aux_line + "     0";
                    }
                    else if (line[pos + 2] == '.') {
                        aux_line = aux_line + "     " + line.substr(pos + 1, 8);
                    }
                    else if (line[pos + 3] == '.') {
                        aux_line = aux_line + "    " + line.substr(pos + 1, 9);
                    }
                    else if (line[pos + 4] == '.') {
                        aux_line = aux_line + "   " + line.substr(pos + 1, 10);
                    }
                    else if (line[pos + 5] == '.') {
                        aux_line = aux_line + "  " + line.substr(pos + 1, 11);
                    }
                    else {
                        aux_line = aux_line + " " + line.substr(pos + 1, 12);
                    }
   
                    aux_allText2 = aux_allText2 + aux_line + '\n';
                }
            }

            //Deleting and writing the final data of Balances
            myfile.close(); while (i < 10000)i++;
            myfile.open("BalancesList.txt", std::ofstream::out | std::ofstream::trunc); while (i < 10000)i++;
            myfile << aux_allText2;
            myfile.close(); while (i < 10000)i++;
            cout << aux_allText2;
        }
    }
}

void TradingBot_HitBTCDriver::getHistoryTrades() {
    string line, aux_line, aux_allText;
    int i = 0;
    system("curl -u hxQscgPuAp4sBh1y4scQ0rik5YhSpeZn:hj9pcr3d0I8-_bdGMBkvyDBjfGKY68jG https://api.hitbtc.com/api/3/spot/history/trade?symbol=HEXBTC >> BalancesListAux.txt");
    cout << "\nTRADES EJECUTADOS\n" << endl;
    ifstream myfile("BalancesListAux.txt");
    //myfile.open("BalancesListAux.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            //Converting one line into various
            int line_length = line.length();
            for (i = 0; i <= line_length; i++) {
                if (line[i] == '}') {
                    //line[i] = '\r';
                    line[i + 1] = '\n';
                }
                else if (line[i] == '[' && line[i + 1] == '{') {
                    //int pos_EXECUTEDTRADES = 0;
                    aux_allText = aux_allText + "\nEXECUTED TRADES\n";
                    //pos_EXECUTEDTRADES = aux_allText.find("EXECUTED TRADES");
                }
                //else if (line.length() == (line.length() - int (2))) {
                //    aux_allText = aux_allText + line;
                //}
            }
            aux_allText = aux_allText + line + '\n';                  
        }
        //Writing in archive BalancesListAux.txt
        ofstream myfile("BalancesListAux.txt");
        myfile << aux_allText << endl;  while (i < 100000)i++;
        cout << aux_allText;
        myfile.close(); while (i < 10000)i++;
    }
}

void TradingBot_HitBTCDriver::getCurrencyPrices() {

    string line, aux_allText;
    int i = 0;
    bool flag_prices = false;

    system("curl https://api.hitbtc.com/api/3/public/price/ticker >> BalancesListAux.txt");
    cout << "\nPRECIOS\n" << endl;
    fstream myfile("BalancesListAux.txt");
    //myfile.open("BalancesListAux.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            //Converting one line into various
            int line_length = line.length();
            for (i = 0; i <= line_length; i++) {
                if (line[i] == '}' && line[i+1] == ',') {
                    //line[i] = '\r';
                    line[i + 1] = '\n';
                }
                else if (line[i] == '{' && line[i + 1] == '"' && line[i + 2] != 'i' && line[i + 3] != 'd' && flag_prices == false) {
                    //int pos_EXECUTEDTRADES = 0;
                    flag_prices = true;
                    aux_allText = aux_allText + "\nPRICES\n";
                    //pos_EXECUTEDTRADES = aux_allText.find("EXECUTED TRADES");
                }
            }
            aux_allText = aux_allText + line + '\n';
        }
        //Writing in archive BalancesListAux.txt
        ofstream myfile("BalancesListAux.txt");
        myfile << aux_allText << endl;  while (i < 100000)i++;
        myfile.close(); while (i < 10000)i++;
    }
}

string TradingBot_HitBTCDriver::getSpecificCurrencyPrice(string pair) {

    string line, aux_line, aux_price;
    int i = 0, pos1, pos2, pos3, pos4;

    fstream myfile("BalancesListAux.txt");
    ////myfile.open("BalancesListAux.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            //Converting one line into various
            int line_length = line.length();
            pos1 = 0;
            pos1 = line.find(pair);
            if (pos1 < 3 && pos1 > 0) {
                pos2 = line.find("price");
                if (pos2 < 16) {
                    aux_line = pair;
                    while (aux_line.length() < 8) {
                        aux_line = aux_line + " ";
                    }
                    pos3 = line.find('.');
                    pos4 = line.find("timestamp");

                    if ((pos3 - pos2) == 16) aux_line = aux_line + line.substr(pos3 - 8, pos4 - pos3 + 8 - 4);
                    else if ((pos3 - pos2) == 15) aux_line = aux_line + " " + line.substr(pos3 - 7, pos4 - pos3 + 7 - 4);
                    else if ((pos3 - pos2) == 14) aux_line = aux_line + "  " + line.substr(pos3 - 6, pos4 - pos3 + 6 - 4);
                    else if ((pos3 - pos2) == 13) aux_line = aux_line + "   " + line.substr(pos3 - 5, pos4 - pos3 + 5 - 4);
                    else if ((pos3 - pos2) == 12) aux_line = aux_line + "    " + line.substr(pos3 - 4, pos4 - pos3 + 4 - 4);
                    else if ((pos3 - pos2) == 11) aux_line = aux_line + "     " + line.substr(pos3 - 3, pos4 - pos3 + 3 - 4);
                    else if ((pos3 - pos2) == 10) aux_line = aux_line + "      " + line.substr(pos3 - 2, pos4 - pos3 + 2 - 4);
                    else if ((pos3 - pos2) == 9) aux_line = aux_line +  "       " + line.substr(pos3 -1, pos4 - pos3 + 1 -4);
                    else if ((pos3 - pos2) == 8) aux_line = aux_line +  "        " + line.substr(pos3, pos4 - pos3 - 4);
                        cout << aux_line << endl;
                } 
            }

            //for (i = 0; i <= line_length; i++) {
            //    if (line[i] == '}' && line[i + 1] == ',') {
            //        //line[i] = '\r';
            //        line[i + 1] = '\n';
            //    }
            //    else if (line[i] == '{' && line[i + 1] == '"' && line[i + 2] != 'i' && line[i + 3] != 'd' && flag_prices == false) {
            //        //int pos_EXECUTEDTRADES = 0;
            //        flag_prices = true;
            //        aux_allText = aux_allText + "\nPRICES\n";
            //        //pos_EXECUTEDTRADES = aux_allText.find("EXECUTED TRADES");
            //    }
            //}
            //aux_allText = aux_allText + line + '\n';
        }
        //Writing in archive BalancesListAux.txt
        //ofstream myfile("BalancesListAux.txt");
        //myfile << aux_allText << endl;  while (i < 100000)i++;
        //cout << aux_allText;
        //myfile.close(); while (i < 10000)i++;
    }
    return line;
}

void TradingBot_HitBTCDriver::getPreviousDate() {
    int i = 0, pos = 0, pos2 = 200;
    string line;
    string Month[12] = {"Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic"};
    string aux_day;

    fstream myfile("BalancesListAux.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            pos = line.find(':');
            pos2 = line.find("La fecha actual es: ");
                if (pos2 == 0) {

            }
            //Converting one line into various
            int line_length = line.length();
            for (i = 0; i <= line_length; i++) {
                if (line[i] == '}') {
                    //line[i] = '\r';
                    line[i + 1] = '\n';
                }
                else if (line[i] == '[' && line[i + 1] == '{') {
                    //int pos_EXECUTEDTRADES = 0;
                    aux_allText = aux_allText + "\nEXECUTED TRADES\n";
                    //pos_EXECUTEDTRADES = aux_allText.find("EXECUTED TRADES");
                }
                //else if (line.length() == (line.length() - int (2))) {
                //    aux_allText = aux_allText + line;
                //}
            }
            aux_allText = aux_allText + line + '\n';
        }
        //Writing in archive BalancesListAux.txt
        ofstream myfile("BalancesListAux.txt");
        myfile << aux_allText << endl;  while (i < 100000)i++;
        cout << aux_allText;
        myfile.close(); while (i < 10000)i++;
    }

}