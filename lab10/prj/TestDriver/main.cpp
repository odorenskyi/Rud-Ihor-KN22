#include <iostream>
#include <ModulesRud.h>
#include <unistd.h>
using namespace std;
int main()
{
    /* TestSuite 1*/
    for(int i = 0; i < 1; i++){
        task10_1("../input.txt","../output.txt");
    }

    /* TestSuite 2 */
    for(int i = 0; i < 3;i++){
        sleep(60);
        task10_2("../input.txt");
        cout << "PASSED" << endl;
    }
    /* TestSuite 3 */
    int values[10] = {4,2,3,7,3,5,10,100,1000,0};
    double x_Y = 2;
    for(int i = 0;i < 10;i++)
    {
        task10_3("../output.txt",x_Y,x_Y,values[i]);
        x_Y += 1;
        cout << "PASSED" << endl;
    }

    return 0;
}
