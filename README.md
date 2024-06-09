# 🗃️ Prática 1 - Problema 11

<!-- -arrumar topicos no sumario
     -fazer seção de implementação  
     -fazer mudanças nas analise de complexidade proposta 1 (M -> A)
     -fazer seção de exemplos 
     -fazer seção do grafico em python
     -fazer seção das analises de resultados 
     -fazer seção de conclusão 
-->



<div align="center">
   <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Ubuntu-orange?logo=ubuntu">
   <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/VS%20Code-blue?logo=visual%20studio%20code"/>
   <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/MakeFile-green?logo=make">
   <img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-darkblue?logo=c%2B%2B"/>
</div>

<details>
  <summary>📌 Tópicos</summary>
    <ol>
        <li><a href="#-introdução">Introdução</a></li>
        <li><a href="#-análise-assintótica">Análise Assintótica</a></li>
        <li><a href="#-implementação">Implementação</a></li>
        <li><a href="#-análise-de-complexidade-de-cada-proposta">Análise de Complexidade de Cada Proposta</a></li>        
        <li><a href="#-estrutura-de-diretorios">Estrutura de Diretórios</a></li>
        <li><a href="#-como-usar">Como Usar</a></li>
        <li><a href="#-exemplos">Exemplos</a></li>
        <li><a href="#-resultados-das-análises">Resultados Das Análises</a></li>
        <li><a href="#-conclusão">Conclusão</a></li>
        <li><a href="#-ambiente-de-compilação">Ambiente de Compilação</a></li>
        <li><a href="#-makefile">MakeFile</a></li>
        <li><a href="#-contato">Contato</a></li>
        <li><a href="#-referências">Referências</a></li>
    </ol>
</details>

## 👋 Introdução 

Este problema foi apresentado através de uma atividade, Prática 1, do professor Michel Pires na disciplina de Algoritmos e Estruturas de Dados I. A atividades Prática 1 é composta por problemas sobre Análise Assintótica e Complexidade Computacional. O chamado Problema 11, consiste inicialmente em fazer o cálculo das somas das raízes quadradas dos números contidos em arquivos referenciados por arquivos de processo. A ideia do professor é fazer com que seus alunos sejam incentivados a explorar as oportunidades de avaliação e melhoria, discutindo essas melhorias e seus possíveis custos operacionais. 


### 📋 Descrição do Problema
Temos dois tipos principais de arquivos:
1. **Arquivos de Processos (`P1.txt`, `P2.txt`, ..., `PQ.txt`):** Cada um desses arquivos contém linhas que listam IDs de outros arquivos de dados. Cada linha representa um conjunto de arquivos a serem processados juntos *(< L1, 04, 07, 01, 01, 07, 06, . . . , 03 >)*. 
2. **Arquivos Referenciados (`A1.txt`, `A2.txt`, ..., `AN.txt`):** Estes arquivos contêm contém 100.000 números de ponto flutuante aleatórios, variando de 1 a 1.000.000 dos quais precisamos calcular a soma das raízes quadradas.

Para cada linha em cada arquivo de processo, precisamos:
1. Ler os IDs dos arquivos referenciados.
2. Para cada arquivo referenciado, calcular a soma das raízes quadradas dos números contidos nele.
3. Acumular esses resultados e escrever a soma no arquivo de saída correspondente.

### 📘 Abordagens
Para resolver o problema de forma eficiente, foram implementadas seis propostas distintas:

- *Proposta 1:* Nessa proposta, o programa processa cada linha de um processo de forma sequencial, ou seja, ele processa a linha 1, depois a linha 2 e assim por diante até a última linha do processo.

- *Proposta 2:* Nessa proposta, o programa processa cada linha de um processo e reaproveita a operação de cálculo quando o número do arquivo for o mesmo, ou seja, se um arquivo já foi processado, a soma das raízes quadradas é guardada e utilizada apenas esse resultado, sem a necessidade de calcular tudo de novo, isso para cada processo.

- *Proposta 3:* Nessa proposta, semelhante à segunda, o que muda é que aqui é utilizado uma espécie de cache goblal para todos os processos. Na proposta 2, era calculada e armazenada a soma das raizes de cada arquivo por cada processo, ou seja quando mudava de processo aqueles resultados armazenados eram descartados. Aqui nesta proposta, as somas de cada arquivo é armazenada e mantida mesmo na troca de um processo para outro.

- *Proposta 4:* Nessa proposta, utilizando a ideia da proposta 3, e buscando com que o tempo de execução seja ainda menor, foi implementado um algoritmo de ordenação quicksort para ordenar cada processo de acordo com a quantidade de arquivos por linha, fazendo com que a linha com mais arquivos seja processada primeiro, para que o reaproveitamento de cálculos seja mais eficiente.

- *Proposta 5:* Nessa proposta, semelhante à proposta 3, foi implementado um cache de arquivos, onde o programa armazena os resultados de cada arquivo em um vetor de cache, fazendo com que o reaproveitamento de cálculos seja mais eficiente. A diferença desta proposta para a proposta 3 é que aqui, o programa armazena os resultados de cada arquivo em um vetor de cache em ordem crescente, e quando um arquivo é processado, o programa busca no vetor de cache o resultado daquele arquivo usando busca binária. Se o arquivo não estiver no cache, o programa calcula a soma das raízes quadradas e armazena no cache.

- *Proposta 6:* Nessa proposta, semelhante à proposta 5, é calculada a soma das raízes quadradas de todos os arquivos antes de olhar para os processos e armazenada em um vetor de cache. Quando um arquivo é processado, o programa pega no vetor de cache o resultado daquele arquivo sem a necessidade de fazer uma busca. Se o arquivo não estiver no cache, o programa calcula a soma das raízes quadradas e armazena no cache.

