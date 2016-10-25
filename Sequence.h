//
// Created by Mahdi Belcaid on 10/15/16.
//

#ifndef PARSESLIMQUICK_SEQUENCE_H
#define PARSESLIMQUICK_SEQUENCE_H

#include <vector>

#include "Signature.h"

using namespace std;

class Sequence {
;
public:

    unsigned int seqId;
    vector<Signature*> signatures;


    Sequence(unsigned int seqId, unsigned short  nbSignatures);
    ~Sequence();

    void addSignature(Signature* &sig, unsigned short bandNumber);
    void addSignature(Signature* &sig);
    Signature* getSignature( unsigned short bandNumber);
};


#endif //PARSESLIMQUICK_SEQUENCE_H
