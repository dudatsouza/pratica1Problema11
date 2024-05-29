#include "problema11.hpp"

const std::string bold_on = "\033[1m";
const std::string bold_off = "\033[0m";

void limparconsole() {
    system("clear");
}

void apresentacao() {
    limparconsole();

    std::cout <<  bold_on << "PROBLEMA 11 - PROCESSAMENTO DE ARQUIVOS" << bold_off << std::endl;
    std::cout << "\nEXPLICAÇÃO: " << std::endl;
    std::cout << "Esse problema foi sugerido pelo professor Michel Pires, da diciplina de Algoritmos e Estruturas de Dados I. "
        "Ele consiste em um programa que mede o tempo de execução de propostas de processamento de conjuntos de processos, onde "
        "a ideia dessas propostas é calcular a soma da raiz quadrada dos valores contidos em cada arquivo de um processo. O "
        "processo é composto por linhas, onde cada linha contém um conjunto de arquivos. Cada arquivo contém uma sequência de "
        "números inteiros. O programa deve ler os arquivos indicados e calcular a soma da raiz quadrada dos valores contidos em " 
        "cada um desses arquivos. Esse processo é repetido para cada linha do processo. Após calcular a soma por linha e subtrair "
        "o resultado temporário obtido da próxima linha executada, o resultado final de cada processo é salvo em um arquivo de saída.\n" << std::endl;

    std::cout << "O programa foi dividido em 3 propostas de processamento de conjuntos de processos, cada proposta foi implementada "
        "de uma forma diferente, onde:\n" << std::endl;
    std::cout << bold_on << "- PROPOSTA 1: " << bold_off << "Nessa proposta, o programa processa cada linha de um processo de forma "
        "sequencial, ou seja, ele processa a linha 1, depois a linha 2 e assim por diante até a última linha do processo.\n" << std::endl;
    std::cout << bold_on << "- PROPOSTA 2: " << bold_off << "Nessa proposta, o programa processa cada linha de um processo e reaproveita "
        "a operação de cálculo quando o número do arquivo for o mesmo, ou seja, se um arquivo já foi processado, a soma das raizes quadradas "
        "é guardada e utilizada apenas esse resultados, sem a necessidade de calcular tudo denovo.\n" << std::endl;
    std::cout << bold_on << "- PROPOSTA 3: " << bold_off << "Nessa proposta, é bem parecida com a segunda proposta, porém, o que muda é a forma "
        "de encontrar o valor já calculada no vetor que está armazenado, fazendo com que seja um pouco mais rápido o retorno. Na proposta 2, "
        "era calculada e armazenada a soma das raizes de cada arquivo por cada processo, ou seja qnd mudava de processo aqueles resultados armazenados "
        "eram descartados. Aqui nesta proposta, as somas de cada arquivo é armazenada e mantida mesmo na troca de um processo para outro.\n" << std::endl;
    std::cout << bold_on << "- PROPOSTA 4: " << bold_off << "Nessa proposta, utilizando a ideia da proposta 3, e buscando com que o tempo de execução "
        "seja ainda menor, foi implementado um algoritmo de ordenação quicksort para ordenar cada processo de acordo com a quantidade de arquivos por linha, "
        "fazendo com que a linha com mais arquivos seja processada primeiro, para que o reaproveitamento de cálculos seja mais eficiente.\n" << std::endl;
    std::cout << bold_on << "- PROPOSTA 5: " << bold_off << "Nessa proposta, é bem semelhante a proposta 3, porém, foi implementado um cache de arquivos, "
        "onde o programa armazena os resultados de cada arquivo em um vetor de cache, fazendo com que o reaproveitamento de cálculos seja mais eficiente. A diferença "
        "dessa proposta para a proposta 3 é que aqui, o programa armazena os resultados de cada arquivo em um vetor de cache em ordem crescente, e quando um arquivo é "
        "processado, o programa busca no vetor de cache o resultado daquele arquivo usando busca binaria, se o arquivo não estiver no cache, o programa calcula a soma "
        "das raizes quadradas e armazena no cache.\n" << std::endl;
    std::cout << bold_on << "- PROPOSTA 6: " << bold_off << "Nessa proposta, é bem semelhante a proposta 5, porém, aqui é calculado a soma das raizes quadradas de"
        "todos os arquivos e armazena em um vetor de cache, e quando um arquivo é processado, o programa busca no vetor de cache o resultado daquele arquivo usando "
        "busca binaria, se o arquivo não estiver no cache, o programa calcula a soma das raizes quadradas e armazena no cache.\n" << std::endl;

    std::cout << "Para medir o tempo de execução de cada proposta, foi gerado um conjunto de processos e arquivos, onde o usuário pode "
        "escolher a quantidade de processos e arquivos que deseja gerar. Após gerar os processos e arquivos, o programa irá processar cada "
        "proposta e medir o tempo de execução de cada uma delas.\n" << std::endl;
    std::cout << "Dê ENTER para continuar e começar a executar o programa...";
    std::cin.get();
    limparconsole();
}

