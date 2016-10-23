//
// Created by Mahdi Belcaid on 10/15/16.
//

#ifndef PARSESLIMQUICK_SEQUENCE_H
#define PARSESLIMQUICK_SEQUENCE_H

#include "Signature.h"

class Sequence {

public:
    Signature** signatures;


    Sequence(unsigned short  nbSignatures);
    ~Sequence();

    void addSignature(Signature* &sig, unsigned short bandNumber);
    Signature* getSignature( unsigned short bandNumber);
};


#endif //PARSESLIMQUICK_SEQUENCE_H
