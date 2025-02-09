# FIFO IPC em C para Linux

Este repositório contém um programa em C que utiliza FIFO (First In, First Out) para comunicação entre processos no Linux. O programa consiste em dois arquivos principais: um para leitura e outro para escrita na FIFO.

## Requisitos

- Sistema operacional Linux
- Compilador GCC

## Compilando e Executando

1. Compile os arquivos fonte:
   gcc -o leitor leitor.c 
   gcc -o escritor escritor.c 

2. Execute primeiro o programa leitor:
   ./leitor

3. Em outra janela de terminal, execute o programa escritor:
   ./escritor

4. Digite mensagens no terminal do escritor. O leitor exibirá as mensagens recebidas.
   Para finalizar a comunicação, digite fim no escritor.

## Estrutura do Código

O programa consiste em dois arquivos principais:

### Leitor (leitor.c)

- Cria um FIFO nomeado.
- Abre o FIFO para leitura.
- Lê mensagens do FIFO e as exibe no terminal.
- Fecha e remove o FIFO ao finalizar.

### Escritor (escritor.c)

- Verifica a existência do FIFO.
- Abre o FIFO para escrita.
- Envia mensagens digitadas pelo usuário para o FIFO.
- Fecha o FIFO ao finalizar.

## Observações

- O arquivo util.h deve conter a definição de PIPE_NAME:
  #define PIPE_NAME "fifo_pipe"

- Certifique-se de que o FIFO foi criado antes de executar o escritor.
- O leitor deve ser iniciado antes do escritor para garantir a comunicação correta.

## Licença

Sinta-se à vontade para modificar e compartilhar.

Desenvolvido por Lucas Monteiro

