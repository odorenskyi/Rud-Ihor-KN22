#include <iostream>
#include <ModulesRud.h>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "uk_UA.UTF-8");
    double result[10] = {-3.0735,-13.1155,-32.0985,-44.1264,35.9927,613.491,3648,19035,99100,532936};
    double x_Y = 2;
    int lengthOfResult = sizeof(result) / sizeof(double);
    for(int i = 0;i<lengthOfResult;i++)
    {
        if(abs(result[i] - s_calculation(x_Y,x_Y)) < 1.0){
           cout << "x = "<< x_Y << " y="<< x_Y << " Вихідне значення: "<< s_calculation(x_Y,x_Y) <<" Тест номер: " << i << "# PASSED" << endl;
        }else{
            cout << "x = "<< x_Y << " y="<< x_Y <<" Вихідне значення: "<< s_calculation(x_Y,x_Y) << " Тест номер: " << i << "# FAILED" << endl;
        }
        x_Y += 1;
    }
    return 0;
}

