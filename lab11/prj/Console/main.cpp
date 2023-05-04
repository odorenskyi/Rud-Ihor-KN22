#include <iostream>
#include "header.hpp"
#include <exception>
using namespace std;

int main()
{
    setlocale(LC_ALL,"ukr");
    try{
        string fileName;
        // Запитуємо у користувача чи хоче він створити файл чи працювати з відомим файлом
        char yesOrNo;
        cout << "Введіть ім'я файлу: " ;
        cin >> fileName;
        cout << "Ви хочете на основі цього імені створити файл?(Y|N)" << endl;
        cin >> yesOrNo;
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
            createFile(fileName);
            cout << "Файл створено!" << endl;
        }
        unsigned short n;
        cout << "Введіть кількість записів, яку ви хочете додати до довідника: ";
        cin >> n;
        // Ініціюємо масив departments з розміром n
        Department *departments = new Department[n];

        int i;
        // Ініціюємо поля класу Department
        unsigned int index;
        string area;
        string district;
        string township;
        string postOffice;

        /* В циклі проходимось n-ну кількість, та створюємо об'єкти Department
        *Просимо користувача ввести відповідні поля для створення запису у файл
        */
        for(i = 0; i < n;i++){
            cout << "Введіть індекс:";
            cin >> index;
            cout << "Введіть область:";
            cin >> area;
            cout << "Введіть район:";
            cin >> district;
            cout << "Введіть населений пункт:";
            cin >> township;
            cout << "Введіть ВПЗ, що обслуговує:";
            cin >> postOffice;
            departments[i] = Department(index,area,district,township,postOffice);
        }
        // Додавання массиву Департаметів до ФАЙЛУ
        addDepartToFile(fileName,departments,n);
        // Звільнюємо дим. пам'ять
        delete[] departments;

        // Запитуємо у користувача чи хоче він отримати всі Департаменти з файлу?
        cout << "Хочете вивести всі департаменти таблицею?(Y|N)";
        yesOrNo = '\0';
        cin >> yesOrNo;
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
        // Кількість Департаментів
        int quanityOfDepartments = 0;
        // Отримуємо список Департаментів
        Department *departmentsFromFile = readDeparts(fileName,&quanityOfDepartments);
        // Виводимо усі Департаменти (типу таблицею)
        for(int i = 0;i < quanityOfDepartments;i++){
            cout << "Індекс"
            << "\t" << "Область"
            << "\t\t" << "Район"
            << "\t" << "Населений пункт"
            << "\t" << " ВПЗ, що обслуговує"
            << endl;

            cout << departmentsFromFile[i].index
            << "\t" << departmentsFromFile[i].area
            << "\t" << departmentsFromFile[i].district
            << "\t" << departmentsFromFile[i].township
            << "\t\t" << departmentsFromFile[i].postOffice
            << endl;
            }
        }
        // Запитуємо у користувача чи хоче він перевірити чи існує Департамент?
        yesOrNo = '\0';
        cout << "Хочете перевірити чи існує Департамент?(Y|N)";
        cin >> yesOrNo;
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
            fileName = ""; index=0; area="a"; district="b"; township="c"; postOffice="d";
            cout << "Введіть ім'я файлу: " ;
            cin >> fileName;
            cout << "Добре! Будь ласка введіть всю інформацію про Департамент:" << endl;
            cout << "Введіть індекс:";
            cin >> index;
            cout << "Введіть область:";
            cin >> area;
            cout << "Введіть район:";
            cin >> district;
            cout << "Введіть населений пункт:";
            cin >> township;
            cout << "Введіть ВПЗ, що обслуговує:";
            cin >> postOffice;
            Department depart (index,area,district,township,postOffice);
            bool isFind = isFindDep(fileName,&depart);
            if(isFind){
                cout << "Так, такий запис є у файлі" << endl;
            }else{
                cout << "Такого запису немає у файлі. Перевірте введену інформацію." << endl;
            }
        }
        // Видалення Департаменту з файлу.
        yesOrNo = '\0';
        cout << "Хочете видалити Департамент з файлу?(Y|N)";
        cin >> yesOrNo;
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
            fileName = ""; index=0; area=""; district=""; township=""; postOffice="";
            cout << "Введіть ім'я файлу: " ;
            cin >> fileName;
            cout << "Добре! Будь ласка введіть всю інформацію про Департамент:" << endl;
            cout << "Введіть індекс:";
            cin >> index;
            cout << "Введіть область:";
            cin >> area;
            cout << "Введіть район:";
            cin >> district;
            cout << "Введіть населений пункт:";
            cin >> township;
            cout << "Введіть ВПЗ, що обслуговує:";
            cin >> postOffice;
            Department depart (index,area,district,township,postOffice);
            removeDepartFromFile(fileName,&depart);
            cout << "Успішно видалено!" << endl;
        }
    }catch(const exception& ex){
        cerr << ex.what() << endl;
    }
    return 0;
}
