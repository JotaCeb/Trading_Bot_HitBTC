#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <stdlib.h>
#include "TradingBot_V001.h"

using namespace std;
using namespace TradingBot;

        string TradingBot_getTimeCPU::getTimeCPU(void) {

            time_t rawtime;
            struct tm* timeinfo;
            char* actual_time;
            string string_actual_time = "";
            string month = "";
            string day = "";

            time(&rawtime);
            timeinfo = localtime(&rawtime);
            actual_time = ctime(&rawtime);
            string_actual_time = actual_time;           //Time of my CPU

            string_actual_time.erase(0, 22);            //Delete everything until 22nd position

            month = to_string((timeinfo->tm_mon) + 1);  //Number of month of year
            if (stoi(month) < 10) {
                month = "0" + month;
            }

            day = to_string((timeinfo->tm_mday));       //Number of day of month
            if (stoi(day) < 10) {
                day = "0" + day;
            }
            string_actual_time = day + "-" + month + "-" + string_actual_time;
            return string_actual_time;
        }