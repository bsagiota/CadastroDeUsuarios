#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <string>
class Usuario {
private:
    std::string nome;
    int cpf;
    int creditos;
public:
    Usuario();
    Usuario(const std::string& nome, int cpf);
    std::string getNome() const;
    void setNome(const std::string& nome);
    int getCPF() const;
    int getCreditos() const;
    bool adicionarCreditos(int quantidade);
    bool removerCreditos(int quantidade);
    Usuario& operator++();
    Usuario operator++(int);
    Usuario& operator--(); 
    Usuario operator--(int);
};

#endif
