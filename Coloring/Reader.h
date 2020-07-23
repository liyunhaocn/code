#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;


class Reader{
public:
    Reader(){};
    vector<string> read(string filePath){
        vector<string> file;

        ifstream fin(filePath, ios::in);
        char line[1024]={0};
        while(fin.getline(line, sizeof(line)))
        {
            //cout<<line<<endl;
            file.push_back(line);
        }
        fin.clear();
        fin.close();
        //cout<<file.size()<<endl;
        return file;
    }
    virtual ~Reader(){};
};


#endif // READER_H_INCLUDED
