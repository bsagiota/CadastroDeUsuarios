#include <iostream>
#include "cadastro.h"
int main() {
    Cadastro cadastro;
    while (true) {
        std::cout << "1. Adicionar Usuario\n";
        std::cout << "2. Buscar Usuario\n";
        std::cout << "3. Adicionar Creditos\n";
        std::cout << "4. Transferir Creditos\n";
        std::cout << "5. Sair\n";
        std::cout << "Escolha uma opcao: ";
        int opcao;
        std::cin >> opcao;
        if (opcao == 1) {
            std::string nome;
            int cpf;
            std::cout << "Nome: ";
            std::cin >> nome;
            std::cout << "CPF: ";
            std::cin >> cpf;
            Usuario usuario(nome, cpf);
            if (cadastro.adicionarUsuario(usuario)) {
                std::cout << "Usuario adicionado com sucesso.\n";
            } else {
                std::cout << "Erro: Usuario com esse CPF ja existe.\n";
            }
        } else if (opcao == 2) {
            int cpf;
            std::cout << "CPF: ";
            std::cin >> cpf;
            Usuario* usuario = cadastro.getUsuarioPorCPF(cpf);
            if (usuario) {
                std::cout << "Nome: " << usuario->getNome() << ", Creditos: " << usuario->getCreditos() << "\n";
            } else {
                std::cout << "Usuario nao encontrado.\n";
            }
        } else if (opcao == 3) {
            int cpf, creditos;
            std::cout << "CPF: ";
            std::cin >> cpf;
            std::cout << "Creditos: ";
            std::cin >> creditos;

            if (cadastro.adicionarCreditoPara(cpf, creditos)) {
                std::cout << "Creditos adicionados com sucesso.\n";
            } else {
                std::cout << "Erro ao adicionar creditos.\n";
            }
        } else if (opcao == 4) {
            int cpf_origem, cpf_destino, creditos;
            std::cout << "CPF de origem: ";
            std::cin >> cpf_origem;
            std::cout << "CPF de destino: ";
            std::cin >> cpf_destino;
            std::cout << "Creditos: ";
            std::cin >> creditos;

            if (cadastro.transferirCreditos(cpf_origem, cpf_destino, creditos)) {
                std::cout << "Transferencia realizada com sucesso.\n";
            } else {
                std::cout << "Erro na transferencia.\n";
            }
        } else if (opcao == 5) {
            break;
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }

    return 0;
}
