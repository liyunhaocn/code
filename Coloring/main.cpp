#include <bits/stdc++.h>

# include "Solver.h"

using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;

int main(int argc, char *argv[]) {

    vector<string> files = {
        "test.col",  // 0
    "DSJC125.1.col", // 1
    "DSJC125.5.col", // 2
    "DSJC125.9.col", // 3
    "DSJC250.1.col", // 4
    "DSJC250.5.col", // 5
    "DSJC250.9.col", // 6
    "DSJC500.1.col", // 7
    "DSJC500.5.col", // 8
    "DSJC500.9.col"  // 9
    };


    Solver Solver1(files[0]);
    int K = Solver1.run();
    cout<<"result:";
    debug(K);

    /*
    ofstream outFile;
    outFile.open("test.txt",ios_base::app);
    if (outFile.is_open()){
        ;
    }else{
        debug("00000");
        return -1;
    }
    for(int j=0;j<20;j++){
        outFile << "=================================="<< endl;
        for(int i=0;i<files.size();i++){
            Solver Solver1(files[i]);
            cout<<files[i]+":"<<endl;
            int K = Solver1.run();
            cout<<"result:";
            debug(K);
            outFile << files[i] <<": "<<K<< endl;

        }
    }
    outFile.close();
    */
    return 0;
}
