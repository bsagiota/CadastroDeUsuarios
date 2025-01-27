#include "cadastro.h"
bool Cadastro::adicionarUsuario(const Usuario& usuario) {
    if (usuarios.find(usuario.getCPF()) == usuarios.end()) {
        usuarios[usuario.getCPF()] = usuario;
        return true;
    }
    return false;
}
Usuario* Cadastro::getUsuarioPorCPF(int cpf) {
    auto it = usuarios.find(cpf);
    if (it != usuarios.end()) {
        return &(it->second);
    }
    return nullptr;
}
std::map<int, Usuario> Cadastro::getUsuarios() const {
    return usuarios;
}
bool Cadastro::adicionarCreditoPara(int cpf, int creditos) {
    auto it = usuarios.find(cpf);
    if (it != usuarios.end()) {
        return it->second.adicionarCreditos(creditos);
    }
    return false;
}
bool Cadastro::transferirCreditos(int cpf_origem, int cpf_destino, int creditos) {
    auto origem = usuarios.find(cpf_origem);
    auto destino = usuarios.find(cpf_destino);

    if (origem != usuarios.end() && destino != usuarios.end()) {
        if (origem->second.removerCreditos(creditos)) {
            destino->second.adicionarCreditos(creditos);
            return true;
        }
    }
    return false;
}