### 🎯 Objetivo

O principal objetivo deste projeto é demonstrar como diferentes técnicas de otimização podem ser aplicadas para reduzir o tempo de processamento e aumentar a eficiência na leitura e cálculo de grandes volumes de dados. Através da comparação das seis abordagens, busca-se identificar a mais eficiente e escalável, oferecendo uma solução prática para problemas semelhantes em contextos de processamento intensivo de dados.


## 🛠️ Desenvolvimento
O desenvolvimento se iniciou na primeira proposta onde a ideia era apenas fazer o cálculo das somas das raízes sem pensar em nenhuma eficiência ou custeio. Esta proposta serviu como base para entender o problema e implementar a solução de forma direta.

### 📌 Proposta 1
Na primeira abordagem, o programa processa cada linha de um processo de forma sequencial:
1. Ler os IDs dos arquivos referenciados.
2. Para cada arquivo, calcular a soma das raízes quadradas dos números contidos nele.
3. Acumular os resultados e escrever a soma no arquivo de saída correspondente.

Depois, uma proposta apresentada pelo próprio professor, de reaproveitar a operação de cálculo quando o número do arquivo for o mesmo. Assim foi feita na proposta 2.

### 📌 Proposta 2
A segunda proposta introduziu um mecanismo para otimizar o tempo de processamento:
1. Implementar um armazenamento para os resultados das somas das raízes quadradas de cada arquivo processado.
2. Reutilizar os resultados armazenados para arquivos já processados, evitando cálculos redundantes, em cada processo.

Após ver a descrepante diferença entre o tempo de execução da proposta 1 e a proposta 2, pude pensar em uma maneira ainda melhor de otimizar esse tempo, pensando da mesma forma que na proposta 2. Na proposta anterior, a cada processo tinha um cache que armazenava as somas dos arquivos calculados, porém quando ia ter a troca de processo esse cache era apagado e um novo era criando, então foi implementado agora uma espécie de cache global, para que todos os processos que iam ser calculados pudessem ter acesso. 

### 📌 Proposta 3
A terceira proposta aprimorou a reutilização dos cálculos:
1. Manter os resultados das somas das raízes quadradas dos arquivos processados, mesmo na troca de processos.
2. Melhorar a busca dos resultados armazenados no vetor, tornando o retorno dos valores mais eficiente.

Vendo agora uma maior eficiência e um melhor desempenho, pensei em ainda mais melhorar. A ideia era fazer com que fosse calculado uma grande quantidade de arquivos inicialmente para que já fosse armazenados para serem usados posteriormente. Então foi escolhido o método de ordenação QuickSort para ordenar as linhas dos processos. 

### 📌 Proposta 4
A quarta proposta introduziu a ordenação das linhas dos processos para maximizar a eficiência:
1. Utilizar o algoritmo de ordenação quicksort para ordenar as linhas de cada processo pela quantidade de arquivos.
2. Processar primeiramente as linhas com mais arquivos, otimizando o reaproveitamento dos cálculos.

Após implementar essa ordenação e observar uma pequena melhoria no tempo de execução em alguns caso, a próxima etapa foi pensar em como armazenar esses resultados de forma mais eficiente, permitindo um acesso rápido e fácil durante o processamento. Então foi pensado apartir da proposta 3, uma maneira melhor de encontrar mais rápido oas dados no cache. Assim, a adição de novos itens no cache foi feita de forma crescente e para buscá-los foi implementado a busca binária. 

### 📌 Proposta 5
A quinta proposta implementou uma ordenação no cache de arquivos para armazenamento e uma busca binária mais eficiente:
1. Armazenar os resultados das somas das raízes quadradas de cada arquivo em um vetor de cache em ordem crescente.
2. Utilizar busca binária para encontrar rapidamente os resultados no cache.
3. Caso o arquivo não esteja no cache, calcular a soma e armazenar o resultado.

Essa abordagem de cache mostrou-se altamente eficaz, reduzindo ainda mais o tempo de execução do programa. No entanto, ainda havia espaço para otimizações adicionais. Pensando na hipótese de não fazer uma busca, foi pensado em uma nova proposta que inicialmente calculava as somas das raízes quadradas de todos os arquivos antes de fazer os processamentos. 

### 📌 Proposta 6
A sexta e última proposta combinou as melhorias anteriores com um cache global:
1. Calcular a soma das raízes quadradas de todos os arquivos e armazenar em um vetor de cache.
2. Utilizar busca binária para encontrar os resultados no cache ao processar cada linha.
3. Se o arquivo não estiver no cache, calcular a soma e armazenar o resultado.

Com essa última proposta, conseguimos alcançar um alto nível de eficiência e desempenho no processamento dos arquivos, atendendo aos requisitos do problema de forma otimizada e escalável.

O desenvolvimento dessas propostas permitiu explorar diversas técnicas de otimização, desde a abordagem sequencial simples até o uso de algoritmos avançados de busca e ordenação. Cada proposta foi projetada para melhorar o desempenho e a eficiência do processamento dos arquivos, fornecendo uma base sólida para a aplicação de técnicas de análise assintótica e complexidade computacional.


## 📝 Implementação



## Análise de Complexidade de Cada Proposta

### Análise de Complexidade da Proposta 1:

1. **Limpar Arquivo de Saída:**
    ```cpp
    limparArquivo("./datasets/output.txt");
    ```
    - Supondo que a função `limparArquivo` apenas abra o arquivo e o trunque, isso é uma operação constante, ou seja, *O(1)*.

2. **Loop Principal sobre Conjuntos de Processos:**
    ```cpp
    for (int i = 0; i < qntConjuntosProcessos; i++) {
    ```
    - Este loop itera *Q* vezes.

