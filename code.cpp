/***********************************************************
*   Автор: Кадесников Михаил                               *
*   Дата: 02.12.2022                                       *
*   Название: Римские цифры                                *
************************************************************/

#include <iostream>

using namespace std;

string toRoman(int value){
  struct romanData {int value; char const* numeral; };
   struct romanData romandata[] = {
        {1000, "M"}, {900, "CM"},
        {500, "D"}, {400, "CD"},
        {100, "C"}, { 90, "XC"},
        { 50, "L"}, { 40, "XL"},
        { 10, "X"}, { 9, "IX"},
        { 5, "V"}, { 4, "IV"},
        { 1, "I"},
    };
  string result;
  for (romanData* current = romandata; current->value > 0; ++current){
    while (value >= current->value){
      result += current->numeral;
      value -= current->value;
    }
  }
  return result;
};

int value(char romanSymbol) {
	if (romanSymbol == 'I')
	  return 1;
	if (romanSymbol == 'V')
		return 5;
	if (romanSymbol == 'X')
		return 10;
	if (romanSymbol == 'L')
		return 50;
	if (romanSymbol == 'C')
		return 100;
	if (romanSymbol == 'D')
		return 500;
	if (romanSymbol == 'M')
		return 1000;
	return -1;
}

int romanToDecimal(string& str) {
	int result = 0;
	for (int index = 0; index < str.length(); index++) {
		int symbol1 = value(str[index]);
		if (index + 1 < str.length()) {
			int symbol2 = value(str[index + 1]);
			if (symbol1 >= symbol2) {
				result = result + symbol1;
      } else {
				result = result + symbol2 - symbol1;
				index++;
			}
		} else {
			result = result + symbol1;
		}
	}
	return result;
}

int main() {
  string numberRO;
  int numberAR, turnNUMB;
    
  cout << "Для перевода арабских цифр в римские нажмите 1" << endl;
  cout << "Для перевода римских цифр в арабские нажмите 2" << endl << ": ";
  cin >> turnNUMB;
    
  if(turnNUMB == 1){
    cout << "Введите число(от 1 до 3999): ";
    cin >> numberAR;
    cout << toRoman(numberAR);
  }
    
  if(turnNUMB == 2){
    cout << "Введите число(от I до MMMCMXCIX): ";
    cin >> numberRO;
    cout << romanToDecimal(numberRO);
  }
    
  if(turnNUMB != 1 && turnNUMB != 2) {
    cout << "Некорректный ввод";
  }
    
  return 0;
}
