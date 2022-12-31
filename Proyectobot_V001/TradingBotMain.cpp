// Proyectobot_V001.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <stdlib.h>
#include "TradingBot_V001.h"

using namespace std;
using namespace TradingBot;

int main()
{
    //Catching actual time (day, month, year)
    string string_actual_time;
    TradingBot_getTimeCPU outsourcing_string_actual_time;
    string_actual_time = outsourcing_string_actual_time.getTimeCPU();
    std::cout << string_actual_time << '\n';

    //Excel time
    string string_specificValue;
    TradingBot_getSpecificValue outsourcing_string_specific_value;
    string_specificValue = outsourcing_string_specific_value.getSpecificValue(string_actual_time);

    //HitBTCInfo
    string string_balance, string_HEX;
    TradingBot_HitBTCDriver outsourcing_HitBTCDriver;
    //outsourcing_HitBTCDriver.erasePreviousBalance();
    outsourcing_HitBTCDriver.getBalance();
    outsourcing_HitBTCDriver.getHistoryTrades();
    outsourcing_HitBTCDriver.getCurrencyPrices();

    string HITquote[23] = {"EOSHIT", "NEOHIT", "LINKHIT",  "ADAHIT","DOTHIT", "FILHIT","IOTAHIT","XRPHIT","UNIHIT","SOLHIT", "XLMHIT", "FTTHIT","AAVEHIT","ZECHIT","XMRHIT","BCHHIT", 
        "DASHHIT","MATICHIT","XTZHIT","BNBHIT", "VETHIT", "TRXHIT","LTCHIT" };
    string BTCquote[39] = { "EOSBTC", "NEOBTC", "LINKBTC", "ADABTC", "DOTBTC", "FILBTC", "IOTABTC", "XRPBTC", "UNIBTC","SOLBTC", "XLMBTC", "FTTBTC", "AAVEBTC", "ZECBTC", "XMRBTC",
        "BCHBTC", "DASHBTC", "MATICBTC","XTZBTC","BNBBTC", "VETBTC", "TRXBTC", "LTCBTC", "HEXBTC", "ETHBTC", "GASBTC", "SNXBTC","MKRBTC", "BATBTC", "MANABTC", "CRVBTC", "DOGEBTC",
        "ETCBTC", "HITBTC", "ICXBTC", "ALGOBTC","ZRXBTC", "WBTCBTC", "REPBTC" };
    string ETHquote[34] = { "EOSETH", "NEOETH", "LINKETH", "ADAETH", "DOTETH", "IOTAETH", "XRPETH", "SOLETH", "XLMETH","FTTETH", "AAVEETH", "ZECETH", "XMRETH", "BCHETH", "DASHETH",
        "XTZETH", "BNBETH", "VETETH","TRXETH", "LTCETH", "GASETH", "SNXETH", "MKRETH", "BATETH", "MANAETH", "CRVETH", "DOGEETH", "ETCETH", "HITETH", "ICXETH", "ALGOETH", "ZRXETH",
        "WBTCETH", "REPETH" };
    string USDTquote[20] = {"EOSUSDT", "NEOUSDT", "LINKUSDT", "ADAUSDT", "DOTUSDT", "IOTAUSDT", "XRPUSDT", "SOLUSDT","XLMUSDT", "FTTUSDT", "AAVEUSDT", "ZECUSDT", "XMRUSDT", "BCHUSDT",
        "DASHUSDT", "XTZUSDT","BNBUSDT", "VETUSDT", "TRXUSDT", "LTCUSDT"};
    string DAIquote[5] = {"EOSDAI", "NEODAI", "XRPDAI", "XMRDAI", "LTCDAI"};
    string GUSDquote[3] = {"ETHGUSD", "BTCGUSD", "USDTGUSD"};
    cout << "\nPRECIOS\n" << endl;
    int i = 0;
    cout << "\tHIT quote" << endl;
    while (i < 23) {
        outsourcing_HitBTCDriver.getSpecificCurrencyPrice(HITquote[i]);
        i++;
    }
    i = 0;
    cout << "\n\n\tBTC quote" << endl;
    while (i < 39) {
        outsourcing_HitBTCDriver.getSpecificCurrencyPrice(BTCquote[i]);
        i++;
    }
    i = 0;
    cout << "\n\n\tETH quote" << endl;
    while (i < 34) {
        outsourcing_HitBTCDriver.getSpecificCurrencyPrice(ETHquote[i]);
        i++;
    }
    i = 0;
    cout << "\n\n\tUSDT quote" << endl;
    while (i < 20) {
        outsourcing_HitBTCDriver.getSpecificCurrencyPrice(USDTquote[i]);
        i++;
    }
    i = 0;
    cout << "\n\n\tDAI quote" << endl;
    while (i < 5) {
        outsourcing_HitBTCDriver.getSpecificCurrencyPrice(DAIquote[i]);
        i++;
    }
    i = 0;
    cout << "\n\n\tGUSD quote" << endl;
    while (i < 3) {
        outsourcing_HitBTCDriver.getSpecificCurrencyPrice(GUSDquote[i]);
        i++;
    }

    system("date >> BalancesListAux.txt");

    system("PAUSE");

    return 0;
}





