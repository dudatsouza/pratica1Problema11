#include "problema11.hpp"

void gerarProcessosEArquivos(int& qntProcesso, int& qntArquivos) {
    std::cout << "--------------------------------------------\nGERAÇÃO DE ARQUIVOS" << std::endl;
    std::cout << "\nDigite a quantidade de arquivos que deseja gerar: ";
    std::cin >> qntArquivos;
    for (int i = 0; i < qntArquivos; i++) {
        std::string nomeArquivo = "./datasets/arquivos/" + std::to_string(i + 1) + ".txt";
        gerarArquivos(nomeArquivo);
    } 
    std::cout << "\n(Cada arquivo contém 100.000 números inteiros aleatórios de 1 a 1.000.000)" << std::endl;
    std::cout << "Arquivos gerados com sucesso!\n" << std::endl;

    std::cout << "--------------------------------------------\nGERAÇÃO DE PROCESSOS" << std::endl;
    std::cout << "\nDigite a quantidade de processos que deseja gerar: ";
    std::cin >> qntProcesso;
    std::cout << "Digite a quantidade de linhas que deseja gerar para cada processo: ";
    int qntLinhas;
    std::cin >> qntLinhas;
    std::cout << "Digite a quantidade de arquivos que deseja gerar para cada linha: ";
    int qntDeArquivosPorLinha;
    std::cin >> qntDeArquivosPorLinha;
    for (int i = 0; i < qntProcesso; i++) {
        std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt";
        gerarProcessos(nomeProcesso, qntArquivos, qntLinhas, qntDeArquivosPorLinha);
    } 
    std::cout << "\nProcessos gerados com sucesso!" << std::endl;
}

void gerarArquivos(std::string nomeArquivo) {
   std::ofstream arquivo(nomeArquivo, std::ios::out | std::ios::binary);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para escrita!" << std::endl;
        return;
    }

    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 1000000.0);

    for (int i = 0; i < 100000; ++i) {
        float num = static_cast<float>(dis(gen));
        arquivo.write(reinterpret_cast<const char*>(&num), sizeof(num));
    }
    arquivo.close();
}

void gerarProcessos(std::string nomeProcesso, int qntArquivos, int qntLinhas, int qntDeArquivosPorLinha) {
    std::ofstream processo(nomeProcesso);
    if (!processo.is_open()) {
        std::cerr << "Erro ao abrir o processo " << nomeProcesso << std::endl;
        return;
    }
    int qntLinhas1 = (rand() % qntLinhas) + 1;
    for (int i = 0; i < qntLinhas1; i++) {
        processo << "< L" << i + 1;
        int qntDeArquivosPorLinha1 = (rand() % qntDeArquivosPorLinha) + 1;
        for (int j = 0; j < qntDeArquivosPorLinha1; j++) {
            int idArquivo = (rand() % qntArquivos) + 1;
            processo << ", " << idArquivo;
        }
        processo << " >" << std::endl;
    }
    processo.close();
}

void proposta1(int qntConjuntosProcessos) {
    limparArquivo("./datasets/output.txt");

    for (int i = 0; i < qntConjuntosProcessos; i++) {
        std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
        std::ifstream processo(nomeProcesso);
        if (!processo.is_open()) {
            std::cerr << "Erro ao abrir o processo " << nomeProcesso << std::endl;
            return;
        }

        std::string linha;
        std::vector<int> arquivosPorLinha;
        double resultadoDeCadaProcesso = 0;
        while (std::getline(processo, linha)) {
            extrairArquivosPorLinha(linha, arquivosPorLinha);
            double resultadoPorLinhaDeCadaProcesso = 0;

            for (int j = 0; j < arquivosPorLinha.size(); j++) {
                double somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(arquivosPorLinha[j]) + ".txt");
                resultadoPorLinhaDeCadaProcesso += somaPorCadaArquivo;
            }
            resultadoDeCadaProcesso -= resultadoPorLinhaDeCadaProcesso;
        }
        escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    }
}