3. **Abrir Arquivo de Processo:**
    ```cpp
    std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
    std::ifstream processo(nomeProcesso);
    ```
    - Abrir um arquivo e verificar se ele está aberto são operações *O(1)*, mas são feitas *qntConjuntosProcessos* vezes.

4. **Loop sobre Linhas do Arquivo de Processo:**
    ```cpp
    while (std::getline(processo, linha)) {
    ```
    - Suponha que cada arquivo de processo tem em média *L* linhas.

5. **Extrair Arquivos por Linha:**
    ```cpp
    extrairArquivosPorLinha(linha, arquivosPorLinha);
    ```
    - Se cada linha do arquivo de processo contém em média *A* IDs de arquivos, essa operação é *O(A)*.

6. **Loop sobre IDs de Arquivos:**
    ```cpp
    for (int j = 0; j < arquivosPorLinha.size(); j++) {
        double somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(arquivosPorLinha[j]) + ".txt");
        resultadoPorLinhaDeCadaProcesso += somaPorCadaArquivo;
    }
    ```
    - Cada chamada à função `calculandoASomaDasRaizQuadradaDeUmArquivo` envolve a leitura de um arquivo e o cálculo da soma das raízes quadradas de seus elementos. Se cada arquivo tiver em média *N* elementos, a complexidade dessa função é *O(N)*.
    - Portanto, o loop sobre os IDs de arquivos tem complexidade *O(A * N)* por linha.

7. **Escrever o Resultado no Arquivo de Saída:**
    ```cpp
    escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    ```
    - Escrever um resultado no arquivo de saída é uma operação *O(1)*, mas é feita *qntConjuntosProcessos* vezes.

#### Cálculo da Complexidade Total:

Sabendo que:
- **Q**: Número de conjuntos de processos.
- **L**: Número médio de linhas por arquivo de processo.
- **A**: Número médio de IDs de arquivos por linha.
- **N**: Número médio de elementos por arquivo referenciado.

Para cada conjunto de processos:
- Abrir o arquivo de processo: *O(1)*
- Iterar sobre *L* linhas: *O(L)*
    - Extrair IDs de arquivos por linha: *O(A)*
    - Iterar sobre *A* IDs de arquivos: *O(A * N)*

Portanto, a complexidade para processar um conjunto de processos é:
**O(L * (A + A * N)) = O(L * A * (1 + N)) ≈ O(L * A * N)**.

Como isso é feito para *Q* conjuntos de processos, assim, a complexidade computacional de tempo da Proposta 1 é:
**O(Q * L * A * N)**.


### Análise de Complexidade da Proposta 2:

1. **Limpar Arquivo de Saída:**
    ```cpp
    limparArquivo("./datasets/output.txt");
    ```
    - Complexidade: *O(1)*.

2. **Loop Externo:**
    ```cpp
    for (int i = 0; i < qntConjuntosProcessos; i++) {
    ```
    - Complexidade: *O(N)*, onde *N* é o número de conjuntos de processos.

3. **Abrir Arquivo de Processo:**
    ```cpp
    std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
    std::ifstream processo(nomeProcesso);
    ```
    - Complexidade: *O(1)*.

4. **Leitura e Processamento de Cada Linha do Arquivo de Processo:**
    ```cpp
    while (std::getline(processo, linha)) {
    ```
    - Complexidade: *O(L)*, onde *L* é o número de linhas no arquivo de processo.

5. **Extração de Arquivos por Linha:**
    ```cpp
    extrairArquivosPorLinha(linha, arquivosPorLinha);
    ```
    - Complexidade: *O(M)*, onde *M* é o número de caracteres na linha.

6. **Inicialização de Cache:**
    ```cpp
    std::vector<std::vector<double>> cacheArquivos;
    ```
    - Inicialização de um vetor, complexidade: *O(1)*.

7. **Loop Interno Sobre Arquivos Por Linha:**
    ```cpp
    for (int j = 0; j < arquivosPorLinha.size(); j++) {
    ```
    - Complexidade: *O(A)*, onde *A* é o número de arquivos referenciados em cada linha.

8. **Busca no Cache:**
    ```cpp
    for (std::vector<double> cache : cacheArquivos) {
        if (cache[0] == idArquivo) {
            somaPorCadaArquivo = cache[1];
            achou = true;
            break;
        }
    }
    ```
    - No pior caso, a busca no cache é linear em relação ao número de elementos no cache. Se denotamos o número de elementos no cache como *C*, a complexidade é *O(C)*.

9. **Cálculo da Soma das Raízes Quadradas (quando não está no cache):**
    ```cpp
    if (!achou) {
        somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(idArquivo) + ".txt");
        cacheArquivos.push_back({static_cast<double>(idArquivo), somaPorCadaArquivo});
    }
    ```
    - Se não estiver no cache, a complexidade é *O(K)*, onde *K* é o número de números no arquivo.
    - Adicionar um novo elemento ao cache tem complexidade *O(1)*.

10. **Escrita no Arquivo de Saída:**
    ```cpp
    escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    ```
    - Complexidade: *O(1)*.

#### Complexidade Total:

Vamos agora compilar as complexidades individuais para determinar a complexidade total da Proposta 2.

- O loop externo itera *N* vezes.
- Para cada iteração do loop externo, temos um loop que processa *L* linhas.
- Para cada linha, extraímos arquivos, o que tem uma complexidade *O(M)*, e iteramos sobre cada arquivo *A*.
- Para cada arquivo, primeiro realizamos uma busca no cache que tem complexidade *O(C)*. Se não for encontrado no cache, calculamos a soma das raízes quadradas dos números, o que tem uma complexidade *O(K)*.

A complexidade total pode ser expressa como:
**O(N * L * (M + A * (C + K)))**

Assumindo que *M* e *K* são relativamente pequenos comparados a *N*, *L*, e *A*, a complexidade pode ser aproximada por:
**O(N * L * A * (C + K))**

