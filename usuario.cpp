#include "usuario.h"
Usuario::Usuario() : nome(""), cpf(0), creditos(0) {}
Usuario::Usuario(const std::string& nome, int cpf) : nome(nome), cpf(cpf), creditos(10) {}
std::string Usuario::getNome() const { return nome; }
void Usuario::setNome(const std::string& novoNome) {
    if (!novoNome.empty()) {
        nome = novoNome;
    }
}
int Usuario::getCPF() const { return cpf; }
int Usuario::getCreditos() const { return creditos; }
bool Usuario::adicionarCreditos(int quantidade) {
    if (quantidade > 0) {
        creditos += quantidade;
        return true;
    }
    return false;
}
bool Usuario::removerCreditos(int quantidade) {
    if (quantidade > 0 && creditos >= quantidade) {
        creditos -= quantidade;
        return true;
    }
    return false;
}
Usuario& Usuario::operator++() {
    ++creditos;
    return *this;
}
Usuario Usuario::operator++(int) {
    Usuario temp = *this;
    ++(*this);
    return temp;
}
Usuario& Usuario::operator--() {
    if (creditos > 0) {
        --creditos;
    }
    return *this;
}
Usuario Usuario::operator--(int) {
    Usuario temp = *this;
    --(*this);
    return temp;
}
