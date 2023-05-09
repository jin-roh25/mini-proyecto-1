#include <iostream>
#include <algorithm>
#include "NodeLeaf.h"
#include "ListArr.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int b,c,f;

    cout << "Espacio de arreglos: ";
    cin >> b;

    ListArr* tree = new ListArr(b);

    //insert left

    /*
    cout << "Elemento a insertar: ";
    cin >> c;

    tree->insert_left(c);
    */

    //insert right

    ///*
    cout << "Elemento a insertar: ";
    cin >> c;

    tree->insert_right(c);
    //*/

    //find
    /*

    cout << "Elementos a buscar: ";
    cin >> c;


    */

    /*cout << "Elementos a insertar: ";
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        tree->insert(i+1,i);
    }*/
    
    /*tree->print();

    cout << "Buscar: ";
    cin >> f;
    if (tree->find(f))
    {
        cout << "está" << endl;
    }else{
        cout << "no está" << endl;
    }*/
    

    return 0;
}
