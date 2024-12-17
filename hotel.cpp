#include <iostream>
#include <limits>
#include <string>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include "hotel.hpp"
void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
}
using namespace std;
void metodo00 ( )
{
}
void cliente ( )
{
// identificar
 cout << endl << "Cadastrar cliente:" << endl;
 string name;
  int codigo;
   string endereco;
    string telefone;
 cin.ignore();
 cout << "nome do cliente: ";
 getline(cin, name);
 cout << "codigo do cliente: " << endl;
 cout << "| 1  | 2  | 3  | 4  | 5  | " << endl;
 cout << "| 6  | 7  | 8  | 9  | 10 |" << endl;
 cout << "| 11 | 12 | 13 | 14 | 15 | " << endl;
 cout << "| 16 | 17 | 18 | 19 | 20 |" << endl;
 cin >> codigo;
 if (codigo > 20 || codigo < 1){cout << " codigo alem dos limites do hotel" << endl; return;}
 cin.ignore();
 cout << "endereco do cliente: ";
 getline(cin, endereco);
 cout << "telefone do cliente: ";
 getline(cin, telefone);
  string code = to_string(codigo);
 hotel <int> objeto(name,code,endereco,telefone);
// encerrar
 pause ( "Apertar ENTER para continuar" );
} 
void funcionario ( )
{
// identificar
 cout << endl << "Cadastrar funcionario:" << endl;
  string name;
  int codigo;
  string telefone;
  string cargo;
  float salario;
 cin.ignore();
 cout << "nome do funcionario: ";
 getline(cin, name);
 cout << "codigo do funcionario: ";
 cin >> codigo;
 if (codigo > 4 || codigo < 1){cout << " codigo alem dos limites do hotel" << endl; return;}
  cin.ignore();
 cout << "telefone do funcionario: ";
 getline(cin, telefone);
 cout << "cargo do funcionario: ";
 getline(cin, cargo);
 cout << "salario do funcionario: ";
 cin >> salario;
 string code = to_string(codigo);
 hotel <int> objeto(name,code,telefone,cargo,salario);
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void quarto ( )
{
// identificar
 cout << endl << "Construir quarto: " << endl;
  int numeroi;
  string numeron;
  int max;
  float value;
 cin.ignore();
 cout << "numero do quarto: ";
 cin >> numeroi;
 if (numeroi > 0 && numeroi <= 20)
 {
 numeron = to_string(numeroi);
 cout << "quantidade maxima de hospedes: (os quartos do hotel comportam no maximo 4 pessoas)";
 cin >> max;
 if (max > 4 || max < 1){cout << "valor invalido" << endl; return;}
 if (max == 1 || max == 2)
 {
  int escolha = 0;
  cout << "deseja que o quarto seja uma suite presidencial? 1 = sim 2 = nao" << endl;
  cin >> escolha;
  if (escolha != 1 && escolha != 2){cout << "valor invalido" << endl; return;}
  else if (escolha == 1){max = 5;}
 }
 cout << "valor da estadia: ";
 cout << "os valores da estadia do hotel sao:" << endl;
 cout << "R$ 100 para quartos de 1/2 hospedes no quarto padrao"<< endl;
  cout << "R$ 200 para quartos de 1/2 hospedes na suite presidencial"<< endl;
   cout << "R$ 120 para quartos de 3 hospedes "<< endl;
    cout << "R$ 135 para quartos de 4 hospedes"<< endl;
 cin >> value;
 if (max == 1 && value != 100){cout << "erro" << endl; return;}
  if (max == 2 && value != 100){cout << "erro" << endl; return;}
   if (max == 3 && value != 120){cout << "erro" << endl; return;}
    if (max == 4 && value != 135){cout << "erro" << endl; return;}
     if (max == 5 && value != 200){cout << "erro" << endl; return;}
 hotel <int> objeto(numeron,max,value);
 }
 else{cout << "quarto nao existe" << endl;}
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void start_estadia ( )
{
   int diaria = 0;
   string linha_temp;
   string trans;
   string linha;
   int linhac = 0;
   int hospedes = 0;
   int n = 0;
   int simples = 0;
   int lotado = 0;
   int mark = 0;
// identificar
 cout << endl << "Iniciar estadia: " << endl;
 cout << "quantos hospedes?" << endl;
 cin >> hospedes;
 if (hospedes == 1 || hospedes == 2)
 {
  cout << "deseja a suite presidencial? sim = 1 nao = 2" << endl;
  int escolha = 0;
  cin >> escolha;
  if (escolha != 1 && escolha != 2){cout << "erro" << endl; return;}
  if (escolha == 1){hospedes = 5;}else if (escolha == 2){hospedes = 2;}
}
 string h = to_string(hospedes);
 cout << "quartos disponiveis: " << endl;
 int ocupado = 0;
 int oc1[25];
  int oc2[25];
 for (int i = 1; i < 21; i = i + 1)
 {
   trans = to_string(i);
   string create;
   create = "quarto";
   string file = create + trans + ".txt";
   ifstream arquivo(file);
   linhac = 0;
   mark = 1;
    while (getline(arquivo, linha)) 
    {
      linhac = linhac + 1;
      if (linhac == 3)
      {
        if (linha.find(h) != string::npos) 
        {
          mark = mark + 1;
        } 
      }
      if (linhac == 5)
      {
      linha_temp = linha;
      }
      if (linhac == 12)
      {
            if (linha.find("ocupado") != string::npos) 
            {
            mark = mark - 1;
            } 
      }
    }
   arquivo.close();
   if (mark == 2) 
   {
   lotado = lotado + 1;
   cout << "| " << i << " | ";
   oc1[i] = i;
   oc2[i] = 0;
   }
   else {oc1[i] = i; oc2[i] = 30;}
 }
 cout << endl;
 int quartoi = 0;
 string quartos;
 if (lotado == 0){cout << "nenhum" << endl; return;}
 else
 {
 cout << "escolha um quarto: " << endl;
 cin >> quartoi;
 for (int o = 0; o < 20; o = o + 1)
 {
 if (oc1[o] == quartoi)
 {
  if (oc2[o] == 30)
  {
 cout << "erro - quarto ocupado ou de tamanho incompativel" << endl; return;
  }
 }
 else if (quartoi < 1 || quartoi > 20)
 {
  cout << "erro - quarto ocupado ou de tamanho incompativel" << endl; return;
 }
 }
 string create;
 create = "quarto";
 quartos = to_string(quartoi);
 string file = create + quartos + ".txt";
 ofstream arquivo(file, ios::app);
 //o programa considera o ano como nao sendo bissexto
 cout << "qual o dia da entrada? (somente o dia)" << endl;
 int entrada_day;
 cin >> entrada_day;
 if (entrada_day < 1 || entrada_day > 31)
 {cout << "dia invalido"; return;}
 cout << "qual o mes da entrada?" << endl;
 int entrada_month;
 cin >> entrada_month;
if (entrada_month < 1 || entrada_month > 12)
 {cout << "mes invalido"; return;}
 cout << "qual o dia da saida? (somente o dia)" << endl;
 int saida_day;
 cin >> saida_day;
 if (saida_day < 1 || saida_day > 31)
 {cout << "dia invalido"; return;}
 cout << "qual o mes da saida?" << endl;
 int saida_month;
 cin >> saida_month;
 if (saida_month < entrada_month || saida_month - entrada_month > 1){cout << "erro - datas "
  << "muito distantes ou invalidas" << endl; return;}
if (entrada_month < 1 || entrada_month > 12)
 {cout << "mes invalido"; return;}
if (entrada_day == saida_day && saida_month == entrada_month)
{cout << "erro - impossivel sair e entrar no mesmo dia" << endl; return;}
 arquivo << "entrada: " << entrada_day << "/" << entrada_month;
 arquivo << " | saida dia : " << saida_day << "/" << saida_month << endl;
 int block = 0;
 int days = 0;
 int dias = 0;
 if (entrada_month == 1 || entrada_month == 3 || entrada_month == 5
  || entrada_month == 7 || entrada_month == 9 || entrada_month == 11)
  {
   days = 31;
   if (entrada_month != saida_month)
   {
   entrada_day = days - entrada_day;
   dias = entrada_day + saida_day;
   }
   else
   {
    dias = saida_day - entrada_day;
   }
  }
  else if (entrada_month == 4 || entrada_month == 6 || entrada_month == 8
  || entrada_month == 10 || entrada_month == 12)
  {
   days = 30;
   if (entrada_month != saida_month)
   {
   entrada_day = days - entrada_day;
   dias = entrada_day + saida_day;
   }
   else
   {
    dias = saida_day - entrada_day;
   }
  }
  else if (entrada_month == 2)
  {
   days = 28;
   if (entrada_month != saida_month)
   {
   entrada_day = days - entrada_day;
   dias = entrada_day + saida_day;
   }
   else
   {
    dias = saida_day - entrada_day;
   }
 }
 int cliente = 0;
 int final_price = 0;
 diaria = stoi(linha_temp);
 final_price = dias * diaria; 
 arquivo << final_price << endl;
 cout << "qual o codigo do cliente? " << endl;
 cin >> cliente;
 if (cliente < 1 || cliente > 20){cout << "clientes exederam o limite do hotel" << endl;return;}
 else
 {
 string create;
 create = "cliente";
 string cl = to_string(cliente);
 string file = create + cl + ".txt";
  ifstream arquivo_cliente(file);
  if (!arquivo_cliente.is_open()) 
  {
    cout << "Cliente: " << cliente << " nao cadastrado." << endl;
    return;
  }
  else
  {
    arquivo << "Cliente: " << endl;
    arquivo << cliente << endl;
  }
  arquivo_cliente.close();
 }
 int funcionario = 0;
  cout << "qual o codigo do funcionario? " << endl;
 cin >> funcionario;
 if (funcionario < 1 || funcionario > 20){cout << "clientes exederam o limite do hotel" << endl;return;}
 else
 {
  string create;
  create = "funcionario";
  string cl = to_string(cliente);
  string file = create + cl + ".txt";
  ifstream arquivo_funcionario(file);
  if (!arquivo_funcionario.is_open()) 
  {
    cout << "Funcionario: " << funcionario << " nao cadastrado." << endl;
    return;
  }
  else
  {
    arquivo << "Funcionario: " << endl;
    arquivo << funcionario << endl;
  }
  arquivo_funcionario.close();
 }
 arquivo << "ocupado" << endl;
 arquivo << "mes de marco de lucros: " << endl;
 arquivo << entrada_month << endl;
 arquivo.close();
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void end_estadia ( )
{
  int quarto = 0;
// identificar
 cout << endl << "Encerrar estadia: " << endl;
 cout << "Qual quarto tera sua estadia finalizada?" << endl;
 cin >> quarto;
 if (quarto < 1 || quarto > 20)
 {
  cout << "Quarto nao existe." << endl; return;
 }
  string create;
  create = "quarto";
  string cl = to_string(quarto);
  string file = create + cl + ".txt";
  ifstream arquivo(file);
  ofstream arquivo_temp("arqtmp.txt");
  string line1;
  int inLine1 = 0;
  while (getline(arquivo, line1)) 
  {
    if (inLine1 <= 4) 
    {
    arquivo_temp << line1 << endl;
    }
  inLine1 = inLine1 + 1;
  }
  arquivo.close();
  arquivo_temp.close();
  ifstream arquivo_tempe("arqtmp.txt");
  ofstream arquivoe(file);
  string line2;
  int inLine2 = 0;
    while (getline(arquivo_tempe, line2)) 
  {
  arquivoe << line2 << endl;
  inLine2 = inLine2 + 1;
  }
  arquivo.close();
  arquivo_temp.close();
  cout << "Estadia do quarto " << quarto << " finalizada" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void pesquisa( )
{
// identificar
 cout << endl << "Pesquisar por participantes do hotel: " << endl;
  int cliente = 0;
  int funcionario = 0;
  int escolha = 0;
 cout << "Deseja pesquisar por um funcionario ou por um cliente? funcionario = 1 cliente = 2"
 << endl;
 cin >> escolha;
 if (escolha != 1 && escolha != 2){cout << "escolha invalida" << endl; return;}
 if (escolha == 1)
 {
  cout << "escreva o codigo do funcionario: " << endl;
  cout << "| 1 | 2 | 3 | 4 |" << endl;
  cin >> funcionario;
  if (funcionario > 4 || funcionario < 1){cout << " codigo alem dos limites do hotel" 
  << endl; return;}
  string create;
  create = "funcionario";
  string cl = to_string(funcionario);
  string file = create + cl + ".txt";
  ifstream arquivo(file);
  if (!arquivo.is_open()) 
  {
    cout << "Funcionario: " << funcionario << " nao cadastrado." << endl;
    return;
  }
  string line1;
  while (getline(arquivo, line1)) 
  {
    cout << line1 << endl;
  }
  arquivo.close();
 }
 else
 {
  cout << "escreva o codigo do cliente: " << endl;
 cout << "| 1  | 2  | 3  | 4  | 5  | " << endl;
 cout << "| 6  | 7  | 8  | 9  | 10 |" << endl;
 cout << "| 11 | 12 | 13 | 14 | 15 | " << endl;
 cout << "| 16 | 17 | 18 | 19 | 20 |" << endl;
 cin >> cliente;
  if (cliente > 20 || cliente < 1){cout << " codigo alem dos limites do hotel" 
  << endl; return;}
  string create;
  create = "cliente";
  string cl = to_string(cliente);
  string file = create + cl + ".txt";
  ifstream arquivo(file);
  if (!arquivo.is_open()) 
  {
    cout << "Cliente: " << cliente<< " nao cadastrado." << endl;
    return;
  }
  string line2;
  cout << "dados do cliente: " << endl;
  while (getline(arquivo, line2)) 
  {
    cout << line2 << endl;
  }
  arquivo.close();
 }
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void estadia_cliente ( )
{
    int cliente = 0;
// identificar
 cout << endl << "Estadias por cliente: " << endl;
 cout << "escreva o codigo do cliente: " << endl;
 cout << "| 1  | 2  | 3  | 4  | 5  | " << endl;
 cout << "| 6  | 7  | 8  | 9  | 10 |" << endl;
 cout << "| 11 | 12 | 13 | 14 | 15 | " << endl;
 cout << "| 16 | 17 | 18 | 19 | 20 |" << endl;
 cin >> cliente;
  if (cliente > 20 || cliente < 1){cout << " codigo alem dos limites do hotel" 
  << endl; return;}
  string cli = to_string(cliente);
cout << "Estadias do cliente " << cliente << ":" << endl;
for (int i = 1; i < 25; i = i + 1)
{
  string create2;
  create2 = "quarto";
  string cl = to_string(i);
  string file = create2 + cl + ".txt";
  ifstream arquivo_temp(file);
  string linha2;
  int linhac = 0;
    while (getline(arquivo_temp, linha2)) 
    {
      linhac = linhac + 1;
      if (linhac == 9)
      {
            if (linha2.find(cli) != string::npos) 
            {
              cout << "| " << i << " | ";
            } 
            break;
      }
    }
  arquivo_temp.close();
}
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
void lucros_month ( )
{
// identificar
 cout << endl << "Lucro por mes:" << endl;
 int mes = 0;
 cin.ignore();
 cout << "Qual mes deseja analisar o lucro: " << endl;
 cin >> mes;
 if (mes < 1 || mes > 12){cout << "erro - mes inexistente" << endl; return; }
 string cli = to_string(mes);
 int total = 0;
for (int i = 1; i < 25; i = i + 1)
{
 int temp_int = 0;
 string linha1;
 string linha2;
  string create;
  create = "quarto";
  string cl = to_string(i);
  string file = create + cl + ".txt";
  ifstream arquivo_temp(file);
  string linha;
  string me = to_string(mes);
  int linhac = 0;
    while (getline(arquivo_temp, linha)) 
    {
      linhac = linhac + 1;
      if (linhac == 7)
      {
        linha1 = linha;
      }
      if (linhac == 14)
      {
        linha2 = linha;
        if (linha2 == me)
        {
          temp_int = stoi(linha1);
          total = total + temp_int;
        }
      }
    }
  arquivo_temp.close();
}
cout << "total de lucro no mes " << mes << " eh de " << total << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
}
int main ( int argc, char** argv )
{
// definir dado
 int x = 0;
 do
 {
 // identificar
 cout <<  "29/11/2024"   << endl; 
 cout << "Miguel Pessoa - Matricula 867160" << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - Cadastrar cliente" << endl;
 cout << " 2 - Cadastrar funcionario" << endl;
 cout << " 3 - Cadastrar quarto" << endl;
 cout << " 4 - Iniciar estadia" << endl;
 cout << " 5 - Encerrar estadia" << endl;
 cout << " 6 - Pesquisar partiipantes" << endl;
 cout << " 7 - Verificar estadias do cliente" << endl;
 cout << " 8 - Verificar lucro por mes" << endl;
 // ler do teclado
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
 switch ( x )
 {
 case 0: metodo00 ( ); break;
 case 1: cliente ( ); break;
 case 2: funcionario ( ); break;
 case 3: quarto ( ); break;
 case 4: start_estadia ( ); break;
 case 5: end_estadia ( ); break;
 case 6: pesquisa ( ); break;
 case 7: estadia_cliente ( ); break;
 case 8: lucros_month ( ); break;
 default:
 cout << endl << "ERRO: Valor invalido." << endl;
 } // end switch
 }
 while ( x != 0 );
// encerrar
 pause ( "Apertar ENTER para terminar" );
 return ( 0 );
}