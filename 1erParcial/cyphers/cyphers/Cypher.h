//
//  Cypher.h
//  cyphers
//
//  Created by Ruben Cuadra on 1/17/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

std::string dctPATH = "/Users/rubcuadra/Code/QATC3045_1/1erParcial/cyphers/cyphers/diccionario.txt";

class Cifrado
{

public:
    virtual std::string decrypt(std::string text) = 0;
    
};


class Caesar : public Cifrado
{
public:
    
    std::string decrypt(std::string text)
    {
        std::transform(text.begin(), text.end(), text.begin(), ::toupper); //Solo usaremos mayusculas
        
        std::vector<std::string> combinations;
        combinations.reserve(26);
        
        for (int i = 0; i < 26; ++i) //Calcular todas las combinaciones
        {
            combinations.push_back(this->encrypt(text,i));
        }
        
        std::string word = wordInDictionary(combinations); //Check if any combinations is in our dictionary
        
        return word.length()==0?text:word; //If we found it we return it, else we return the original text
    }
    
    std::string encrypt(std::string text,int key)
    {
        std::string Crypted = text;
        for(int Current = 0; Current < text.length(); Current++)
        {
            //Ajustar para que sea ciclico, seria mejor modulos pero neh
            while (Crypted[Current]+key > 90){Crypted[Current]-=26;}
            Crypted[Current] += key;
        }
        return Crypted;
    }
    
private:
    std::string wordInDictionary(std::vector<std::string> words)
    {
        std::ifstream myfile (dctPATH);
        std::string currentLine;
        if (myfile.is_open())
        {
            while ( getline (myfile,currentLine) )
            {
                for (std::string currentKey : words)
                {
                    
                    if ( match(currentLine,currentKey) ) //Si coinciden regresar current currentKey
                    {
                        myfile.close();
                        return currentKey;
                    }
                }
            }
            myfile.close();
        }
        return "";
    }
    
    bool match(std::string one,std::string two)
    {
        if (one.length()!=two.length())
        {
            return false;
        }
        else
        {
            std::transform(one.begin(), one.end(), one.begin(), ::toupper);
            std::transform(two.begin(), two.end(), two.begin(), ::toupper);
            //1 No seria necesario por que ya todo es mayusculas pero por si acaso
            return one==two;
        }
    }
    
};

