#pragma once
#include<iostream>
#include "Stocznia.hpp"
#include "ObjCounter.hpp"

unsigned int transportujFlota(unsigned int towar)
{   
    if (towar == 0){
        return 0;
    };

    unsigned int sumaryczny_towar = 0;
    int zaglowce  = 1;
    CountThis<Zaglowiec>();
    while (sumaryczny_towar < towar){
        Stocznia stocznia{};
        Statek* s1 = stocznia();

        Zaglowiec* k_ptr = dynamic_cast<Zaglowiec*>(s1);
        if (k_ptr){
            // std::cout << "Zaglowiec\n";
            zaglowce +=1 ;
        }
        unsigned int s1_transp =s1->transportuj();
        sumaryczny_towar += s1_transp; 
        delete s1;
        
    }
    return zaglowce;
}

