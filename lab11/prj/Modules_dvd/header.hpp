#ifndef HEADER_HPP_INCLUDED
#define HEADER_HPP_INCLUDED
#include <string>

class Department
{
    public:
        unsigned int index;
        std::string area;
        std::string district;
        std::string township;
        std::string postOffice;

        Department(unsigned int i, std::string ar, std::string dist, std::string tsh, std::string office){
            if(ar.length() == 0 || tsh.length() == 0 || office.length() == 0)
                throw std::exception();

            index = i; district = dist; postOffice = office;
            area = ar; township = tsh;
        }

        Department(){
        }
};

Department* readDeparts(std::string path,int* length);

void addDepartToFile(std::string path, Department* deps, int length_deps);

void removeDepartFromFile(std::string path, Department* dep);

void createFile(std::string path);

bool isFindDep(std::string path, Department* dep);

#endif // HEADER_HPP_INCLUDED
