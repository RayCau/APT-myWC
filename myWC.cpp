#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[]);
int countLines(std::string filename);
int countCharacters(std::string filename);

int main(int argc, char *argv[]){ 
    if(std::string(argv[1]) == "-l"){
        countLines(argv[2]);
    }else if(std::string(argv[1]) == "-c"){
        countCharacters(argv[2]);
    }else{
        std::cout << "Please enter valid command-line arguments." << std::endl;
    }
    return(EXIT_SUCCESS);
}

int countLines(std::string filename){
    int linecount = 0;

    std::ifstream infile(filename);
    std::string str;
    while (std::getline(infile, str)) {
        ++linecount;
    }
    infile.close();

    std::cout << "The line count for " << filename << " is: " << linecount << std::endl;
    return linecount;
}

int countCharacters(std::string filename){
    int charcount = 0;
    std::ifstream infile(filename);
    std::string line;

    while ((infile.get()) != EOF){
        ++charcount;
    }	

    infile.close();
    std::cout << "The character count for " << filename << " is: " << charcount << std::endl;

    return charcount;
}