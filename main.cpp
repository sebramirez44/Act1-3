#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Item.h"
#include "mergesort.h"
using namespace std;


int main(){
    fstream bitacora("bitacora.txt");
    string line;
    vector <Item> v;
    while (getline(bitacora,line)){
        Item Elemento(line);
        v.push_back(Elemento);
    }
    getline(bitacora,line);
    Item test(line);
    cout << "linea original: " << endl;
    cout << line << endl;
    cout << "linea recreada: " << endl;
    cout << test.getSmes() << " " << test.getDia() << " " << test.getShora() << " " << test.getIp() << " " << test.getEstado() << endl;
    cout << "test de ints: ";
    cout << test.getMes() << endl;
    cout << "test de stoi: ";
    cout << test.getHora() << ":" << test.getMinuto()<<":" <<test.getSegundo() << endl;
    for (int i = 0; i < v.size();i++){
        cout << v[i].getSmes() << endl;
    }
    cout << "compare dia de los primeros dos: " << v.at(0).compareHora(v.at(0),v.at(1)) << endl;
    mergesort tests(v);
    

    return 0;
}