### Análise de Complexidade da Proposta 3:

1. **Limpar Arquivo de Saída:**
    ```cpp
    limparArquivo("./datasets/output.txt");
    ```
    - Complexidade: *O(1)*.

2. **Inicialização do Cache:**
    ```cpp
    std::vector<std::vector<double>> cacheArquivos;
    ```
    - Complexidade: *O(1)*.

3. **Loop Externo:**
    ```cpp
    for (int i = 0; i < qntConjuntosProcessos; i++) {
    ```
    - Complexidade: *O(N)*, onde *N* é o número de conjuntos de processos.

4. **Abrir Arquivo de Processo:**
    ```cpp
    std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
    std::ifstream processo(nomeProcesso);
    ```
    - Complexidade: *O(1)*.

5. **Leitura e Processamento de Cada Linha do Arquivo de Processo:**
    ```cpp
    while (std::getline(processo, linha)) {
    ```
    - Complexidade: *O(L)*, onde *L* é o número de linhas no arquivo de processo.

6. **Extração de Arquivos por Linha:**
    ```cpp
    extrairArquivosPorLinha(linha, arquivosPorLinha);
    ```
    - Complexidade: *O(M)*, onde *M* é o número de caracteres na linha.

7. **Loop Interno Sobre Arquivos Por Linha:**
    ```cpp
    for (int j = 0; j < arquivosPorLinha.size(); j++) {
    ```
    - Complexidade: *O(A)*, onde *A* é o número de arquivos referenciados em cada linha.

8. **Busca no Cache:**
    ```cpp
    for (std::vector<double> cache : cacheArquivos) {
        if (cache[0] == idArquivo) {
            somaPorCadaArquivo = cache[1];
            achou = true;
            break;
        }
    }
    ```
    - No pior caso, a busca no cache é linear em relação ao número de elementos no cache. Se denotamos o número de elementos no cache como *C*, a complexidade é *O(C)*.

9. **Cálculo da Soma das Raízes Quadradas (quando não está no cache):**
    ```cpp
    if (!achou) {
        somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(idArquivo) + ".txt");
        cacheArquivos.push_back({static_cast<double>(idArquivo), somaPorCadaArquivo});
    }
    ```
    - Se não estiver no cache, a complexidade é *O(K)*, onde *K* é o número de números no arquivo.
    - Adicionar um novo elemento ao cache tem complexidade *O(1)*.

10. **Escrita no Arquivo de Saída:**
    ```cpp
    escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    ```
    - Complexidade: *O(1)*.

#### Complexidade Total:

Vamos agora compilar as complexidades individuais para determinar a complexidade total da Proposta 3.

- O loop externo itera *N* vezes.
- Para cada iteração do loop externo, temos um loop que processa *L* linhas.
- Para cada linha, extraímos arquivos, o que tem uma complexidade *O(M)*, e iteramos sobre cada arquivo *A*.
- Para cada arquivo, primeiro realizamos uma busca no cache que tem complexidade *O(C)*. Se não for encontrado no cache, calculamos a soma das raízes quadradas dos números, o que tem uma complexidade *O(K)*.

A complexidade total pode ser expressa como:
**O(N * L * (M + A * (C + K)))**

Assumindo que *M* e *K* são relativamente pequenos comparados a *N*, *L*, e *A*, a complexidade pode ser aproximada por:
**O(N * L * A * (C + K))**


### Análise de Complexidade da Proposta 4:

1. **Limpar Arquivo de Saída:**
    ```cpp
    limparArquivo("./datasets/output.txt");
    ```
    - Complexidade: *O(1)*.

2. **Inicialização do Cache:**
    ```cpp
    std::vector<std::vector<double>> cacheArquivos;
    ```
    - Complexidade: *O(1)*.

3. **Loop Externo:**
    ```cpp
    for (int i = 0; i < qntConjuntosProcessos; i++) {
    ```
    - Complexidade: *O(N)*, onde *N* é o número de conjuntos de processos.

4. **Abrir Arquivo de Processo:**
    ```cpp
    std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
    std::ifstream processo(nomeProcesso);
    ```
    - Complexidade: *O(1)*.

5. **Leitura e Processamento de Cada Linha do Arquivo de Processo:**
    ```cpp
    while (std::getline(processo, linha)) {
    ```
    - Complexidade: *O(L)*, onde *L* é o número de linhas no arquivo de processo.

6. **Extração de Arquivos por Linha e Armazenamento:**
    ```cpp
    extrairArquivosPorLinha(linha, arquivosPorLinha);
    linhas.push_back(arquivosPorLinha);
    ```
    - Complexidade: *O(M)*, onde *M* é o número de caracteres na linha.

7. **Ordenação das Linhas:**
    ```cpp
    quickSort(linhas, 0, linhas.size() - 1);
    ```
    - A complexidade média do QuickSort é *O(L 
log L)*.

8. **Loop Interno Sobre Linhas e Arquivos Por Linha:**
    ```cpp
    for (int i = 0; i < linhas.size(); i++) {
    ```
    - Complexidade: *O(L)*.

    ```cpp
    for (int j = 0; j < linhas[i].size(); j++) {
    ```
    - Complexidade: *O(A)*.

9. **Busca no Cache:**
    ```cpp
    for (std::vector<double> cache : cacheArquivos) {
        if (cache[0] == idArquivo) {
            somaPorCadaArquivo = cache[1];
            achou = true;
            break;
        }
    }
    ```
    - No pior caso, a busca no cache é linear em relação ao número de elementos no cache. Se denotamos o número de elementos no cache como *C*, a complexidade é *O(C)*.

