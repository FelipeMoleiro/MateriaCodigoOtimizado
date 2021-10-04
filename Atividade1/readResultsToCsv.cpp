#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

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

    std::vector<std::string> finalfile;

    std::string path = "./results";
    for (const auto & entry : fs::directory_iterator(path)){
        std::ifstream infile(entry.path());
        std::string line;
        std::getline(infile, line);
        std::getline(infile, line);
        std::getline(infile, line);

        std::string finalLine;

        finalLine.append(entry.path());
        std::getline(infile, line); //l1chace
        finalLine.append(";" + get_number(line));
        std::getline(infile, line); //l1chacemiss
        finalLine.append(";" + get_number(line));
        std::getline(infile, line); //branch
        finalLine.append(";" + get_number(line));
        std::getline(infile, line); //branchmiss
        finalLine.append(";" + get_number(line));

        std::getline(infile, line); //nothing

        std::getline(infile, line); //seconds
        finalLine.append(";" + get_number(line) + "\n");

        finalfile.push_back(finalLine);
    }

    sort(finalfile.begin(),finalfile.end());
    
    for(uint i=0;i<finalfile.size();i++){
        outfile << finalfile[i];
    }

    return 0;
}