#pragma once
#include <iostream>
#include <string>
using namespace std;
//clase para definir cada elemento del vector
class Item{
private:
    //poner variables
    //maybe darle un numero a cada mes?
    string smes;
    int mes;

    int dia;
    //definitivamente darle un numero a cada hora
    string shora;
    int hora;
    int minuto;
    int segundo;
    //ip se puede quedar como string
    string ip;
    //se refiere a si fallo o no, tambien se puede quedar string
    string estado;



public:
    //tal vez aqui hacer funciones para separar strings y eso
    //para ordenar por fecha alomejor tener primero como prioridad mes, si mes es igual, checar dia, si dia es igual, checar hora
    Item(){
        smes = "";
        mes = 0;
        dia = 0;
        shora = "";
        hora = 0;
        ip = "";
        estado = "";
    }
    //alomejor poner un constructor que tome el string y de ahi obtenga todo.
    //alomejor en lugar de decir que uno es mayor a otro, hacer funcion compare() para ver que objeto es mayor.
    Item(string linea){
        //convertir en un array con split()
        //pasar cada item de ese array a su respectivo atributo
        string*atributos = this->split(linea);
        this->smes = atributos[0];
        this->dia = stoi(atributos[1]);
        this->shora = atributos[2];
        this->ip = atributos[3];
        this->estado = atributos[4];
        this->MestoInt();
        this->HoratoInts();
    }
    ~Item(){

    }
    void MestoInt(){
        if (this->smes == "Jan"){
            this->mes = 1;
        }
        else if(this->smes == "Feb"){
            this->mes = 2;
        }
        else if(this->smes == "Mar"){
            this->mes = 3;
        }
        else if(this->smes == "Apr"){
            this->mes = 4;
        }
        else if(this->smes == "May"){
            this->mes = 5;
        }
        else if(this->smes == "Jun"){
            this->mes = 6;
        }
        else if(this->smes == "Jul"){
            this->mes = 7;
        }
        else if(this->smes == "Aug"){
            this->mes = 8;
        }
        else if(this->smes == "Sep"){
            this->mes = 9;
        }
        else if(this->smes == "Oct"){
            this->mes = 10;
        }
        else if(this->smes == "Nov"){
            this->mes = 11;
        }
        else if(this->smes == "Dic"){
            this->mes = 12;
        }
        else{
            this->mes = 24;
        }
    }
    void HoratoInts(){
        //separar el string de hora
        //poner cada valor donde debe de estar (hora, minuto, segundo)
        //ejemplo de un string hora: 10:32:24
        //primeros dos a int, depsues saltarse el : y segundos dos a int, otra vez saltarse el : y terceros dos a int
        string temp = "";
        //hacemos hardcoding de cada valor, porque solo tenemos 3 ints y conocemos el formato
        //tambien como cada 2 numeros tenemos que hacer una asignacion difernete no sale mucho peor.
        temp = temp + this->shora[0];
        temp = temp + this->shora[1];
        this->hora = stoi(temp);
        temp = "";
        temp = temp + this->shora[3];
        temp = temp + this->shora[4];
        this->minuto = stoi(temp);
        temp = "";
        temp = temp + this->shora[6];
        temp = temp + this->shora[7];
        this->segundo = stoi(temp);

    }
    string *split(string sentence){
        static string arr[5] = {""};
        string adicionar = "";
        int contador = 0;
        for (int i = 0; i < sentence.length();i++){
            if (sentence[i] == ' ' && contador < 4){
                arr[contador] = adicionar;
                adicionar = "";
                contador++;
            }
            else{
                adicionar = adicionar + sentence[i];
            }
        }
        arr[4] = adicionar; //hacemos esto para que el string "Failed password for illegal user" se guarde con espacios.
        return arr;
    }
    int compare(Item arg1, Item arg2){
        //si es 0 el primer arg es mayor
        //si es 1 el segundo arg es mayor
        //si es 2 son iguales
        if (compareDia(arg1,arg2) != 2){
            return compareDia(arg1,arg2);
        }
        else if(compareHora(arg1,arg2) != 2){
            return compareHora(arg1,arg2);
        }
        else{
            return 2;
        }


    }
    int compareDia(Item arg1, Item arg2){
        //return 0 significa el primer arg mayor
        //return 1 significa el segundo arg mayor
        //return 2 significa son iguales
        //primero comparar mes, si es igual comparar dia
        if (arg1.mes > arg2.mes){
            return 0;
        }
        else if(arg1.mes < arg2.mes){
            return 1;
        }
        else{
            if (arg1.dia > arg2.dia){
                return 0;
            }
            else if(arg1.dia < arg2.dia){
                return 1;
            }
            else{
                return 2;
            }
        }
    }
    int compareHora(Item arg1, Item arg2){
        //return 0 significa el primer arg mayor
        //return 1 significa el segundo arg mayor
        //return 2 significa son iguales
        if (arg1.hora > arg2.hora){
            return 0;
        }
        else if(arg1.hora < arg2.hora){
            return 1;
        }
        else{
            if (arg1.minuto > arg2.minuto){
                return 0;
            }
            else if(arg1.minuto<arg2.minuto){
                return 1;
            }
            else{
                if (arg1.segundo > arg2.segundo){
                    return 0;
                }
                else if(arg1.segundo < arg2.segundo){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
    }
    string getSmes(){
        return this->smes;
    }
    string getShora(){
        return this->shora;
    }
    string getIp(){
        return this->ip;
    }
    string getEstado(){
        return this->estado;
    }
    int getDia(){
        return this->dia;
    }
    int getMes(){
        return this->mes;
    }
    int getHora(){
        return this->hora;
    }
    int getMinuto(){
        return this->minuto;
    }
    int getSegundo(){
        return this->segundo;
    }



};