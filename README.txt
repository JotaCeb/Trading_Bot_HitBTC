Readme

1. Create an account at Exchange Hitbtc
2. Generate an API key
3. Copy the API key and the secretkey in each function of the Hitbtcdriver.cpp
	Theoretical example: curl -u "Apikey: secretkey" https://api.hitbtc.com/api/3/spot/balance
	Practical example: curl -U HXQSCGPUAP4SBH1Y4SCQ0RIK5YHSPEZN: HJ9PCR3D0I8 -_BDGMBKYDBJFGKY

4. By default the information will be placed in the BalancesListAux.txtfile

5. You just have to double click here Proyectobot_V001.exe and to see the result in BalancesListAux.txt

WARNINGS:
	The bot does not buy or sell. Only offers the base on which to build
	All information was extracted from https://api.hitbtc.com/
	If you do not want to buy and sell generate an API key that does not allow you to buy and sell
	If you want to buy and sell, extract these commands from https://api.hitbtc.com/ and generate an API key that allows you to buy and sell