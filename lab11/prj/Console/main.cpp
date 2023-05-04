#include <iostream>
#include "header.hpp"
#include <exception>
using namespace std;

int main()
{
    setlocale(LC_ALL,"ukr");
    try{
        string fileName;
        // �������� � ����������� �� ���� �� �������� ���� �� ��������� � ������ ������
        char yesOrNo;
        cout << "������ ��'� �����: " ;
        cin >> fileName;
        cout << "�� ������ �� ����� ����� ���� �������� ����?(Y|N)" << endl;
        cin >> yesOrNo;
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
            createFile(fileName);
            cout << "���� ��������!" << endl;
        }
        unsigned short n;
        cout << "������ ������� ������, ��� �� ������ ������ �� ��������: ";
        cin >> n;
        // �������� ����� departments � ������� n
        Department *departments = new Department[n];

        int i;
        // �������� ���� ����� Department
        unsigned int index;
        string area;
        string district;
        string township;
        string postOffice;

        /* � ���� ����������� n-�� �������, �� ��������� ��'���� Department
        *������� ����������� ������ ������� ���� ��� ��������� ������ � ����
        */
        for(i = 0; i < n;i++){
            cout << "������ ������:";
            cin >> index;
            cout << "������ �������:";
            cin >> area;
            cout << "������ �����:";
            cin >> district;
            cout << "������ ��������� �����:";
            cin >> township;
            cout << "������ ���, �� ���������:";
            cin >> postOffice;
            departments[i] = Department(index,area,district,township,postOffice);
        }
        // ��������� ������� ����������� �� �����
        addDepartToFile(fileName,departments,n);
        // ��������� ���. ���'���
        delete[] departments;

        // �������� � ����������� �� ���� �� �������� �� ������������ � �����?
        cout << "������ ������� �� ������������ ��������?(Y|N)";
        yesOrNo = '\0';
        cin >> yesOrNo;
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
        // ʳ������ ������������
        int quanityOfDepartments = 0;
        // �������� ������ ������������
        Department *departmentsFromFile = readDeparts(fileName,&quanityOfDepartments);
        // �������� �� ������������ (���� ��������)
        for(int i = 0;i < quanityOfDepartments;i++){
            cout << "������"
            << "\t" << "�������"
            << "\t\t" << "�����"
            << "\t" << "��������� �����"
            << "\t" << " ���, �� ���������"
            << endl;

            cout << departmentsFromFile[i].index
            << "\t" << departmentsFromFile[i].area
            << "\t" << departmentsFromFile[i].district
            << "\t" << departmentsFromFile[i].township
            << "\t\t" << departmentsFromFile[i].postOffice
            << endl;
            }
        }
        // �������� � ����������� �� ���� �� ��������� �� ���� �����������?
        yesOrNo = '\0';
        cout << "������ ��������� �� ���� �����������?(Y|N)";
        cin >> yesOrNo;
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
            fileName = ""; index=0; area="a"; district="b"; township="c"; postOffice="d";
            cout << "������ ��'� �����: " ;
            cin >> fileName;
            cout << "�����! ���� ����� ������ ��� ���������� ��� �����������:" << endl;
            cout << "������ ������:";
            cin >> index;
            cout << "������ �������:";
            cin >> area;
            cout << "������ �����:";
            cin >> district;
            cout << "������ ��������� �����:";
            cin >> township;
            cout << "������ ���, �� ���������:";
            cin >> postOffice;
            Department depart (index,area,district,township,postOffice);
            bool isFind = isFindDep(fileName,&depart);
            if(isFind){
                cout << "���, ����� ����� � � ����" << endl;
            }else{
                cout << "������ ������ ���� � ����. �������� ������� ����������." << endl;
            }
        }
        // ��������� ������������ � �����.
        yesOrNo = '\0';
        cout << "������ �������� ����������� � �����?(Y|N)";
        cin >> yesOrNo;
        if(yesOrNo == 'y' || yesOrNo == 'Y'){
            fileName = ""; index=0; area=""; district=""; township=""; postOffice="";
            cout << "������ ��'� �����: " ;
            cin >> fileName;
            cout << "�����! ���� ����� ������ ��� ���������� ��� �����������:" << endl;
            cout << "������ ������:";
            cin >> index;
            cout << "������ �������:";
            cin >> area;
            cout << "������ �����:";
            cin >> district;
            cout << "������ ��������� �����:";
            cin >> township;
            cout << "������ ���, �� ���������:";
            cin >> postOffice;
            Department depart (index,area,district,township,postOffice);
            removeDepartFromFile(fileName,&depart);
            cout << "������ ��������!" << endl;
        }
    }catch(const exception& ex){
        cerr << ex.what() << endl;
    }
    return 0;
}