void proposta2(int qntConjuntosProcessos) {
    limparArquivo("./datasets/output.txt");

    for (int i = 0; i < qntConjuntosProcessos; i++) {
        std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
        std::ifstream processo(nomeProcesso);
        if (!processo.is_open()) {
            std::cerr << "Erro ao abrir o processo " << nomeProcesso << std::endl;
            return;
        }

        std::string linha;
        std::vector<int> arquivosPorLinha;
        std::vector<std::vector<double>> cacheArquivos;
        double resultadoDeCadaProcesso = 0;

        while (std::getline(processo, linha)) {
            extrairArquivosPorLinha(linha, arquivosPorLinha);
            double resultadoPorLinhaDeCadaProcesso = 0;

            for (int j = 0; j < arquivosPorLinha.size(); j++) {
                int idArquivo = arquivosPorLinha[j];
                double somaPorCadaArquivo = 0;
                bool achou = false;

                for (std::vector<double> cache : cacheArquivos) {
                    if (cache[0] == idArquivo) {
                        somaPorCadaArquivo = cache[1];
                        achou = true;
                        break;
                    }
                }

                if (!achou) {
                    somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(idArquivo) + ".txt");
                    cacheArquivos.push_back({static_cast<double>(idArquivo), somaPorCadaArquivo});
                }
                
                resultadoPorLinhaDeCadaProcesso += somaPorCadaArquivo;
            }
            resultadoDeCadaProcesso -= resultadoPorLinhaDeCadaProcesso;
        }
        escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    }
}

void proposta3(int qntConjuntosProcessos) {
    limparArquivo("./datasets/output.txt");
    std::vector<std::vector<double>> cacheArquivos;

    for (int i = 0; i < qntConjuntosProcessos; i++) {
        std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
        std::ifstream processo(nomeProcesso);
        if (!processo.is_open()) {
            std::cerr << "Erro ao abrir o processo " << nomeProcesso << std::endl;
            return;
        }

        std::string linha;
        std::vector<int> arquivosPorLinha;
        double resultadoDeCadaProcesso = 0;

        while (std::getline(processo, linha)) {
            extrairArquivosPorLinha(linha, arquivosPorLinha);
            double resultadoPorLinhaDeCadaProcesso = 0;

            for (int j = 0; j < arquivosPorLinha.size(); j++) {
                int idArquivo = arquivosPorLinha[j];
                double somaPorCadaArquivo = 0;
                bool achou = false;

                for (std::vector<double> cache : cacheArquivos) {
                    if (cache[0] == idArquivo) {
                        somaPorCadaArquivo = cache[1];
                        achou = true;
                        break;
                    }
                }

                if (!achou) {
                    somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(idArquivo) + ".txt");
                    cacheArquivos.push_back({static_cast<double>(idArquivo), somaPorCadaArquivo});
                }
                
                resultadoPorLinhaDeCadaProcesso += somaPorCadaArquivo;
            }
            resultadoDeCadaProcesso -= resultadoPorLinhaDeCadaProcesso;
        }
        escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    }
}

void proposta4(int qntConjuntosProcessos) {
     limparArquivo("./datasets/output.txt");
    std::vector<std::vector<double>> cacheArquivos;

    for (int i = 0; i < qntConjuntosProcessos; i++) {
        std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
        std::ifstream processo(nomeProcesso);
        if (!processo.is_open()) {
            std::cerr << "Erro ao abrir o processo " << nomeProcesso << std::endl;
            return;
        }

        std::string linha;
        std::vector<int> arquivosPorLinha;
        double resultadoDeCadaProcesso = 0;
        std::vector<std::vector<int>> linhas;

        while (std::getline(processo, linha)) {
            extrairArquivosPorLinha(linha, arquivosPorLinha);
            linhas.push_back(arquivosPorLinha);
        }

        quickSort(linhas, 0, linhas.size() - 1);

        for (int i = 0; i < linhas.size(); i++) {
            double resultadoPorLinhaDeCadaProcesso = 0;
            for (int j = 0; j < linhas[i].size(); j++) {
                int idArquivo = linhas[i][j];
                double somaPorCadaArquivo = 0;
                bool achou = false;

                for (std::vector<double> cache : cacheArquivos) {
                    if (cache[0] == idArquivo) {
                        somaPorCadaArquivo = cache[1];
                        achou = true;
                        break;
                    }
                }

                if (!achou) {
                    somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(idArquivo) + ".txt");
                    cacheArquivos.push_back({static_cast<double>(idArquivo), somaPorCadaArquivo});
                }
                
                resultadoPorLinhaDeCadaProcesso += somaPorCadaArquivo;
            }
            resultadoDeCadaProcesso -= resultadoPorLinhaDeCadaProcesso;
        }
        escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    }
   
}

