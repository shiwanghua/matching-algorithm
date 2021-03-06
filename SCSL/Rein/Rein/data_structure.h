#ifndef _DATA_STRUCTURE_H
#define _DATA_STRUCTURE_H
#include<string>
#include<vector>
using namespace std;

struct Cnt{
    int att;
    int value;
    int op;     //  op==0 -> "="  op==1 -> ">="  op==2 -> "<="
};

struct IntervalCnt{
    int att;
    int lowValue, highValue;
};

struct Sub {
    int id;
    int size; 								//number of predicates
    vector<Cnt> constraints;				//list of constraints
};

struct IntervalSub{
    int id;
    int size;
    vector<IntervalCnt> constraints;
};

struct ConElement {
    int att;
    int val;
    int subID;
};

struct Combo{
    int val;
    int subID;
};

struct kCombo
{
    int val;
    int subID;
    int indexId;
};


struct IntervalCombo{
    int lowValue, highValue;
    int subID;
};

struct Pair{
    int att;
    int value;
};

struct changeaction{
    int id,oldlevel,newlevel;
};

struct Pub{
    int size;
    vector<Pair> pairs;
	int hotnum;
};

struct WeightPair{
    int id;
    double weight;
};


#endif //_DATA_STRUCTURE_H
