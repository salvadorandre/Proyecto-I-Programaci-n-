//
// Created by Admin on 23/04/2025.
//

#ifndef CURSOS_H
#define CURSOS_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Cursos {
    vector<string> list;

    public:
    Cursos(){
        list.push_back("Matematica");
        list.push_back("Ciencias");
        list.push_back("Lenguaje");
        list.push_back("Programacion");
    };
      int getCursos(){
        int curso =0;
        int id=0;

        cout << "Eliga un curso" << endl;
        for(const string& s : list){

          cout <<"Cursos:"<< to_string(id)<<" "<<s << endl;
          id++;
        }
        cin >> curso;

        if(curso > list.size() || curso < 0){
          curso = 0;
        }
        return curso;
      }
  string getCursos(int id){
        string curso;

        if(id > list.size() || id < 0){
          id = 0;
        }
        curso =list[id];

        return curso;
      }
  int getCursosId(int id){


        if(id > list.size() || id < 0){
          id = 0;
        }


        return id;
      }
};



#endif //CURSOS_H
