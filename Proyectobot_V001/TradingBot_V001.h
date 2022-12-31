#pragma once
#include <string>

using namespace std;

    namespace TradingBot
    {
        //TimeCPU
        class TradingBot_getTimeCPU
        {
        public:
            string getTimeCPU();
        };
        //ExcelData
        class TradingBot_getSpecificValue
        {
        public:
            string getSpecificValue(string);
        };
        //HitBTCDriver
        class TradingBot_HitBTCDriver
        {
        public:
            void getBalance();
        public:
            void erasePreviousBalance();
        public:
            void getHistoryTrades();
        public:
            void getCurrencyPrices();
        public:
            string getSpecificCurrencyPrice(string);
        public:
            void getPreviousDate();
        };
    }

