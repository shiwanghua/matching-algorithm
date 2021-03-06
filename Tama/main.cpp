#include <iostream>
#include "tama.h"
using namespace std;
int main(int argc, char **argv)
{
    int subs;           // Number of subscriptions.
    int pubs;           // Number of publications.
    int atts;           // Total number of attributes, i.e. dimensions.
    int cons;           // Number of constraints(predicates) in one sub.
    int m;              // Number of constraints in one pub.
    int valDom;         // Cardinality of values.
    int attDis;         // The distribution of attributes in subs and pubs. 0:uniform distribution | 1:Zipf distribution
    int valDis;         // The distribution of values in subs and pubs. 0:uniform
    double alpha;       // Parameter for Zipf distribution.
    double width;       // Width of a predicate.
    int level = 13;     // The depth of Tama.

    freopen("paras.txt", "r", stdin);
    cin >> subs >> pubs >> atts >> cons >> m >> attDis >> valDis >> valDom;
    cin >> alpha >> width;

    vector<double> insertTimeList;
    vector<double> matchTimeList;
    vector<double> matchSubList;

    // Initiate generator
    intervalGenerator gen(subs, pubs, atts, cons, m, attDis, valDis, valDom, alpha, width);
    gen.GenSubList();
    gen.GenPubList();


    Tama a(atts, valDom, level);

    // insert
    for (int i = 0; i < subs; i++)
    {
        Timer subStart;

        a.insert(gen.subList[i]);                       // Insert sub[i] into data structure.

        int64_t insertTime = subStart.elapsed_nano();   // Record inserting time in nanosecond.
        insertTimeList.push_back((double) insertTime / 1000000);
    }


    // match
    for (int i = 0; i < pubs; i++)
    {
        int matchSubs = 0;                              // Record the number of matched subscriptions.
        Timer matchStart;

        a.match(gen.pubList[i], matchSubs, gen.subList);

        int64_t eventTime = matchStart.elapsed_nano();  // Record matching time in nanosecond.
        matchTimeList.push_back((double) eventTime / 1000000);
        matchSubList.push_back(matchSubs);
    }


    // output
    string outputFileName = "tama.txt";
    string content = Util::Int2String(subs) + "\t" + Util::Double2String(Util::Average(insertTimeList)) + "\t" +
                     Util::Double2String(Util::Average(matchTimeList)) + "\t" +
                     Util::Double2String(Util::Average(matchSubList));
    Util::WriteData(outputFileName.c_str(), content);


    // check
    //Util::Check(gen, "tama");

    return 0;
}
