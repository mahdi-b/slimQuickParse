//
// Created by Mahdi Belcaid on 10/15/16.
//

#ifndef PARSESLIMQUICK_SEQUENCES_H
#define PARSESLIMQUICK_SEQUENCES_H

#include "Sequence.h"

class Sequences {

public:

    unsigned int nbSequences;
    unsigned int nbSigs;
    Sequence** items;

    Sequences(unsigned int nbSequences, unsigned int nbSigs);
    ~Sequences();

    //Sequence* getSeqSignature(unsigned int seqId, unsigned short bandNumber);


};


#endif //PARSESLIMQUICK_SEQUENCES_H