10. **Cálculo da Soma das Raízes Quadradas (quando não está no cache):**
    ```cpp
    if (!achou) {
        somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(idArquivo) + ".txt");
        cacheArquivos.push_back({static_cast<double>(idArquivo), somaPorCadaArquivo});
    }
    ```
    - Se não estiver no cache, a complexidade é *O(K)*, onde *K* é o número de números no arquivo.
    - Adicionar um novo elemento ao cache tem complexidade *O(1)*.

11. **Escrita no Arquivo de Saída:**
    ```cpp
    escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    ```
    - Complexidade: *O(1)*.

#### Complexidade Total:

Vamos agora compilar as complexidades individuais para determinar a complexidade total da Proposta 4.

- O loop externo itera *N* vezes.
- Para cada iteração do loop externo, temos um loop que processa *L* linhas.
- Extração de arquivos por linha tem uma complexidade *O(M)*, e armazenar essas linhas tem uma complexidade *O(1)*.
- Ordenação das linhas usando QuickSort tem complexidade *O(L log L)*.
- Para cada linha, iteramos sobre cada arquivo, o que tem uma complexidade *O(A)*.
- Para cada arquivo, realizamos uma busca no cache que tem complexidade *O(C)*. Se não for encontrado no cache, calculamos a soma das raízes quadradas dos números, o que tem uma complexidade *O(K)*.

A complexidade total pode ser expressa como:
**O(N * (L log L + L * (M + A * (C + K))))**

Assumindo que *M* e *K* são relativamente pequenos comparados a *N*, *L*, e *A*, a complexidade pode ser aproximada por:
**O(N * (L log L + L * A * (C + K)))**


### Análise de Complexidade da Proposta 5:

1. **Limpar Arquivo de Saída:**
    ```cpp
    limparArquivo("./datasets/output.txt");
    ```
    - Complexidade: *O(1)*.

2. **Loop Externo:**
    ```cpp
    for (int i = 0; i < qntConjuntosProcessos; i++) {
    ```
    - Complexidade: *O(N)*, onde *N* é o número de conjuntos de processos.

3. **Abrir Arquivo de Processo:**
    ```cpp
    std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
    std::ifstream processo(nomeProcesso);
    ```
    - Complexidade: *O(1)*.

4. **Leitura e Processamento de Cada Linha do Arquivo de Processo:**
    ```cpp
    while (std::getline(processo, linha)) {
    ```
    - Complexidade: *O(L)*, onde *L* é o número de linhas no arquivo de processo.

