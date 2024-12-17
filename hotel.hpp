#ifndef _hotel_HPP_
#define _hotel_HPP_
#include <iostream>
using std::cin ;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;
using std::ifstream ;
using namespace std;
template < typename A >
class hotel
{
 private:
 //cliente
 string codigo_c;
 string nome;
 string endereco;
 string telefone;
 //funcionario
 string codigo_f;
 string cargo;
 string salario;
 //estadia
 string codigo_e;
 string data_in;
 string data_out;
 int diarias;
 int numero;
 float value;
 //quarto
 int quant;
 float value_day;
 public: 
 hotel();
 //cliente
    hotel (string name, string cod, string end, string tel)
    {
        string create;
        create = "cliente";
        string file = create + cod + ".txt";
        ofstream arquivo(file);
        arquivo << "nome do cliente: " << name << endl;
                arquivo << "codigo do cliente: " << cod << endl;
                        arquivo << "endereco do cliente: " << end << endl;
                                arquivo << "telefone do cliente: " << tel << endl;
        arquivo.close();
    }
 //funcionario
        hotel (string name, string cod, string tel, string carg, float sal)
    {
        string create;
        create = "funcionario";
        string file = create + cod + ".txt";
        ofstream arquivo(file);
        arquivo << "nome do funcionario: " << name << endl;
            arquivo << "codigo do funcionario: " << cod << endl;
                arquivo << "telefone do funcionario: " << tel << endl;
                    arquivo << "cargo do funcionario: " << carg << endl;
                        arquivo << "salario do funcionario: " << sal << "$" << endl;
        arquivo.close();
    }
 //quarto
        hotel (string numero, int max, float value)
    {
        string create;
        create = "quarto";
        string file = create + numero + ".txt";
        ofstream arquivo(file);
        arquivo << "numero do quarto: " << numero << endl;
        //o 5 no local da diaria se refere a suite presidencial, é uma forma
        //de o programa reconhecer aquilo como uma suite.
        if (max == 5)
        {
            arquivo << "quarto para: 2"<< endl;
            arquivo << max << endl;
        }
        else
        {
            arquivo << "quarto para: "<< endl;
                arquivo << max << endl;
        }
                    arquivo << "valor da diaria: " << endl;
                        arquivo << value << endl;
        arquivo.close();
    }
};
#endif