//string EOSHIT = "EOSHIT", NEOHIT = "NEOHIT", LINKHIT = "LINKHIT", ADAHIT = "ADAHIT", DOTHIT = "DOTHIT", FILHIT = "FILHIT", IOTAHIT = "IOTAHIT", XRPHIT = "XRPHIT", UNIHIT = "UNIHIT",
//SOLHIT = "SOLHIT", XLMHIT = "XLMHIT", FTTHIT = "FTTHIT", AAVEHIT = "AAVEHIT", ZECHIT = "ZECHIT", XMRHIT = "XMRHIT", BCHHIT = "BCHHIT", DASHHIT = "DASHHIT", MATICHIT = "MATICHIT",
//XTZHIT = "XTZHIT", BNBHIT = "BNBHIT", VETHIT = "VETHIT", TRXHIT = "TRXHIT", LTCHIT = "LTCHIT";
//string EOSBTC = "EOSBTC", NEOBTC = "NEOBTC", LINKBTC = "LINKBTC", ADABTC = "ADABTC", DOTBTC = "DOTBTC", FILBTC = "FILBTC", IOTABTC = "IOTABTC", XRPBTC = "XRPBTC", UNIBTC = "UNIBTC",
//SOLBTC = "SOLBTC", XLMBTC = "XLMBTC", FTTBTC = "FTTBTC", AAVEBTC = "AAVEBTC", ZECBTC = "ZECBTC", XMRBTC = "XMRBTC", BCHBTC = "BCHBTC", DASHBTC = "DASHBTC", MATICBTC = "MATICBTC",
//XTZBTC = "XTZBTC", BNBBTC = "BNBBTC", VETBTC = "VETBTC", TRXBTC = "TRXBTC", LTCBTC = "LTCBTC", HEXBTC = "HEXBTC", ETHBTC = "ETHBTC", GASBTC = "GASBTC", SNXBTC = "SNXBTC",
//MKRBTC = "MKRBTC", BATBTC = "BATBTC", MANABTC = "MANABTC", CRVBTC = "CRVBTC", DOGEBTC = "DOGEBTC", ETCBTC = "ETCBTC", HITBTC = "HITBTC", ICXBTC = "ICXBTC", ALGOBTC = "ALGOBTC",
//ZRXBTC = "ZRXBTC", WBTCBTC = "WBTCBTC", REPBTC = "REPBTC";
//string EOSETH = "EOSETH", NEOETH = "NEOETH", LINKETH = "LINKETH", ADAETH = "ADAETH", DOTETH = "DOTETH", IOTAETH = "IOTAETH", XRPETH = "XRPETH", SOLETH = "SOLETH", XLMETH = "XLMETH",
//FTTETH = "FTTETH", AAVEETH = "AAVEETH", ZECETH = "ZECETH", XMRETH = "XMRETH", BCHETH = "BCHETH", DASHETH = "DASHETH", XTZETH = "XTZETH", BNBETH = "BNBETH", VETETH = "VETETH",
//TRXETH = "TRXETH", LTCETH = "LTCETH", GASETH = "GASETH", SNXETH = "SNXETH", MKRETH = "MKRETH", BATETH = "BATETH", MANAETH = "MANAETH", CRVETH = "CRVETH", DOGEETH = "DOGEETH",
//ETCETH = "ETCETH", HITETH = "HITETH", ICXETH = "ICXETH", ALGOETH = "ALGOETH", ZRXETH = "ZRXETH", WBTCETH = "WBTCETH", REPETH = "REPETH";
//string EOSUSDT = "EOSUSDT", NEOUSDT = "NEOUSDT", LINKUSDT = "LINKUSDT", ADAUSDT = "ADAUSDT", DOTUSDT = "DOTUSDT", IOTAUSDT = "IOTAUSDT", XRPUSDT = "XRPUSDT", SOLUSDT = "SOLUSDT",
//XLMUSDT = "XLMUSDT", FTTUSDT = "FTTUSDT", AAVEUSDT = "AAVEUSDT", ZECUSDT = "ZECUSDT", XMRUSDT = "XMRUSDT", BCHUSDT = "BCHUSDT", DASHUSDT = "DASHUSDT", XTZUSDT = "XTZUSDT",
//BNBUSDT = "BNBUSDT", VETUSDT = "VETUSDT", TRXUSDT = "TRXUSDT", LTCUSDT = "LTCUSDT";
//string EOSDAI = "EOSDAI", NEODAI = "NEODAI", XRPDAI = "XRPDAI", XMRDAI = "XMRDAI", LTCDAI = "LTCDAI";
//string ETHGUSD = "ETHGUSD", BTCGUSD = "BTCGUSD", USDTGUSD = "USDTGUSD";
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

