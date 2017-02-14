//
//  main.cpp
//  pwd
//
//  Created by Ruben Cuadra on 2/7/17.
//  Copyright © 2017 Ruben Cuadra. All rights reserved.
//

#include<stdio.h>
#include<cstring>

//g++ -g pwd.cpp
//lldb -q ./a.out

int fun(char * pass);

int main(int argc, char *argv[])
{
    fun(argv[1])
    ?printf("granted\n")
    :printf("Noup\n");
    
    return 0;
}


int fun(char * pass)
{
    int res = 0;
    char p[16];
    strcpy(p,pass);
    if ( strcmp(p,"123456789")==0 )
        res=1;
    return res;
}
