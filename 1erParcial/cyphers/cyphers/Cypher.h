//
//  Cypher.h
//  cyphers
//
//  Created by Ruben Cuadra on 1/17/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

#ifndef Cypher_h
#define Cypher_h

class Cifrado
{

public:
    virtual std::string decrypt(std::string text) = 0;
    
};

#endif /* Cypher_h */
