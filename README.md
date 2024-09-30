Objetivo do Projeto:

O objetivo deste projeto é simular uma carteira de investimentos em C, onde os usuários podem gerenciar suas contas e realizar operações básicas como consulta de saldo, depósito, saque, e login com verificação de senha. Além disso, o projeto permite que usuários comprem e vendam criptomoedas.

Funcionalidades:

Cadastro de usuários: Os usuários podem se cadastrar utilizando um CPF e uma senha.
Login de usuários: Para acessar o sistema, é necessário fornecer um CPF e senha válidos.
Consulta de saldo: Os usuários podem consultar seus saldos em reais, Bitcoin, Ethereum e Ripple.
Depósito de reais: Os usuários podem realizar depósitos em reais na sua carteira.
Saque de reais: Saques podem ser realizados após validação de senha.
Menu interativo: Após o login, os usuários acessam um menu onde podem escolher as ações que desejam realizar.

Como compilar e executar:
Compilação
Para compilar o código C, utilize o comando abaixo no terminal:
gcc Projeto_1.c -o Projeto_1

Execução
Após a compilação, execute o programa com o seguinte comando:
./Projeto_1

Como usar o programa
Cadastro de Usuários
No menu inicial, escolha a opção 1 para cadastrar um novo usuário.
O programa solicitará o CPF e a senha. Após isso, o usuário será registrado com saldos iniciais zerados.

Fazer Login
No menu inicial, escolha a opção 2 para fazer login.
Digite o CPF e a senha para acessar o sistema. Se o login for bem-sucedido, o menu principal será exibido.

Menu Principal
Após o login, o menu principal será exibido com as seguintes opções:
Consultar Saldo: Ver os saldos de reais e criptomoedas.
Depositar Reais: Informe um valor para adicionar à sua conta de reais.
Sacar Reais: Informe um valor para saque, seguido pela validação da senha.
Sair: Finaliza a sessão e retorna ao menu inicial.

Sair do Sistema
Para encerrar o programa, escolha a opção 3 no menu inicial.