5. **Extração de Arquivos por Linha:**
    ```cppN * L * A * K
    - Complexidade: *O(M)*, onde *M* é o número de caracteres na linha.

6. **Loop Interno Sobre Arquivos Por Linha:**
    ```cpp
    for (int j = 0; j < arquivosPorLinha.size(); j++) {
    ```
    - Complexidade: *O(A)*, onde *A* é o número de arquivos por linha.

7   . **Busca no Cache:**
    ```cpp
    double somaPorCadaArquivo = buscarNoCache(idArquivo, cacheArquivos);               
    ```
    - Complexidade: *O(logQ)* por ser uma busca binária em um cache de *Q* elementos.

8. **Cálculo da Soma das Raízes Quadradas (quando não está no cache):**
    ```cpp
    if (somaPorCadaArquivo == -1) { 
        somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(idArquivo) + ".txt");
        colocarCacheOrdenado(cacheArquivos, idArquivo, somaPorCadaArquivo);
    }
    ```
    - Complexidade de calcular a soma: *O(K)*, onde *K* é o número de números no arquivo.
    - Complexidade de adicionar um novo elemento ao cache:*O(Q)* (no pior caso, por inserção ordenada).

9. **Escrita no Arquivo de Saída:**
    ```cpp
    escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    ```
    - Complexidade: *O(1)*.

#### Complexidade Total:

Vamos agora compilar as complexidades individuais para determinar a complexidade total da Proposta 5.

- O loop externo itera *N* vezes.
- Para cada iteração do loop externo, temos um loop que processa *L* linhas.
- Extração de arquivos por linha tem uma complexidade *O(M)*.
- Para cada linha, iteramos sobre cada arquivo, o que tem uma complexidade *O(A)*.
- A busca no cache é *O(logQ)*,  Se o valor não estiver no cache, o cálculo tem complexidade *O(K)* e a inserção ordenada no cache tem complexidade *O(Q)*.

A complexidade total pode ser expressa como:
**O(Q + N * L * (M + A * (logQ + K + Q)))**

Assumindo que *M* e *K* são relativamente pequenos comparados a *N*, *L*, e *A*, a complexidade pode ser aproximada por:

Entre *logQ*, *K*, e *Q*, geralmente *Q* (número de arquivos) será maior, considerando que *logQ* cresce mais lentamente e *K* depende do tamanho dos arquivos, a complexidade pode ser aproximada por:
**O(Q + N * L * A * Q)**

### Análise de Complexidade da Proposta 6:

1. **Limpar Arquivo de Saída:**
    ```cpp
    limparArquivo("./datasets/output.txt");
    ```
    - Complexidade: *O(1)*.

2. **Inicialização do Cache:**
    ```cpp
    for (int i = 0; i < qntArquivos; i++) {
        cacheArquivos.push_back({static_cast<double>(i + 1), calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(i + 1) + ".txt")});
    }
    ```
    - Complexidade: *O(Q * K)*, onde *Q* é o número de arquivos e *K* é o número de números no arquivo.
    - Inicializa o cache com os resultados de todas as somas das raízes quadradas dos arquivos.

3. **Loop Externo:**
    ```cpp
    for (int i = 0; i < qntConjuntosProcessos; i++) {
    ```
    - Complexidade: *O(N)*, onde *N* é o número de conjuntos de processos.

4. **Abrir Arquivo de Processo:**
    ```cpp
    std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
    std::ifstream processo(nomeProcesso);
    ```
    - Complexidade: *O(1)*.

5. **Leitura e Processamento de Cada Linha do Arquivo de Processo:**
    ```cpp
    while (std::getline(processo, linha)) {
    ```
    - Complexidade: *O(L)*, onde *L* é o número de linhas no arquivo de processo.

6. **Extração de Arquivos por Linha:**
    ```cpp
    extrairArquivosPorLinha(linha, arquivosPorLinha);
    ```
    - Complexidade: *O(M)*, onde *M* é o número de caracteres na linha.

7. **Loop Interno Sobre Arquivos Por Linha:**
    ```cpp
    for (int j = 0; j < arquivosPorLinha.size(); j++) {
    ```
    - Complexidade: *O(A)*, onde *A* é o número de arquivos por linha.

8. **Acesso ao Cache para Obter Soma das Raízes Quadradas:**
    ```cpp
    int idArquivo = arquivosPorLinha[j];
    double somaPorCadaArquivo = cacheArquivos[idArquivo - 1][1];
    ```
    - Complexidade: *O(1)*.
    - Acesso direto ao cache com complexidade constante.

9. **Cálculo do Resultado de Cada Processo:**
    ```cpp
    resultadoPorLinhaDeCadaProcesso += somaPorCadaArquivo;
    ```
    - Complexidade: *O(1)*.

10. **Escrita no Arquivo de Saída:**
    ```cpp
    escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    ```
    - Complexidade: *O(1)*.

#### Complexidade Total:

Vamos agora compilar as complexidades individuais para determinar a complexidade total da Proposta 6.

- O loop externo itera *N* vezes.
- Para cada iteração do loop externo, temos um loop que processa *L* linhas.
- Extração de arquivos por linha tem uma complexidade *O(M)*.
- Para cada linha, iteramos sobre cada arquivo, o que tem uma complexidade *O(A)*.
- O acesso ao cache e o cálculo do resultado são operações de complexidade *O(1)*.

A complexidade total pode ser expressa como:
**O(Q * K + N * L * (M + A))**

Assumindo que *M* e *K* são relativamente pequenos comparados a *N*, *L*, e *A*, a complexidade pode ser aproximada por:
**O(Q * K + N * L * A)**


### Comparação entre as Propostas:

#### Proposta 1:
- Complexidade: *O(Q * L * M * N)*.
- Desempenho: Recalcula a soma das raízes quadradas para cada arquivo sempre que referenciado.

#### Proposta 2:
- Complexidade: *O(N * L * A * (C + K))*.
- Desempenho: Utiliza cache local ao arquivo de cada processo, recalculando apenas se o arquivo não estiver no cache. Isso adiciona um fator *O(C)* para a busca no cache, mas elimina múltiplas leituras e cálculos para o mesmo arquivo, que diminui o valor de *O(K)*.

#### Proposta 3:
- Complexidade: *O(N * L * A * (C + K))*.
- Desempenho: Utiliza um cache global que persiste entre os arquivos de processo, evitando recalcular a soma das raízes quadradas de arquivos já processados anteriormente em outros processos.

#### Proposta 4:
- Complexidade: *O(N * (L log L + L * A * (C + K)))*.
- Desempenho: Ordena as linhas antes de processá-las, colocando a linha que tem mais processo primeiro, usando QuickSort, o que pode melhorar a localidade de referência e eficiência do cache, mas adiciona o custo de ordenação *O(L log L)*.

#### Proposta 5:
- Complexidade: *O(Q + N * L * A * Q)*.
- Desempenho: Utiliza um cache global e a busca binária que acelera a recuperação do cache, inserção ordenada mantém o cache eficiente.

#### Proposta 6:
- Complexidade: *O(Q * K + N * L * A)*
- Desempenho: Pré-calcula e armazena todas as somas antes de processar, excelente se a memória não é um problema.

## 📂 Estrutura de Diretórios

O projeto é organizado da seguinte forma:
```.
|
├── build
│   │   └── objects
│   │       ├── src
│   │       |   ├── problema11.o
│   │       |   └── main.o
│   │       └── app
├── datasets
│   │   ├── arquivos
│   │   |   ├── 1.txt
│   │   |   └── 2.txt
│   │   └── arquivos
│   │       ├── 1.txt
│   │       └── 2.txt
├── src
│   │   ├── main.cpp
│   │   ├── problema11.cpp
│   │   └── problema11.hpp
├── makefile
└── README.md
```
Esta estrutura de diretórios facilita a organização do projeto e a localização dos arquivos necessários para compilar o código-fonte, executar o programa e visualizar os resultados.

## 📚 Como Usar

1. Clone este repositório:

    ```bash
    git clone https://github.com/dudatsouza/pratica1Problema11.git

2. Antes de compilar o programa, é recomendado executar o comando `make clean` para garantir que todos os arquivos compilados anteriores sejam removidos:

    ```bash
    make clean
    ```

3. Em seguida, compile o programa usando o Makefile:

    ```bash
    make
    ```

4. Execute o programa, fornecendo os dados que ele pede:

    ```bash
    make run 
    ```

5. Siga as instruções do programa, gerando os arquivos e os processos que estarão localizados em suas respectivas pastas, `./datasets/arquivos/` e `./datasets/processos/`, e a soma das raízes quadradas em `./datasets/output.txt`.

6. Depois você irá ser redirecionado para uma janela do navegador com o gráfico dos tempos de execução, onde poderá visualizar o desempenho de cada proposta da maneira que desejar, tendo uma noção melhor da eficiência de cada uma. 

## 📋 Exemplos


### 📄 Arquivos de entradas:
Os arquivos de entradas vc pode está pegando de exemplos os que estão disponíveis na pasta `/datasets`. Lá você vai encontrar os arquivos: 
- `resultados.csv`
- `resultadosMedias.csv`
- `resultadosMinMax.csv`
- `resultadosMinMaxMedias.csv`


### 📄 Exemplo de Saída de um dos Gráficos:
1. **Primeiro tipo de plotagem:** 
A partir do script `plotGaficoMedias.gp` são plotados 12 gráficos, cada um pegando a diferença entre o tempo de execução dos três MaxMin. Aqui está um exemplo de um dos gráficos gerados a partir dos dados do arquivo `resultadosMedias.csv`: 
<p align="center">
    <figure align="center">
    <img src="./images/imgs_readme/graficoExemploMedias.png" alt="Gráfico Exemplo" width="500" >
    <figcaption>Fonte: Autor</figcaption>
    </figure>
</p>

**OBSERVAÇÃO:** Foram plotados um total de 12 gráficos, representando diferentes tamanhos de vetores e organizações, mostrando a variação do tempo de execução de acordo com o MinMax usado.

2. **Segundo tipo de plotagem:** 
A partir do script `plotGaficoMinMax.gp` são plotados 9 gráficos, cada um pegando a diferença entre o tempo de execução de acordo com o tamanho do vetor. Aqui está um exemplo de um dos gráficos gerados a partir dos dados do arquivo `resultadosMiinMaxMedias.csv`: 
<p align="center">
    <figure align="center">
    <img src="./images/imgs_readme/graficoExemploMinMax.png" alt="Gráfico Exemplo" width="500" >
    <figcaption>Fonte: Autor</figcaption>
    </figure>
</p>

**OBSERVAÇÃO:** Foram plotados um total de 9 gráficos, representando diferentes organizações e MinMaxs usados, mostrando a variação do tempo de execução de acordo com o tamanho do vetor.

## 📈 Resultados das Análises


## Escolha da melhor proposta 
Cada uma das propostas apresentadas oferece vantagens e desvantagens, e a escolha da melhor depende de vários fatores, como o tipo de arquivos, a estrutura dos dados e os padrões de acesso. Aqui estão algumas considerações finais sobre o desempenho de cada proposta:

**PROPOSTA 1: Processamento Sequencial**

- **Descrição:** Cada linha de um arquivo de processo é lida e processada de forma sequencial, calculando a soma das raízes quadradas dos números nos arquivos referenciados.
- **Limitação:** Alta redundância, pois cada arquivo referenciado é processado repetidamente sem aproveitamento de cálculos anteriores, resultando em uma significativa ineficiência.

**PROPOSTA 2: Reaproveitamento de Cálculos por Processo**

- **Descrição:** Introduz um cache para armazenar a soma das raízes quadradas de arquivos já processados dentro de um mesmo processo.
- **Melhoria:** Reduz a redundância dentro de um único processo, evitando recalcular somas de arquivos já processados.
- **Limitação:** O cache é descartado ao final de cada processo, não aproveitando os cálculos entre processos diferentes.

**Proposta 3: Cache Global**
- **Descrição:** Implementa um cache global que armazena os resultados das somas das raízes quadradas entre todos os processos.
- **Melhoria:** Aproveita os cálculos realizados entre diferentes processos, aumentando a eficiência global.
- **Limitação:** Embora o reaproveitamento de cálculos seja maximizado, a busca no cache pode ser ineficiente se não for otimizada.

**PROPOSTA 4: Ordenação e Reaproveitamento**
- **Descrição:** Ordena as linhas de cada processo com base no número de arquivos referenciados antes de iniciar o processamento.
- **Melhoria:** Processa primeiro as linhas com mais arquivos referenciados, otimizando o reaproveitamento dos cálculos iniciais e melhorando a eficiência de cache.
- **Limitação:** A complexidade adicional da ordenação pode introduzir overhead, e a eficiência depende da distribuição dos dados.

**PROPODTA 5: Cache com Busca Binária**
- **Descrição:** Utiliza um vetor de cache ordenado para armazenar resultados e implementa busca binária para recuperação eficiente dos valores já calculados.
- **Melhoria:** A busca binária permite uma recuperação muito mais rápida dos valores no cache, otimizando significativamente o tempo de execução.
- **Limitação:** A manutenção do vetor ordenado e a inserção de novos valores podem introduzir alguma complexidade adicional.

**Proposta 6: Preprocessamento Completo com Cache**
- **Descrição:** Pré-calcula a soma das raízes quadradas de todos os arquivos antes de processar os arquivos de processo, armazenando os resultados em um vetor de cache.
- **Melhoria:** Elimina completamente a necessidade de calcular somas durante o processamento dos arquivos de processo, pois todos os resultados estão pré-computados e disponíveis de forma imediata.
- **Limitação:** Requer um grande uso de memória para armazenar todos os resultados e um tempo inicial de processamento considerável para calcular todas as somas, mas este tempo é compensado pela eficiência do processamento subsequente.


### Justificativa para Parar de Procurar Outras Maneiras
Após a implementação da Proposta 6, a análise dos tempos de execução e da eficiência revelou que:

1. **Eficiência Máxima Alcançada:** O tempo de execução para processar cada linha dos arquivos de processo foi drasticamente reduzido devido ao pré-cálculo e armazenamento eficiente das somas das raízes quadradas. A busca no vetor de cache pré-calculado é extremamente rápida, praticamente eliminando o tempo de processamento repetitivo.

2. **Custo-Benefício:** Qualquer tentativa adicional de otimização apresentaria melhorias marginais a um custo operacional e de complexidade significativamente maior. A implementação de algoritmos mais sofisticados ou o uso de técnicas de paralelismo ou distribuição poderia resultar em ganhos menores em relação ao custo de implementação e manutenção.

3. **Limitação Prática:** O uso de um vetor de cache que armazena todas as somas das raízes quadradas pré-calculadas já é uma abordagem que maximiza o uso da memória disponível e do tempo de processamento inicial. As melhorias possíveis além desta abordagem seriam incrementais e não justificariam o esforço adicional necessário.

4. **Simplicidade e Mantenabilidade:** A Proposta 6, apesar de exigir um tempo de pré-processamento significativo, simplifica consideravelmente o código subsequente, tornando-o mais fácil de manter e menos propenso a erros. O design claro e eficiente facilita futuras modificações ou expansões do sistema.

Portanto, a escolha da Proposta 6 como a solução final foi baseada em uma análise detalhada de eficiência, complexidade, custo-benefício e simplicidade de manutenção. Esta proposta atende plenamente aos requisitos do problema, fornecendo um equilíbrio ideal entre desempenho e praticidade quando a maioria dos arquivos são acessados, mas pode desperdiçar cálculos quando muitos arquivos não são usados. Mas também sabemos que para muitos casos práticos, Proposta 3 ou Proposta 5 são geralmente as melhores opções devido ao uso eficiente do cache. 

## 🎉 Conclusão 

## 🔨 Ambiente de Compilação

A seguir estão os detalhes do ambiente de compilação onde o programa foi executado:

| Componente      | Detalhes                          |
|-----------------|-----------------------------------|
| Sistema Operacional | Ununtu 22.04.4 LTS  - 64 bits|
| Modelo do hardware| Dell Inc. Inspiron 3501|
| Processador     | Intel® Core™ i3-1005G1 CPU @ 1.20GHz × 4|
| Memória RAM     | 8 GB, 1 de 8 GB, DDR4, 2.666 MHz|
| Armazenamento   | 256 GB, M.2 2230, PCIe NVMe de 3ª geração x4, SSD|
| IDE             | Visual Studio Code|

Observação: Os detalhes acima são baseados no ambiente de compilação utilizado durante o desenvolvimento do programa e podem variar em diferentes sistemas.


## ⛏ Makefile

O Makefile é um utilitário que automatiza o processo de compilação e execução de programas. Aqui estão os principais comandos do Makefile para este projeto:

| Comando      | - **Descrição **                              |
|--------------|-----------------------------------------|
| `make`       | Compila o programa.                     |
| `make run`   | Executa o programa com o arquivo de entrada fornecido. |
| `make clean` | Remove os arquivos compilados.          |


## 📧 Contato

Para mais informações ou sugestões, sinta-se à vontade para entrar em contato:

- ✉️ **E-mail**: [![Gmail Badge](https://img.shields.io/badge/-dudateixeirasouza@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:dudateixeirasouza@gmail.com)](mailto:dudateixeirasouza@gmail.com)
- 💼 **LinkedIn**: [![Linkedin Badge](https://img.shields.io/badge/-LinkedIn-0e76a8?style=flat-square&logo=Linkedin&logoColor=white)](https://www.linkedin.com/in/maria-eduarda-teixeira-souza-2a2b3a254/)
- 📸 **Instagram**: [![Instagram Badge](https://img.shields.io/badge/-Instagram-e4405f?style=flat-square&logo=Instagram&logoColor=white)](https://www.instagram.com/dudat_18/)

Ficarei feliz em receber feedbacks, contribuições ou responder a quaisquer dúvidas que você possa ter sobre o programa. 

## 🔖 Referências
1. João Arthur. **Análise Assintótica**. Disponível em: [https://joaoarthurbm.github.io/eda/posts/analise-assintotica/](https://joaoarthurbm.github.io/eda/posts/analise-assintotica/). Acesso em: 12 abr. 2024.

2. Pereira, F. **Análise de Algoritmos**. Disponível em: [https://www.ime.usp.br/~pf/analise_de_algoritmos/](https://www.ime.usp.br/~pf/analise_de_algoritmos/). Acesso em: 12 abr. 2024.

3. XVI ENID. **PROLICEN: Engenharia de Software: análise de complexidade assintótica de algoritmos**. Disponível em: [http://www.prac.ufpb.br/enex/XVENID/PROLICEN/CCAE/25.pdf](http://www.prac.ufpb.br/enex/XVENID/PROLICEN/CCAE/25.pdf). Acesso em: 12 abr. 2024.

4. Hokama. **CIC110 - Estrutura de Dados - Análise Assintótica**. Disponível em: [https://hokama.com.br/disciplinas/cic110_2019s2/02-analise-assintotica.pdf](https://hokama.com.br/disciplinas/cic110_2019s2/02-analise-assintotica.pdf). Acesso em: 12 abr. 2024.

5. Martins, A. **Análise de Complexidade de Algoritmos**. Disponível em: [http://www.deinf.ufma.br/~acmo/grad/ED_complexidade_2005.pdf](http://www.deinf.ufma.br/~acmo/grad/ED_complexidade_2005.pdf). Acesso em: 12 abr. 2024.

6. Reinaldo. **Análise de Algoritmos (Parte 3)**. Disponível em: [http://www.decom.ufop.br/reinaldo/site_media/uploads/2014-01-bcc202/aulas/aula_06_-_analise_de_algoritmos_(parte_3)_(v1).pdf](http://www.decom.ufop.br/reinaldo/site_media/uploads/2014-01-bcc202/aulas/aula_06_-_analise_de_algoritmos_(parte_3)_(v1).pdf). Acesso em: 12 abr. 2024.

7. CEFET-MG. **Aula 1 - Análise de Algoritmos**. Disponível em: [https://ava.cefetmg.br/pluginfile.php/250215/mod_resource/content/8/Aula1.pdf](https://ava.cefetmg.br/pluginfile.php/250215/mod_resource/content/8/Aula1.pdf). Acesso em: 12 abr. 2024.




