#ifndef MODULESRUD_H_INCLUDED
#define MODULESRUD_H_INCLUDED
int dec2Bin(int n);
double s_calculation(double x, double y);
std::pair <double,double> task9_1(int arr[]);
std::pair <std::string,std::string> task9_2(int ukrSize);
int task9_3(int N);
void task9_4();
void task10_1(std::string inputfile,std::string outputfile);
void task10_2(std::string path);
void task10_3(std::string path,double x, double y, int b);
class ClassLab12_Rud{
    private:
        std::string m_name;
        std::string m_code;
        double m_x;
        double m_y;
        std::string m_emitent;
        int m_year;
        int m_edition;
        std::string m_metal;
        int m_grade;
        std::string m_denomination;
        std::string m_mint;
        double m_weight;
    public:
        ClassLab12_Rud(std::string name="",std::string code="",double x=0,double y=0,
        std::string emitent="",int year=0,int edition=0,std::string metal="",int grade=0,
        std::string denomination="",std::string mint="",double weight=0): m_name(name),m_code(code),m_x(x),m_y(y),m_emitent(emitent),
        m_year(year),m_edition(edition),m_metal(metal),m_grade(grade),m_denomination(denomination),m_mint(mint), m_weight(weight)
        {

        }
        void setName(std::string name);
        void setCode(std::string code);
        void setX(double x);
        void setY(double y);
        void setEmitent(std::string emitent);
        void setYear(int year);
        void setEdition(int edition);
        void setMetal(std::string metal);
        void setGrade(int grade);
        void setDenomination(std::string denomination);
        void setMint(std::string mint);
        void setWeight(double weight);
        std::string getCode();
        double getSquare();

        void print();
};
bool fileInDir();
#endif // MODULESRUD_H_INCLUDED
