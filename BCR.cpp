#include "BCR.h"
#include<iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <math.h>

BCR::BCR(std::string name)
{
    this -> name = name;
    this -> readFile();
    this -> dumpPriceList();
    this -> decode();
}

BCR::~BCR()
{
    //dtor
}

void BCR::clear(){
    this->line.clear();
}

void BCR::readFile(){
    std::string linia;
    std::fstream file;

    file.open(name, std::ios::in);
    if(file.good()){
        while(!file.eof()){
            getline(file, linia);
            line.push_back(linia);
        }
        file.close();
    }
}

void BCR::setFile(std::string name){
    this -> name.clear();
    this -> name = name;
    this -> readFile();
}

void BCR::dumpFile(){
    for(std::string s:line){
        std::cout<<s<<std::endl;
    }
}

void BCR::decode(){
    char znak;
    int i=0;
    std::string n="";
    int kod=0;
    bool zm;
    Prod prods;

    for(std::string s:line){
        for(char& znak : s){
            if(znak != '&' && zm==false)    n += znak;
            else if(znak == '&'){
                zm=true;
                continue;
            }
            else{
                if(znak == '|'){
                    kod += 1*pow(2,i);
                    i++;
                }
                else{
                    i++;
                }

            }
        }
        prods.nazwa=n;
        prods.cena=kod;
        produkt.push_back(prods);
        n="";
        kod=0;
        i=0;
        zm=false;
    }
}

void BCR::dumpPriceList(){
    for(Prod p:produkt)
        std::cout<<p.nazwa<<" "<<p.cena<<std::endl;
}
