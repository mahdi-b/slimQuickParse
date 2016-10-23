//
// Created by Mahdi Belcaid on 10/15/16.
//

#ifndef PARSESLIMQUICK_SIGNATURE_H
#define PARSESLIMQUICK_SIGNATURE_H


class Signature {
private:
    short binary_search(unsigned int array[], int first, int last, int search_key);
public:
    unsigned int signatureId;
    unsigned short cardinality;
    unsigned short nbSequences; // not more than 65,535 in a single signature
    bool visited;
    unsigned int* sequences;

    Signature(unsigned int signatureId, unsigned short cardinality);
    ~Signature();

    void addSequence(unsigned int seqId);
    short getPositionOfSeqId(unsigned int seqId);

};


#endif //PARSESLIMQUICK_SIGNATURE_H
