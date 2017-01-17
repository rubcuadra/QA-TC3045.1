//
//  Caesar.h
//  cyphers
//
//  Created by Ruben Cuadra on 1/17/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

#ifndef Caesar_h
#define Caesar_h
#include "Cypher.h"
#include <iostream>
#include <vector>

class Caesar : public Cifrado
{
public:
    
    std::string decrypt(std::string text)
    {
        std::vector<std::string> combinations;
        combinations.reserve(26);
        
        for (int i = 0; i < 26; ++i)
        {
            combinations.push_back(this->encrypt(text,i));
            std::cout<<combinations.at(i)<<"\n";
        }
        
        //Abrir dictionary y validar que alguna se encuentra ahi, regresar la que se encuentra o la llave original
        
        return "";
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


};


#endif /* Caesar_h */