void proposta5(int qntConjuntosProcessos, int qntArquivos) {
    limparArquivo("./datasets/output.txt");
    std::vector<std::vector<double>> cacheArquivos;

    for (int i = 0; i < qntConjuntosProcessos; i++) {
        std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
        std::ifstream processo(nomeProcesso);
        if (!processo.is_open()) {
            std::cerr << "Erro ao abrir o processo " << nomeProcesso << std::endl;
            return;
        }

        std::string linha;
        std::vector<int> arquivosPorLinha;
        double resultadoDeCadaProcesso = 0;

        while (std::getline(processo, linha)) {
            extrairArquivosPorLinha(linha, arquivosPorLinha);
            double resultadoPorLinhaDeCadaProcesso = 0;

            for (int j = 0; j < arquivosPorLinha.size(); j++) {
                int idArquivo = arquivosPorLinha[j];
                double somaPorCadaArquivo = buscarNoCache(idArquivo, cacheArquivos);               

                if (somaPorCadaArquivo == -1) { 
                    somaPorCadaArquivo = calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(idArquivo) + ".txt");
                    colocarCacheOrdenado(cacheArquivos, idArquivo, somaPorCadaArquivo);
                }
                
                resultadoPorLinhaDeCadaProcesso += somaPorCadaArquivo;
            }
            resultadoDeCadaProcesso -= resultadoPorLinhaDeCadaProcesso;
        }
        escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    }
}

void proposta6(int qntConjuntosProcessos, int qntArquivos) {
    limparArquivo("./datasets/output.txt");
    std::vector<std::vector<double>> cacheArquivos;

    for (int i = 0; i < qntArquivos; i++) {
            cacheArquivos.push_back({static_cast<double>(i + 1), calculandoASomaDasRaizQuadradaDeUmArquivo("./datasets/arquivos/" + std::to_string(i + 1) + ".txt")});
        }

    for (int i = 0; i < qntConjuntosProcessos; i++) {
        std::string nomeProcesso = "./datasets/processos/P" + std::to_string(i + 1) + ".txt"; 
        std::ifstream processo(nomeProcesso);
        if (!processo.is_open()) {
            std::cerr << "Erro ao abrir o processo " << nomeProcesso << std::endl;
            return;
        }

        std::string linha;
        std::vector<int> arquivosPorLinha;
        double resultadoDeCadaProcesso = 0;

        while (std::getline(processo, linha)) {
            extrairArquivosPorLinha(linha, arquivosPorLinha);
            double resultadoPorLinhaDeCadaProcesso = 0;

            for (int j = 0; j < arquivosPorLinha.size(); j++) {
                int idArquivo = arquivosPorLinha[j];
                double somaPorCadaArquivo = cacheArquivos[idArquivo - 1][1];
                resultadoPorLinhaDeCadaProcesso += somaPorCadaArquivo;
            }
            resultadoDeCadaProcesso -= resultadoPorLinhaDeCadaProcesso;
        }
        escreverResultadoNoArquivoDeSaida("./datasets/output.txt", resultadoDeCadaProcesso);
    }
}

void extrairArquivosPorLinha(std::string linha, std::vector<int>& arquivosPorLinha) {
    std::string aux = "";
    bool achouL = false;
    bool achouV = false;
    arquivosPorLinha.clear();
    for (int j = 0; j < linha.size(); j++) {
        if (achouL && !achouV && linha[j] == ',') {
            achouV = true;
        } else if (linha[j] == ',' || (linha[j] == '>' && aux != "")) {
            arquivosPorLinha.push_back(std::stoi(aux));
            aux = "";
        } else if (linha[j] == 'L') {
            achouL = true;
        } else if (linha[j] != '<' && linha[j] != '>' && linha[j] != ' ' && achouV) {
            aux += linha[j];
        }
    }
}

