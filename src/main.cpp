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
    std::cout << bold_on << "- PROPOSTA 3: " << bold_off << "Nessa proposta, é bem parecida com a segunda proposta, porém, o que muda é que aqui "
        "é utilizado uma espécie de cache goblal para todos os processos. Na proposta 2, era calculada e armazenada a soma das raizes de cada arquivo "
        "por cada processo, ou seja quando mudava de processo aqueles resultados armazenados eram descartados. Aqui nesta proposta, as somas de cada "
        "arquivo é armazenada e mantida mesmo na troca de um processo para outro.\n" << std::endl;
    std::cout << bold_on << "- PROPOSTA 4: " << bold_off << "Nessa proposta, utilizando a ideia da proposta 3, e buscando com que o tempo de execução "
        "seja ainda menor, foi implementado um algoritmo de ordenação quicksort para ordenar cada processo de acordo com a quantidade de arquivos por linha, "
        "fazendo com que a linha com mais arquivos seja processada primeiro, para que o reaproveitamento de cálculos seja mais eficiente.\n" << std::endl;
    std::cout << bold_on << "- PROPOSTA 5: " << bold_off << "Nessa proposta, é bem semelhante a proposta 3, porém, foi implementado um cache de arquivos, "
        "onde o programa armazena os resultados de cada arquivo em um vetor de cache, fazendo com que o reaproveitamento de cálculos seja mais eficiente. A diferença "
        "dessa proposta para a proposta 3 é que aqui, o programa armazena os resultados de cada arquivo em um vetor de cache em ordem crescente, e quando um arquivo é "
        "processado, o programa busca no vetor de cache o resultado daquele arquivo usando busca binaria, se o arquivo não estiver no cache, o programa calcula a soma "
        "das raizes quadradas e armazena no cache.\n" << std::endl;
    std::cout << bold_on << "- PROPOSTA 6: " << bold_off << "Nessa proposta, é bem semelhante a proposta 5, porém, aqui é calculado a soma das raizes quadradas de"
        "todos os arquivos e armazena em um vetor de cache, e quando um arquivo é processado, o programa pega no vetor de cache o resultado daquele arquivo sem a "
        "necessidade de fazer uma busca. Se o arquivo não estiver no cache, o programa calcula a soma das raizes quadradas e armazena no cache.\n" << std::endl;

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

    std::cout << bold_on << "ANÁLISE DOS RESULTADOS" << bold_off << std::endl;
    std::cout << "\nAntes de chegar a uma conclusão de qual proposta é melhor, vamos analisar qual o custo computacional de cada uma.\n" << std::endl;

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "CUSTO COMPUTACIONAL" << std::endl;
    std::cout << "\nCada uma das propostas apresentadas oferece vantagens e desvantagens, e a escolha da melhor depende de vários fatores, como o tipo de arquivos, a estrutura dos dados e os padrões de acesso. Aqui estão algumas considerações sobre o desempenho de cada proposta:" << std::endl;
    std::cout << "\nSabendo que: " << std::endl;
    std::cout << " - Q: quantidade de conjuntos de processos" << std::endl;
    std::cout << " - L: quantidade de linhas de um processo" << std::endl;
    std::cout << " - A: quantidade de arquivos por linha" << std::endl;
    std::cout << " - N: quantidade de números em um arquivo" << std::endl;  
    std::cout << " - C: quantidade de elementos no cache" << std::endl;
    std::cout << " - K: quantidade de números em um arquivo que não está no cache" << std::endl;
    std::cout << "Dessa forma, temos as seguintes análises, dê ENTER para continuar..." << std::endl;
    std::cin.get();

    std::cout << bold_on << "--- PROPOSTA 1 --- \n- Complexidade: " <<  bold_off << "O(Q * L * A * N)" << std::endl;
    std::cout << bold_on << "- Descrição: " << bold_off << "Cada linha de um arquivo de processo é lida e processada de forma sequencial, calculando a soma das raízes quadradas dos números nos arquivos referenciados." << std::endl;
    std::cout << bold_on << "- Limitação: " << bold_off << "Alta redundância, pois cada arquivo referenciado é processado repetidamente sem aproveitamento de cálculos anteriores, resultando em uma significativa ineficiência.\n" << std::endl;

    std::cout << bold_on << "--- PROPOSTA 2--- \n- Complexidade: " <<  bold_off << "O(N * L * A * (C + K))" << std::endl;
    std::cout << bold_on << "- Descrição: " << bold_off << "Introduz um cache para armazenar a soma das raízes quadradas de arquivos já processados dentro de um mesmo processo." << std::endl;
    std::cout << bold_on << "- Melhoria: " << bold_off << "Reduz a redundância dentro de um único processo, evitando recalcular somas de arquivos já processados." << std::endl;
    std::cout << bold_on << "- Limitação: " << bold_off << "O cache é descartado ao final de cada processo, não aproveitando os cálculos entre processos diferentes.\n" << std::endl;

    std::cout << bold_on << "--- PROPOSTA 3 --- \n- Complexidade: " <<  bold_off << "O(N * L * A * (C + K))" << std::endl;
    std::cout << bold_on << "- Descrição: " << bold_off << "Implementa um cache global que armazena os resultados das somas das raízes quadradas entre todos os processos." << std::endl;
    std::cout << bold_on << "- Melhoria: " << bold_off << "Aproveita os cálculos realizados entre diferentes processos, aumentando a eficiência global." << std::endl;
    std::cout << bold_on << "- Limitação: " << bold_off << "Embora o reaproveitamento de cálculos seja maximizado, a busca no cache pode ser ineficiente se não for otimizada.\n" << std::endl;

    std::cout << bold_on << "--- PROPOSTA 4 --- \n- Complexidade: " <<  bold_off << "O(N * (L log L + L * A * (C + K))" << std::endl;
    std::cout << bold_on << "- Descrição: " << bold_off << "Ordena as linhas de cada processo com base no número de arquivos referenciados antes de iniciar o processamento." << std::endl;
    std::cout << bold_on << "- Melhoria: " << bold_off << "Processa primeiro as linhas com mais arquivos referenciados, otimizando o reaproveitamento dos cálculos iniciais e melhorando a eficiência de cache." << std::endl;
    std::cout << bold_on << "- Limitação: " << bold_off << "A complexidade adicional da ordenação pode introduzir overhead, e a eficiência depende da distribuição dos dados.\n" << std::endl;

    std::cout << bold_on << "--- PROPOSTA 5 --- \n- Complexidade: " <<  bold_off << "O(Q + N * L * A * Q)" << std::endl;
    std::cout << bold_on << "- Descrição: " << bold_off << "Utiliza um vetor de cache ordenado para armazenar resultados e implementa busca binária para recuperação eficiente dos valores já calculados." << std::endl;
    std::cout << bold_on << "- Melhoria: " << bold_off << "A busca binária permite uma recuperação muito mais rápida dos valores no cache, otimizando significativamente o tempo de execução." << std::endl;
    std::cout << bold_on << "- Limitação: " << bold_off << "A manutenção do vetor ordenado e a inserção de novos valores podem introduzir alguma complexidade adicional.\n" << std::endl;

    std::cout << bold_on << "--- PROPOSTA 6 --- \n- Complexidade: " <<  bold_off << "O(Q * K + N * L * A)" << std::endl;
    std::cout << bold_on << "- Descrição: " << bold_off << "Pré-calcula a soma das raízes quadradas de todos os arquivos antes de processar os arquivos de processo, armazenando os resultados em um vetor de cache." << std::endl;
    std::cout << bold_on << "- Melhoria: " << bold_off << "Elimina completamente a necessidade de calcular somas durante o processamento dos arquivos de processo, pois todos os resultados estão pré-computados e disponíveis de forma imediata." << std::endl;
    std::cout << bold_on << "- Limitação: " << bold_off << "Requer um grande uso de memória para armazenar todos os resultados e um tempo inicial de processamento considerável para calcular todas as somas, mas este tempo é compensado pela eficiência do processamento subsequente.\n" << std::endl;    
    std::cout << "Dê ENTER para continuar..." << std::endl;
    std::cin.get();
    limparconsole();

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << bold_on << "ANÁLISE DE EFICIÊNCIA" << bold_off << std::endl;
    std::cout << "\nApós a implementação da Proposta 6, a análise dos tempos de execução e da eficiência revelou que: " << std::endl;
    std::cout << "\n- O tempo de execução para processar cada linha dos arquivos de processo foi drasticamente reduzido devido ao pré-cálculo e armazenamento eficiente das somas das raízes quadradas. A busca no vetor de cache pré-calculado é extremamente rápida, praticamente eliminando o tempo de processamento repetitivo." << std::endl;
    std::cout << "\n- Qualquer tentativa adicional de otimização apresentaria melhorias marginais a um custo operacional e de complexidade significativamente maior. A implementação de algoritmos mais sofisticados ou o uso de técnicas de paralelismo ou distribuição poderia resultar em ganhos menores em relação ao custo de implementação e manutenção." << std::endl;
    std::cout << "\n- O uso de um vetor de cache que armazena todas as somas das raízes quadradas pré-calculadas já é uma abordagem que maximiza o uso da memória disponível e do tempo de processamento inicial. As melhorias possíveis além desta abordagem seriam incrementais e não justificariam o esforço adicional necessário." << std::endl;
    std::cout << "\n- A Proposta 6, apesar de exigir um tempo de pré-processamento significativo, simplifica consideravelmente o código subsequente, tornando-o mais fácil de manter e menos propenso a erros. O design claro e eficiente facilita futuras modificações ou expansões do sistema." << std::endl;
    std::cout << "\nPortanto, a escolha da Proposta 6 como a solução final para parar de procurar outras maneiras foi baseada em uma análise detalhada de eficiência, complexidade, custo-benefício e simplicidade de manutenção. Esta proposta atende plenamente aos requisitos do problema, fornecendo um equilíbrio ideal entre desempenho e praticidade. Além de que através de testes realizados, já conseguimos ver uma grande evolução no tempo de execução desde a primeira proposta até a última.\n" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "\nDê ENTER para continuar..." << std::endl;
    std::cin.get();
    limparconsole();

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << bold_on << "CONCLUSÃO" << bold_off << std::endl;
    std::cout << "\nEste problema foi uma oportunidade valiosa para explorar diferentes abordagens de otimização de processamento de arquivos e avaliar o impacto de cada uma no desempenho geral do sistema. A análise detalhada das propostas e a medição do tempo de execução permitiram identificar as vantagens e desvantagens de cada abordagem e determinar a solução mais eficiente para o problema. Foi feito um estudo comparativo das propostas, considerando fatores como complexidade, eficiência, custo computacional e facilidade de manutenção." << std::endl;
    std::cout << "\nPara a maioria dos casos, a Proposta 3 se destaca como a mais eficiente devido ao seu uso de um cache global que minimiza redundâncias de cálculos. No entanto, a Proposta 5 com busca binária no cache oferece um equilíbrio interessante e pode ser preferível em situações com padrões de acesso muito variáveis. A Proposta 6 pode ser a melhor escolha em cenários onde a maioria dos arquivos é acessada, apesar do risco de calcular somas desnecessárias." << std::endl;
    std::cout << "\nConcluimos que escolha da melhor proposta depende de fatores específicos do problema, como a distribuição dos dados, a frequência de acesso e a disponibilidade de memória. A análise detalhada do desempenho de cada proposta é essencial para determinar a solução mais adequada para um caso específico." << std::endl;
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


    std::ofstream csvFile("./datasets/tempos_execucao.csv");
    csvFile << "QuantidadeConjuntos,Proposta1,Proposta2,Proposta3,Proposta4,Proposta5,Proposta6\n";

    for (int qnt : qntConjuntosProcessos) {
        std::cout << qnt << " | ";
        csvFile << qnt << ",";
        medindoTempoDeExecucaoDeCadaProposta(qnt, qntArquivos, csvFile);
        std::cout << std::endl;
    } 

    csvFile.close();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa o buffer de entrada

    std::cout << "\n--------------------------------------------" << std::endl;
    std::cout << "Dê ENTER para continuar..." << std::endl;
    std::cin.get();
    limparconsole();
    gerandoGrafico();
    analiseDeResultados();
    limparPastas();
    limparArquivosDeSaida();

    std::cout << "\n--------------------------------------------" << std::endl;
    std::cout << "Dê ENTER para finalizar o programa...";
    std::cin.get();
    limparconsole();

    std::cout << "\nAgradeço a atenção e a oportunidade de resolver esse problema. Vejo você na próxima!" << std::endl;

    std::cout << "\n\n--------------------------------------------" << std::endl;
    std::cout << "Feito por: " << bold_on << "Maria Eduarda Teixeira Souza" << bold_off << std::endl;
    std::cout << "         - Engenharia de Computação - 2024/1 - CEFET/MG - Campus V" << std::endl;
    std::cout << "         - Disciplina de Algoritmos e Estruturas de Dados I" << std::endl;
    std::cout << "         - https://github.com/dudatsouza/pratica1Problema11\n\n" << std::endl;

    return 0;
}

