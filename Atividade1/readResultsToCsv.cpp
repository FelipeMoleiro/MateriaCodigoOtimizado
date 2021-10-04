#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

std::string get_number(std::string line){
    int i=0;
    while(i < line.size() && !isdigit(line[i])){
        i++;
    }
    if(i == line.size()) return "";
    int ini = i;
    while(line[i] == ',' || line[i] == '.' || isdigit(line[i])){
        i++;
    }
    return line.substr(ini,i-ini);
}

int main(){
    std::ofstream outfile("result.csv");

    std::string path = "./results";
    for (const auto & entry : fs::directory_iterator(path)){
        std::ifstream infile(entry.path());
        std::string line;
        std::getline(infile, line);
        std::getline(infile, line);
        std::getline(infile, line);

        outfile << entry.path();
        std::getline(infile, line); //l1chace
        outfile << ';' << get_number(line);
        std::getline(infile, line); //l1chacemiss
        outfile << ';' << get_number(line);
        std::getline(infile, line); //branch
        outfile << ';' << get_number(line);
        std::getline(infile, line); //branchmiss
        outfile << ';' << get_number(line);

        std::getline(infile, line); //nothing

        std::getline(infile, line); //seconds
        outfile << ';' << get_number(line) << '\n';

    }
        

    return 0;
}