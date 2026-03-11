// --- Configurações do Jogo ---
const int leds[] = {2, 5};      
const int botoes[] = {4, 18};   
const int pinoBuzzer = 27; // Seu pino atualizado!

// Sons: 262Hz (Dó) para o LED Azul, 330Hz (Mi) para o LED Amarelo
const int notas[] = {262, 330}; 
const int notaErro = 150; 

int sequencia[100];             
int rodada = 0;                 
bool fimDeJogo = false;

void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(botoes[i], INPUT);
  }
  pinMode(pinoBuzzer, OUTPUT);
  
  Serial.begin(115200);
  randomSeed(analogRead(34)); // Semente aleatória
  
  Serial.println("Geng-nius Pronto! Aguardando início...");
  delay(1000);
}

void loop() {
  if (fimDeJogo) {
    rodada = 0;
    fimDeJogo = false;
    delay(1500);
  }

  // Adiciona novo passo
  sequencia[rodada] = random(0, 2); 
  rodada++;

  // 1. O Geng-nius mostra a sequência
  for (int i = 0; i < rodada; i++) {
    int cor = sequencia[i];
    digitalWrite(leds[cor], HIGH);
    tone(pinoBuzzer, notas[cor]); 
    delay(500);
    digitalWrite(leds[cor], LOW);
    noTone(pinoBuzzer);          
    delay(200);
  }

  // 2. Sua vez de repetir
  for (int i = 0; i < rodada; i++) {
    int botaoPressionado = -1;
    
    // Espera você apertar algo
    while (botaoPressionado == -1) {
      for (int b = 0; b < 2; b++) {
        if (digitalRead(botoes[b]) == HIGH) {
          botaoPressionado = b;
          
          // Som e luz de feedback do seu clique
          digitalWrite(leds[b], HIGH);
          tone(pinoBuzzer, notas[b]);
          while(digitalRead(botoes[b]) == HIGH); // Espera soltar
          delay(50); 
          digitalWrite(leds[b], LOW);
          noTone(pinoBuzzer);
        }
      }
    }

    // 3. Verificação de erro
    if (botaoPressionado != sequencia[i]) {
      Serial.println("GAME OVER!");
      somErro();
      fimDeJogo = true;
      return; 
    }
  }
  
  Serial.println("Nível Concluído!");
  delay(800);
}

void somErro() {
  tone(pinoBuzzer, notaErro);
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[0], HIGH); digitalWrite(leds[1], HIGH);
    delay(200);
    digitalWrite(leds[0], LOW); digitalWrite(leds[1], LOW);
    delay(200);
  }
  noTone(pinoBuzzer);
}
