#include <iostream>
#include <fstream>
#include <filesystem>
#include "ModulesRud.h"

using namespace std;

int main()
{
    ofstream fout("TestResult.txt");
    if(!fileInDir){
        return 0;
    }else{
        ClassLab12_Rud tc1;
        ClassLab12_Rud tc2;
        ClassLab12_Rud tc3;
        ClassLab12_Rud tc4;
        ClassLab12_Rud tc5;
        ClassLab12_Rud testCases[] = {tc1,tc2,tc3,tc4,tc5};

        string fileNames[5] {"tc-1.txt","tc-2.txt","tc-3.txt","tc-4.txt","tc-5.txt"};

        ifstream* fileArray[5];


        for(int i = 0; i < 5; i++) {
            fileArray[i] = new ifstream(fileNames[i]);
        }
        string name,code,emitent,year,x,y,edition,metal,grade,denomination,mint,weight;
        for(int i = 0; i < 5;i++){
            name,code,emitent,year,x,y,edition,metal,grade,denomination,mint,weight="";
            getline(*fileArray[i],name);
            testCases[i].setName(name);

            getline(*fileArray[i],code);
            testCases[i].setCode(code);

            getline(*fileArray[i],x);
            testCases[i].setX(stod(x));

            getline(*fileArray[i],y);
            testCases[i].setY(stod(y));

            getline(*fileArray[i],emitent);
            testCases[i].setEmitent(emitent);

            getline(*fileArray[i],year);
            testCases[i].setYear(stoi(year));

            getline(*fileArray[i],edition);
            testCases[i].setEdition(stoi(edition));

            getline(*fileArray[i],metal);
            testCases[i].setMetal(metal);

            getline(*fileArray[i],grade);
            testCases[i].setGrade(stoi(grade));

            getline(*fileArray[i],denomination);
            testCases[i].setDenomination(denomination);

            getline(*fileArray[i],mint);
            testCases[i].setMint(mint);

            getline(*fileArray[i],weight);
            testCases[i].setWeight(stod(weight));
        }
        /* TC1 */
        ClassLab12_Rud test1("Петро Сагайдачний","GC0012",39.0,29.2,"Острів Ніуе",2013,1555,"срібло",999,"1 долар","Монетний двір Польщі",16.81);
        if(testCases[0].getSquare() == test1.getSquare()){
            fout << "PASSED" << endl;
        }else{
            fout << "FAILED!" << endl;
        }
        /* TC2 */
        ClassLab12_Rud test2("Петро Сагайдачний","HH12LU",39.0,29.2,"Острів Ніуе",2013,1555,"срібло",999,"1 долар","Монетний двір Польщі",16.81);
        if(testCases[1].getCode() == test2.getCode()){
            fout << "PASSED" << endl;
        }
        /* TC3 */
        ClassLab12_Rud test3("Петро Сагайдачний","GC0012",39.0,29.2,"Острів Ніуе",2013,1555,"срібло",999,"1 долар","Монетний двір Польщі",16.81);
        if(testCases[2].getSquare() == test3.getSquare()){
            fout << "PASSED" << endl;
        }else{
            fout << "FAILED!" << endl;
        }
        /* TC4 */
        ClassLab12_Rud test4("Петро Сагайдачний","GC0012",39.0,29.2,"Острів Ніуе",2013,1555,"срібло",999,"1 долар","Монетний двір Польщі",16.81);
        test4.setCode("HH12LU");
        test4.setMetal("Золото");
        test4.setWeight(20.05);
        test4.setX(60);
        test4.setY(36);

        testCases[3].setCode("HH12LU");
        testCases[3].setMetal("Золото");
        testCases[3].setWeight(20.05);
        testCases[3].setX(60);
        testCases[3].setY(36);
        if(testCases[3].getCode() == test4.getCode() && testCases[3].getSquare() == test4.getSquare()){
            fout << "PASSED" << endl;
        }else{
            fout << "FAILED!" << endl;
        }
        /* TC5 */
        ClassLab12_Rud test5("Петро Сагайдачний","GC0012",39.0,29.2,"Острів Ніуе",2013,1555,"срібло",999,"1 долар","Монетний двір Польщі",16.81);
        test5.setCode("HH12LU");
        test5.setMetal("Золото");
        test5.setWeight(20.05);
        test5.setX(-1);
        test5.setY(1);

        testCases[4].setCode("HH12LU");
        testCases[4].setMetal("Золото");
        testCases[4].setWeight(20.05);
        testCases[4].setX(-1);
        testCases[4].setY(1);
        if(testCases[4].getCode() == test5.getCode() && testCases[4].getSquare() == test5.getSquare()){
            fout << "PASSED" << endl;
        }else{
            fout << "FAILED!" << endl;
        }
        for (int i = 0; i < 5; i++) {
            delete fileArray[i];
        }
        fout.close();
    }
    return 0;
}
