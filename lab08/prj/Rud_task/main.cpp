#include <iostream>
#include <clocale>
#include <ModulesRud.h>

using namespace std;
void printInfo()
{
    cout << "Рудь Ігор | Академ-група:КН-22 | ЦНТУ " << "\u00A9" << endl;
}
int task8_2_2(int a,int b)
{
    cout << "Введіть значення a та b" << endl;
    cin >> a >> b;
    return (a<=b-32);
}
double task8_2_3(double x, double y)
{
    cout << "Введіть значення x та y" << endl;
    cin >> x >> y;
    cout << "В десятковій системі числення x та y відповідно:\t" << dec << x << "\t" << dec << y << endl;
    cout << "В шістнадцятковій системі числення x та y відповідно:\t" << hex << x << "\t" << hex << y << endl;
    return s_calculation(x,y);
}
int main()
{
    setlocale(LC_ALL, "ru_UA.utf8");
    //8.2.1
    printInfo();
    int a,b;
    double x,y;
    //8.2.2
    cout << task8_2_2(a,b) << endl;
    //8.2.3
    cout << task8_2_3(x,y) << endl;
    return 0;
}
