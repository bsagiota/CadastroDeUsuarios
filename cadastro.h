#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "usuario.h"
#include <map>
class Cadastro {
private:
    std::map<int, Usuario> usuarios;

public:
    bool adicionarUsuario(const Usuario& usuario);
    Usuario* getUsuarioPorCPF(int cpf);
    std::map<int, Usuario> getUsuarios() const;
    bool adicionarCreditoPara(int cpf, int creditos);
    bool transferirCreditos(int cpf_origem, int cpf_destino, int creditos);
};

#endif