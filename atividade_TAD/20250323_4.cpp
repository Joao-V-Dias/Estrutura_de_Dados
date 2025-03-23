#include <iostream>
#include <string>
using namespace std;

struct Livro{
    string titulo;
    string autor;
    int paginas;

    void ler(){
        cout << "Titulo: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Autor: ";
        getline(cin, autor);
        cout << "Numero de paginas: ";
        cin >> paginas;
    }

    void imprimir(){
        cout << "****************" << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Paginas: " << paginas << endl;
    }
};

void livroMaisPagina(Livro livros[], int livrosArmazendos){
    int idMaiorPagina = 0;
    for(int i = 1 ; i < livrosArmazendos ; i++){
        if(livros[i].paginas > livros[idMaiorPagina].paginas) idMaiorPagina = i;
    }
    livros[idMaiorPagina].imprimir();
}

int menu(){
    int opcao;
    cout << "**********************" << endl << endl;
    cout << "Menu" << endl;
    cout << "1 - Cadastrar livro" << endl;
    cout << "2 - Listar livros" << endl;
    cout << "3 - Livro com maior numero de paginas" << endl;
    cout << "4 - Sair" << endl;
    cout << "Digite um dos numeros acima: ";
    cin >> opcao;
    cin.clear();
    cout << "**********************" << endl << endl;
    return opcao;
}

int main(){
    int livrosArmazendos = 0, max = 10;
    struct Livro livros[max];
    while(true){
        switch (menu()){
            case 1:
                livros[livrosArmazendos].ler();
                livrosArmazendos++;
                break;
            case 2:
                if(livrosArmazendos == 0){
                    cout << "Nenhum livro registrado" << endl;
                    break; 
                }

                for(int i = 0 ; i < livrosArmazendos ; i++){
                    livros[i].imprimir();
                }
                break;
            case 3:
                if(livrosArmazendos > 0)livroMaisPagina(livros, livrosArmazendos);
                else cout << "Nenhum livro registrado" << endl;;
                break;
            case 4:
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

/*
4. Faça um programa que seja capaz de armazenar informações sobre livros de uma biblioteca.
Seu programa deve ter um TAD para representar o livro, contendo título, autor e número de páginas. 
Além disso, seu TAD deve ter duas operações: ler e imprimir.
Seu programa também deve ter um TAD para representar toda a biblioteca, contendo um vetor de livros e a quantidade de livros já armazenados nessa TAD. 
O máximo de livros na TAD biblioteca será 10. 
Seu TAD deve ter uma operação capaz de ler um novo livro, uma operação para imprimir todos os livros da biblioteca e outra operação capaz de imprimir o livro que contém o maior número de páginas de toda a biblioteca.
*/