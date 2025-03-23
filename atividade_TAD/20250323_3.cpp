#include <iostream>
#include <string>
using namespace std;

struct Funcionario{
    string nome;
    string cargo;
    double salarioBase;
    double beneficios;
    double descontos;

    double calcularSalarioLiquido(){
        return salarioBase + beneficios - descontos;
    }

    void cadastrarFuncionario(){
        cout << "Cadastrar Funcionario" << endl;
        cout << "Nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Cargo: ";
        getline(cin, cargo);
        cout << "Salario base: ";
        cin >> salarioBase;
        cout << "Beneficios: ";
        cin >> beneficios;
        cout << "Descontos: ";
        cin >> descontos;
        cout << "Funcionario cadastrado" << endl << "************************" << endl;
    }

    void mostrarFuncionario(){
        cout << "Nome: " << nome << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Salario liquido: R$ " << calcularSalarioLiquido() << endl;
        cout << "*************************************" << endl;
    }
};

double mediaSalarial(Funcionario funcionarios[], int numFuncionarios){
    double media = 0;
    for(int i = 0 ; i < numFuncionarios ; i++){
        media+= funcionarios[i].calcularSalarioLiquido();
    }
    return media / numFuncionarios;
}

string maiorSalario(Funcionario funcionarios[], int numFuncionarios){
    int idMaiorSalario = 0;
    for(int i = 1 ; i < numFuncionarios; i++){
        if(funcionarios[i].calcularSalarioLiquido() > funcionarios[idMaiorSalario].calcularSalarioLiquido()) idMaiorSalario = i;
    }

    return "Funcionario com maior salario: " + funcionarios[idMaiorSalario].nome + "\n******************\n";
}

int main(){
    int numFuncionarios = 10;
    struct Funcionario funcionarios[numFuncionarios];

    for(int i = 0 ; i < numFuncionarios ; i++){
        funcionarios[i].cadastrarFuncionario();
    }

    for(int i = 0 ; i < numFuncionarios ; i++){
        funcionarios[i].mostrarFuncionario();
    }

    double media = mediaSalarial(funcionarios, numFuncionarios);
    cout << "Media Salarial: " << media << endl;

    cout << maiorSalario(funcionarios, numFuncionarios) << endl;

    return 0;
}

/*
3. Uma loja precisa controlar a folha de pagamento de seus funcionários. 
-----Os atributos de um funcionário são nome, cargo, salário base, benefícios e descontos.
-----Criar uma struct para a loja e cadastrar uma lista de no máximo 10 funcionários com os campos acima e depois mostre os dados de cada um deles, com o salário liquido de cada um. 
-----O cálculo do salário líquido é: salário base + benefícios – descontos.
Criar operações também para exibir a média salarial da loja e exibir quem recebe o maior salário.
*/