std::vector<int> preparandoConjuntos(int qntProcesso) {
    std::cout << "\n--------------------------------------------" << std::endl;
    std::cout << "PREPARANDO OS CONJUNTOS DE PROCESSOS\n" << std::endl;
    std::cout << "Digite a quantidade de conjuntos de processos que deseja medir o tempo de execução: ";
    int qntConjuntos;
    std::cin >> qntConjuntos;

    std::vector<int> qntConjuntosProcessos;
    for (int i = 0; i < qntConjuntos; i++) {
        std::cout << "Digite a quantidade de processos do conjunto " << i + 1 << ": ";
        int qntProcessos;   
        std::cin >> qntProcessos;
        if(qntProcessos <= qntProcesso) {
            qntConjuntosProcessos.push_back(qntProcessos);
        } else {
            std::cout << "A quantidade de processos não pode ser maior que a quantidade de processos gerados. Digite novamente." << std::endl;
            i--;
        }
    }
    return qntConjuntosProcessos;
    limparconsole();
}

void analiseDeResultados() {
    limparconsole();

    std::cout << bold_on << "ANÁLISE DOS RESULTADOS\n" << bold_off << std::endl;
    std::cout << "Antes de chegar a uma conclusão de qual proposta é melhor, vamos analisar qual o custo computacional de cada uma.\n" << std::endl;

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "CUSTO COMPUTACIONAL\n" << std::endl;
    std::cout << bold_on << "PROPOSTA 1: " << bold_off << "O custo computacional dessa proposta é de O(p * a * n), onde p é a quantidade de processos, a é a quantidade de "
    "arquivos por processo e n é a quantidade de numeros por arquivo\n" << std::endl;


    std::cout << "Dê ENTER para finalizar o programa...";
    std::cin.get();
}

int main() {  
    apresentacao();  
    std::cout << bold_on << "EXECUÇÃO DO PROGRAMA\n" << bold_off << std::endl;
    int qntProcesso; 
    int qntArquivos;
    gerarProcessosEArquivos(qntProcesso, qntArquivos);
    std::vector<int> qntConjuntosProcessos = preparandoConjuntos(qntProcesso);    
    limparconsole();
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "INICIANDO A MEDIÇÃO DO TEMPO DE EXECUÇÃO DAS PROPOSTAS\n" << std::endl;
    std::cout << "Qnt | prop 1 |  prop 2 |  prop 3 | prop 4 | prop 5 | prop 6" << std::endl;
    for (int qnt : qntConjuntosProcessos) {
        std::cout << qnt << " | ";
        medindoTempoDeExecucaoDeCadaProposta(qnt, qntArquivos);
        std::cout << std::endl;
    } 
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "FIM DA MEDIÇÃO DO TEMPO DE EXECUÇÃO DAS PROPOSTAS\n" << std::endl;
    std::cout << "Dê ENTER para continuar...";
    std::cin.get();
    std::cin.get();
    analiseDeResultados();
    return 0;
}
