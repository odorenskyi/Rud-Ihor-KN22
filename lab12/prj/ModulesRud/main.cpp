#include <cmath>
#include <iostream>
#include <fstream>
#include <locale>
#include <ctime>
#include "ModulesRud.h"

using namespace std;

int dec2Bin(int n){
    int bin = 0;
    int remainder = 1;
    int i = 1;
    while(n != 0){
        remainder = n % 2;
        n = n / 2;
        bin = bin + remainder * i;
        i *= 10;
    }
    return bin;
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
            return pair<string,string>("ĐĐľ ŃŃĐ˝ŃŃ","ĐĐľ ŃŃĐ˝ŃŃ");
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
void task10_1(string inputfile,string outputfile){
    locale loc("uk_UA.utf8");
    ifstream fin;
    ofstream fout;
    fin.open(inputfile);
    fout.open(outputfile);

    try{
        if(!fout.is_open() || !fin.is_open()){
            throw "Đ¤Đ°ĐšĐť Đ˝Đľ Đ˛Đ´Đ°ĐťĐžŃŃ Đ˛ŃĐ´ĐşŃĐ¸ŃĐ¸!";
        }
        string line;
        while (!fin.eof()) {
            getline(fin,line);
            if(line[line.length() - 1] == ',' || line[line.length() - 1] == '.'){
                fout << "ĐĐ°ĐşŃĐ˝ŃŃŃŃŃŃŃ Đ˝Đ° ŃĐ¸ĐźĐ˛ĐžĐť " << line[line.length() - 1];
            }
        }
        char ch;
        string upperLetters;
        while(fin.get(ch)){
            if(isupper(ch)){
                upperLetters += ch;
            }
        }
        fout << "\n" << upperLetters;
        fout << "ĐĐłĐžŃ Đ ŃĐ´Ń, ĐŚĐľĐ˝ŃŃĐ°ĐťŃĐ˝ĐžŃĐşŃĐ°ŃĐ˝ŃŃĐşĐ¸Đš ŃĐľŃĐ˝ŃŃĐ˝Đ¸Đš ŃĐ˝ŃĐ˛ĐľŃŃĐ¸ŃĐľŃ, ĐŃĐžĐżĐ¸Đ˛Đ˝Đ¸ŃŃĐşĐ¸Đš, ĐŁĐşŃĐ°ŃĐ˝Đ°, 2023Ń.\n";

    }catch (const char* message){
        cerr << message;
    }
    fout.close();
    fin.close();
}
void task10_2(string path){
    time_t now = time(nullptr);
    tm* timeinfo = localtime(&now);
    ofstream fout;
    fout.open(path,fstream::app);
    try{
        if(!fout.is_open()){
            throw "Đ¤Đ°ĐšĐť Đ˝Đľ Đ˛Đ´Đ°ĐťĐžŃŃ Đ˛ŃĐ´ĐşŃĐ¸ŃĐ¸!";
        }
        fout << sizeof(fout) << " kb\n";
        fout << asctime(timeinfo);

    }catch (const char* message){
        cerr << message;
    }
    fout.close();
}
void task10_3(string inputfile,double x, double y, int b){

    double result = s_calculation(x,y);

    ofstream fout;
    fout.open(inputfile,fstream::app);

    try{
        if(!fout.is_open()){
            throw "Đ¤Đ°ĐšĐť Đ˝Đľ Đ˛Đ´Đ°ĐťĐžŃŃ Đ˛ŃĐ´ĐşŃĐ¸ŃĐ¸!";
        }
        fout << "\n" << result;
        fout << "\n" << dec2Bin(b);

    }catch (const char* message){
        cerr << message;
    }
    fout.close();
}
void ClassLab12_Rud::setName(string name){
    m_name = name;
}
void ClassLab12_Rud::setCode(string code){
    m_code = code;
}
void ClassLab12_Rud::setX(double x){
    m_x = x < 0 ? 1 : x;
}
void ClassLab12_Rud::setY(double y){
    m_y = y < 0 ? 1 : y;
}
void ClassLab12_Rud::setEmitent(string emitent){
    m_emitent = emitent;
}
void ClassLab12_Rud::setYear(int year){
    m_year = year;
}
void ClassLab12_Rud::setEdition(int edition){
    m_edition = edition;
}
void ClassLab12_Rud::setMetal(string metal){
    m_metal = metal;
}
void ClassLab12_Rud::setGrade(int grade){
    m_grade = grade;
}
void ClassLab12_Rud::setDenomination(string denomination){
    m_denomination = denomination;
}
void ClassLab12_Rud::setMint(string mint){
    m_mint = mint;
}
void ClassLab12_Rud::setWeight(double weight){
    m_weight = weight;
}
double ClassLab12_Rud::getSquare(){
    return M_PI * m_x * m_y;
}
void ClassLab12_Rud::print(){
    cout << "Монета іноземного виробництва" << "\n" << m_name << "\n"
    << "Код: " << m_code << "\n"
    << "Розмір: " << m_x << " x " << m_y << " мм" << "\n"
    << "Емітент: " << m_emitent << "\n"
    << "Рік випуску: " << m_year << "\n"
    << "Тираж: " << m_edition << "\n"
    << "Метал: " << m_metal << "\n"
    << "Проба: " << m_grade << "\n"
    << "Номінал: " << m_denomination << "\n"
    << "Монетний двір: " << m_mint << "\n"
    << "Вага: " << m_weight << " г" << endl;
}
string ClassLab12_Rud::getCode(){
    return m_code;
}
