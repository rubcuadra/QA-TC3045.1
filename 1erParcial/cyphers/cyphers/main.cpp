//
//  main.cpp
//  cyphers
//
//  Created by Ruben Cuadra on 1/17/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Cypher.h"

using std::  cout;
using std::  endl;
using std::   cin;
using std::string;
using std::ifstream;
using std::vector;

string Encrypt(string, int);
vector<string> getText( string fileName);
string encrPATH = "/Users/rubcuadra/Code/QATC3045_1/1erParcial/cyphers/cyphers/encriptado.txt";

int main(int argc, char *argv[])
{
    Caesar *caesar = new Caesar();
    
    vector<string> data = getText(encrPATH);
    string key = data.at(0);
    string text = data.at(2);
    
    
    string result = caesar->decrypt(key);
    std::cout<<result<<"\n";
    
    return 0;
}


// Vector 0 = Llave
// Vector 1 = space
// Vector 2 = texto en vinegere
vector<string> getText( string fileName)
{
    vector<string> vals;
    vals.reserve(3); //Llave, texto, else
    
    ifstream myfile (fileName);
    string currentLine;
    if (myfile.is_open())
    {
        
        while ( getline (myfile,currentLine) )
        {
            vals.push_back(currentLine);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return vals;
}

bool isInDictionary( string dictionaryPath)
{
    return false;
}
