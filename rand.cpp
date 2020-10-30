#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(){

    char filename[] = "index.txt";   

    string line[1500];

    string bukva[20000];

    int o;
    int y = 0;

    for (int i = 0; i < 20000; i++)
    {
        o = (rand()%26+97);
        bukva[i] =  (char)o;
        bukva[i] = (string) bukva[i];
        
    }
 o = 0;
    for (int i = 0; i < 1000; i++)
    {
        o= (rand()%7+4);
        for (int j = y; j < y+o; j++)
        {
            line[i]+=bukva[y + j];
        }
        y += o;
    }
    
    

    fstream out(filename);

    if(out.is_open()){
        for (int i = 0; i < 1000; i++){
            out << line[i] << endl;
            }
    }

    out.close();

    return 0;
}