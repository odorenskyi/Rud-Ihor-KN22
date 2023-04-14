#include <cmath>
#include <iostream>
using namespace std;

int SampleAddInt(int i1, int i2)
{
    return i1 + i2;
}
double s_calculation(double x, double y)
{
    return pow(x,2) - pow(y,3) + sqrt(pow(y,x) - M_PI);
}
pair<double,double> task9_1(int arr[])
{
    int zarobitna_plata = 0;
    int zarobitna_plata_z_nalogamu = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i] > 0){
            if(arr[i] <= 8){
            zarobitna_plata += arr[i] * 40;
            }else{
            zarobitna_plata += 320 +  300;
            }
        }else{
            return pair<double,double>(0,0);
        }
    }
    zarobitna_plata_z_nalogamu = zarobitna_plata - (zarobitna_plata * 18.6)  / 100;
    return pair<double,double>(zarobitna_plata,zarobitna_plata_z_nalogamu);
}

pair <string,string> task9_2(int ukrSize)
{
    switch(ukrSize)
    {
        case 23:
            return pair<string,string>("8","37/38");
        case 25:
            return pair<string,string>("9","39/40");
        case 27:
            return pair<string,string>("10","41/42");
        case 29:
            return pair<string,string>("11","43/44");
        case 31:
            return pair<string,string>("12","45/46");
        default:
            return pair<string,string>("Не існує","Не існує");
    }
}

int task9_3(int N)
{
    if(N < 0 || N > 7483650){
        return -1;
    }
    int count = 0;
    bool isD7Bit = N & (1 << 7);
    if(isD7Bit){
        while(N != 0){
            if((N & 1) == 0){
                count++;
            }
            N >>= 1;
        }
    }else{
        while(N != 0){
            if((N & 1) == 1){
                count++;
            }
            N >>= 1;
        }
    }
    return count;
}
void task9_4(){
    char choice;
    cin >> choice;
    if(choice == 'v'){
        cout << "s_calculation" << endl;
        cout << s_calculation(2,2) << endl;
    }else if(choice == 'n'){
        cout << "task9_1" << endl;
        int test[5] {8,8,8,8,8};
        task9_1(test);
    }else if(choice == 'm'){
        cout << "task9_2" << endl;
        task9_2(27);
    }else if(choice == 'q'){
        cout << "task9_3" << endl;
        cout << task9_3(7) << endl;
    }else{
        cout << '\a' << endl;
    }
    cin >> choice;
    if(choice == 'W' || choice == 'w'){
        cout << "End" << endl;
    }else{
        task9_4();
    }
}
