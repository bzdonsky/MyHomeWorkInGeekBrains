#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <memory>
void addArray(char arr[] , std::string s, char Qe){
    for(int i = 0 ; i < Qe; i++){
        arr[i] = s[i];
    }
}
void Glue (char arr1[], char arr2[], char glue[]){
    for(int i = 0; i < 18 ; i++){
        glue[i] = arr1[i];
    }
    for(int i = 0 ; i < 13; i++){
        glue[18+i] = arr2[i];
    }

}

int main ()
{

    std::ifstream Out ("out.txt");
    if(!Out){
        std::cout << "File not open";
    }


    std::ifstream Hello ("Hello, World.txt");
    if(!Hello){
        std::cout << "File not open";
    }
    std::string OutFile;
    std::string HelloFile;

    std::getline(Out, OutFile , '\n');
    std::getline(Hello, HelloFile , '\n');

    char* file1 = new char[18];
    char* file2 = new char[13];
    addArray(file1,OutFile,18);
    addArray(file2,HelloFile,13);

    char* file3 = new char[18+13];

    Glue(file1,file2,file3);
    delete[] file1;
    delete [] file2;

    for(int i = 0; i < (18+13); i++){
        std::cout << file3[i];
    }
    delete [] file3;
return 0;
}
