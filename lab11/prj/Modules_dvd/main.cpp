#include <fstream>
#include <iostream>
#include "header.hpp"

// ###################################################
// Private functions. Only use in module. (PRIVATE)
// ###################################################

bool comparing(Department* dep, Department* dep_sec){
    if(dep_sec->index == dep->index && dep_sec->area == dep->area && dep_sec->district == dep->district && dep_sec->township == dep->township && dep_sec->postOffice == dep->postOffice)
        return true;

    return false;
}

void changeCount(std::string path, int cnt, bool cnt_or_not){
    int i = 0;
    std::string cnt_before = "";
    std::string line_content = "";

    std::ifstream reader;
    reader.open(path, std::ios_base::in);

    getline(reader, line_content);

    while(line_content[i] != '&' && cnt_before.length() <= 15){
        cnt_before += line_content[i];
        i += 1;
    }

    std::string full_count = "";

    if(cnt_or_not == true)
        full_count = std::to_string(cnt + std::stoi(cnt_before));
    else
        full_count = std::to_string(cnt);

    std::string toWrite = full_count + "&";

    while(!reader.eof()){
        getline(reader, line_content); //

        toWrite += "\n" + line_content;
    }

    reader.close();

    std::ofstream writer;
    writer.open(path, std::ios_base::out);

    writer << toWrite;

    writer.close();
}

int countObjects(std::string path){
    std::ifstream reader;
    std::string line_content;
    std::string temp_line = "";
    int i = 0;
    reader.open(path, std::ios_base::in);

    getline(reader, line_content);

    reader.close();

    while(line_content[i] != '&' && temp_line.length() < 15){
        temp_line += line_content[i];
        i += 1;
    }

    if(temp_line.length() < 15)
        return std::stoi(temp_line);

    return -1;
}

// This is also a private function, do not touch. For delete use "removeDepartFromFile"

Department* removeDep(Department* deps, int index, int dep_size){
    int output_index = 0;
    int new_size = dep_size - 1;
    Department* output = new Department[new_size];

    for(int i = 0; i < dep_size; i += 1){
        if(i == index){
            continue;
        }
        output[output_index] = deps[i];

        output_index += 1;
    }

    return output;
}

Department analyzeObject(std::string obj, bool* flagCrash){
    int sem_col = 0;
    int length = obj.length();
    std::string index = "";
    std::string area = "";
    std::string district = "";
    std::string township = "";
    std::string postOffice = "";

    for(int i = 0; i < length; i += 1){
        if(obj[i] == ';'){
            sem_col += 1;
            continue;
        }

        switch(sem_col){
            case 0:
                index += obj[i];
                break;
            case 1:
                area += obj[i];
                break;
            case 2:
                district += obj[i];
                break;
            case 3:
                township += obj[i];
                break;
            case 4:
                postOffice += obj[i];
                break;
        }
    }

    if(sem_col != 4)
        (*flagCrash) = true;

    return Department(std::stoi(index), area, district, township, postOffice);
}

//
//  ###############################################
//  Public functions. Can use in any place. (PUBLIC)
//  ###############################################
//

// Read all departs in file.

Department* readDeparts(std::string path, int* length){
    std::string obj_line = "";
    bool IsCrashed = false;
    int obj_index = 0;

    (*length) = countObjects(path);

    if((*length) == -1)
        throw std::invalid_argument("File is corrupt."); // The file is corrupt - the reading did not go through.
    else if(*length == 0)
        return nullptr; // The file is empty. There are no objects. We don't do calculations.

    Department* output_objects = new Department[(*length)];

    std::ifstream reader;
    reader.open(path, std::ios_base::in);
    if(reader.is_open() == false)
        throw std::invalid_argument("Can't open the file.");
    getline(reader, obj_line); obj_line = "";

    while(!reader.eof()){
        getline(reader, obj_line);

        Department dep_obj = analyzeObject(obj_line, &IsCrashed);

        if(IsCrashed == true || obj_index >= (*length))
            throw std::invalid_argument("Object in file is corrupt."); // if object is corrupt - throw exception.

        output_objects[obj_index] = dep_obj;
        obj_index += 1;
    }

    reader.close();

    return output_objects; // return all read objects
}

// Adds an array of deps objects to the file.
// The size of the array is specified with length_deps
// ATTENTION. UP COMMENTS!!!

void addDepartToFile(std::string path, Department* deps, int length_deps){
    if(length_deps <= 0)
        throw std::invalid_argument("Length cannot be < 0.");

    changeCount(path, length_deps, true);

    std::ofstream writer;
    writer.open(path, std::ios_base::app);
    if(writer.is_open() == false)
        throw std::invalid_argument("Can't open the file");

    for(int i = 0; i < length_deps; i += 1){
        Department toAdd_dep = deps[i];

        writer << "\n";
        writer << toAdd_dep.index;
        writer << ";" + toAdd_dep.area + ";" + toAdd_dep.district + ";" + toAdd_dep.township + ";" + toAdd_dep.postOffice;
    }

    writer.close();
}

// Delete the dep object from the file.
// ATTENTION, ONLY ONE (1) OBJECT! NOT ARRAY.

void removeDepartFromFile(std::string path, Department* dep){
    int length = -1;
    int cnt_dels = 0;
    bool isFind = false;

    Department* read_deps = readDeparts(path, &length);

    for(int i = 0; i < length; i += 1){
        if(comparing(&read_deps[i], dep)){
            read_deps = removeDep(read_deps, i, length - cnt_dels);
            cnt_dels += 1;
            isFind = true;
            i = -1;
        }
    }
    if(isFind == true){
        std::ofstream writer;
        writer.open(path, std::ios_base::out);

        writer << (length - cnt_dels) << "&";

        for(int i = 0; i < length - cnt_dels; i += 1){
            writer << "\n" + std::to_string(read_deps[i].index) + ";" + read_deps[i].area + ";" + read_deps[i].district + ";" + read_deps[i].township + ";" + read_deps[i].postOffice;
        }

        writer.close();
    }
}

bool isFindDep(std::string path, Department* dep){
    int length = 0;
    Department* all_deps = readDeparts(path, (&length));

    for(int i = 0; i < length; i += 1){
        if(comparing(&all_deps[i], dep))
            return true;
    }

    return false;
}

// If the file does not exist, initialize it.

void createFile(std::string path){
    std::ofstream creator;
    creator.open(path, std::ios_base::out);

    if(creator.is_open() == false){
        throw std::invalid_argument("Can't create file.");
    }

    creator << "0&";
    creator.close();
}