void gerandoGrafico() {
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "GRÁFICO DO DESEMPENHO DAS PROPOSTAS" << std::endl;
    std::cout << "Você deseja gerar o gráfico do desempenho das propostas? (s/n): ";
    char opcao;
    std::cin >> opcao;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa o buffer de entrada
    if (opcao == 's') {
        std::cout << "\n- Você será redirecionado para uma janela do navegador com o gráfico gerado, onde você poderá visualizar o desempenho de cada proposta da maneira que desejar." << std::endl;
        std::cout << "- Quando terminar de visualizar o gráfico, feche a janela do navegador para continuar aqui para a análise dos resultados." << std::endl;
        std::cout << "\nDê ENTER para continuar..." << std::endl;
        std::cin.get();

        std::cout << "Indo para o navegador...\n" << std::endl;

        std::string command = "python3 src/gerarGrafico.py";
        int result = system(command.c_str());
        if (result == 0) {
            std::cout << "Script Python executado com sucesso." << std::endl;
        } else {
            std::cerr << "Falha na execução do script Python." << std::endl;
        }
    } else {
        std::cout << "Gráfico não gerado." << std::endl;
    }

    std::cout << "--------------------------------------------\n" << std::endl;
    std::cout << "Dê ENTER para continuar..." << std::endl;
    std::cin.get();    
}
