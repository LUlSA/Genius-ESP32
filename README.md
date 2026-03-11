# Genius-ESP32

Este projeto é uma versão do clássico jogo "Genius" (ou Simon Says) que desenvolvi usando o microcontrolador ESP32. O foco foi aplicar na prática conceitos de lógica de programação e eletrônica que vemos na faculdade.

O jogo desafia a memória gerando sequências aleatórias de luzes e sons. A cada acerto, o desafio fica maior!

### 🛠️ Hardware utilizado
* **ESP32 DevKit V1**
* **2 LEDs** (Azul e Amarelo)
* **2 Botões** para a interação do jogador
* **1 Buzzer** para o feedback sonoro
* **Resistores** de 220 ohms (para os LEDs) e 10k ohms (para os botões)

### 💡 O que aprendi com o projeto
Durante a montagem e programação, apliquei conceitos fundamentais:

* **Debouncing:** Tratamento via código para evitar que um único aperto no botão seja lido como vários cliques.
* **Resistores de Pull-down:** Para garantir que os pinos de entrada não fiquem "flutuando" e leiam o sinal corretamente.
* **Frequências Sonoras:** Uso de tons diferentes para ajudar na memorização (cada cor tem seu som).
* **Randomização:** Usei o ruído de um pino analógico para que as sequências do jogo sejam sempre diferentes em cada partida.

### 🚀 Como usar
1. Monte o circuito seguindo a pinagem indicada no código.
2. Suba o código usando a Arduino IDE.
3. Acompanhe o status pelo Monitor Serial (115200 baud).