void medindoTempoDeExecucaoDeCadaProposta(int qntConjuntosProcessos, int qntArquivos, std::ofstream& csvFile) {
    auto inicio1 = std::chrono::high_resolution_clock::now();
    proposta1(qntConjuntosProcessos);
    auto fim1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempoProposta1 = fim1 - inicio1;
    std::cout << tempoProposta1.count() << " | ";
    csvFile << tempoProposta1.count() << ",";

    auto inicio2 = std::chrono::high_resolution_clock::now();
    proposta2(qntConjuntosProcessos);
    auto fim2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempoProposta2 = fim2 - inicio2;
    std::cout << tempoProposta2.count() << " | ";
    csvFile << tempoProposta2.count() << ",";

    auto inicio3 = std::chrono::high_resolution_clock::now();
    proposta3(qntConjuntosProcessos);
    auto fim3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempoProposta3 = fim3 - inicio3;
    std::cout << tempoProposta3.count() << " | ";
    csvFile << tempoProposta3.count() << ",";

    auto inicio4 = std::chrono::high_resolution_clock::now();
    proposta4(qntConjuntosProcessos);
    auto fim4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempoProposta4 = fim4 - inicio4;
    std::cout << tempoProposta4.count() << " | ";
    csvFile << tempoProposta4.count() << ",";

    auto inicio5 = std::chrono::high_resolution_clock::now();
    proposta5(qntConjuntosProcessos, qntArquivos);
    auto fim5 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempoProposta5 = fim5 - inicio5;
    std::cout << tempoProposta5.count() << " | ";
    csvFile << tempoProposta5.count() << ",";

    auto inicio6 = std::chrono::high_resolution_clock::now();
    proposta6(qntConjuntosProcessos, qntArquivos);
    auto fim6 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempoProposta6 = fim6 - inicio6;
    std::cout << tempoProposta6.count();
    csvFile << tempoProposta6.count() << "\n";
}

void limparArquivo(std::string nomeArquivo) {
    std::ofstream arquivo(nomeArquivo, std::ios_base::trunc);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return;
    }
    arquivo.close();
}

double calculandoASomaDasRaizQuadradaDeUmArquivo(std::string nomeArquivo) {
    std::ifstream arquivo(nomeArquivo, std::ios::in | std::ios::binary);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return 0;
    }

    double soma = 0.0;
    float num;
    while (arquivo.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        soma += std::sqrt(num);
    }

    arquivo.close();
   return soma;
}

void escreverResultadoNoArquivoDeSaida(std::string nomeArquivo, double resultado) {
    std::ofstream arquivo(nomeArquivo, std::ios_base::app);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return;
    }
    long long numeroInteiro = static_cast<long long>(resultado);
    arquivo << numeroInteiro << std::endl;
    arquivo.close();
}

void trocar(std::vector<std::vector<int>>& matriz, int i, int j) {
    std::vector<int> temp = matriz[i];
    matriz[i] = matriz[j];
    matriz[j] = temp;
}

int particao(std::vector<std::vector<int>>& matriz, int low, int high) {
    int pivo = matriz[high].size(); 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (matriz[j].size() >= pivo) { 
            i++;
            trocar(matriz, i, j);
        }
    }
    trocar(matriz, i + 1, high);
    return i + 1;
}

void quickSort(std::vector<std::vector<int>>& matriz, int low, int high) {
    if (low < high) {
        int pi = particao(matriz, low, high);

        quickSort(matriz, low, pi - 1);
        quickSort(matriz, pi + 1, high);
    }
}

double buscarNoCache(int idArquivo, std::vector<std::vector<double>>& cacheArquivos) {
    int inicio = 0;
    int fim = cacheArquivos.size() - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (cacheArquivos[meio][0] == idArquivo) {
            return cacheArquivos[meio][1];
        }

        if (cacheArquivos[meio][0] < idArquivo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

void colocarCacheOrdenado(std::vector<std::vector<double>>& cacheArquivos, int idArquivo, double somaPorCadaArquivo) {
    int i = 0;
    while (i < cacheArquivos.size() && cacheArquivos[i][0] < static_cast<double>(idArquivo)) {
        i++;
    }
    cacheArquivos.insert(cacheArquivos.begin() + i, {static_cast<double>(idArquivo), somaPorCadaArquivo});
}

void limparPastas() {
    std::filesystem::remove_all("./datasets/arquivos");
    std::filesystem::remove_all("./datasets/processos");
    std::filesystem::create_directory("./datasets/arquivos");
    std::filesystem::create_directory("./datasets/processos");
}
