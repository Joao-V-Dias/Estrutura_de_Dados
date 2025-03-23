#include <iostream>
#include <string>
using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;

    void setData(){
        cout << "Digite a data no formato (DD MM AAAA): ";
        cin >> dia >> mes >> ano;
        cin.clear();
    }

    string getData(){
        return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
    }
};

struct Cliente {
    string nome;
    struct Data dataNascimento;
    char sexo;

    int calcularIdade(Data dataAtual){
        int idade = dataAtual.ano - dataNascimento.ano;

        if (dataAtual.mes < dataNascimento.mes || 
            (dataAtual.mes == dataNascimento.mes && dataAtual.dia < dataNascimento.dia)) {
            idade--;
        }

        return idade;
    }

    void setCliente(){
        cout << "Cadastrar Cliente" << endl;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Data de nascimento - ";
        dataNascimento.setData();
        cout << "Sexo (M/F): ";
        cin >> sexo;
        cout << "Cliente cadastrado!" << endl;
    }

    void getCliente(Data dataAtual){
        cout << "Nome: " << nome << endl;
        cout << "Data de nascimento: " << dataNascimento.getData() << endl;
        cout << "Idade: " << calcularIdade(dataAtual) << endl;
        cout << "Sexo: " << (sexo == 'M' ? "Masculino" : "Feminino") << endl;
        cout << "**********************" << endl << endl;
    }
};

int menu(){
    int opcao;
    cout << "**********************" << endl << endl;
    cout << "Menu" << endl;
    cout << "1 - Cadastrar cliente" << endl;
    cout << "2 - Listar clientes" << endl;
    cout << "3 - Sair" << endl;
    cout << "Digite um dos numeros acima: ";
    cin >> opcao;
    cin.clear();
    cout << "**********************" << endl << endl;
    return opcao;
}

int main() {
    struct Data dataAtual;
    dataAtual.setData();

    int max = 50, idCliente = 0;
    struct Cliente clientes[max];

    while(true){
        switch (menu()){
            case 1:
                if(idCliente < max){
                    clientes[idCliente].setCliente();
                    idCliente++;
                }else{
                    cout << "Numero maximo de clientes atingido." << endl;
                }
                break;
            case 2:
                if(idCliente == 0){
                    cout << "Nenhum cliente foi cadastrado ainda!" << endl;
                }else{
                    cout << "Lista de clientes" << endl;
                    for(int i = 0 ; i < idCliente ; i++){
                        clientes[i].getCliente(dataAtual);
                    }
                }
                break;
            case 3:
                cout << "Saindo";
                return 0;
                break;
            default:
                cout << "Opcao invalida! Tente novamente" << endl;
                break;
        }
    }

    return 0;
}