// Definir os pinos dos LEDs para Semáforo 1
const int vermelho1Pin = 13;
const int amarelo1Pin = 12;
const int verde1Pin = 11;

// Definir os pinos dos LEDs para Semáforo 2
const int vermelho2Pin = 10;
const int amarelo2Pin = 9;
const int verde2Pin = 8;

// Enumeração para os estados dos semáforos
enum State {
  SEMAFORO1_VERDE,     // Semáforo 1 está verde, Semáforo 2 está vermelho
  SEMAFORO1_AMARELO,   // Semáforo 1 está amarelo, Semáforo 2 ainda está vermelho
  SEMAFORO2_VERDE,     // Semáforo 2 está verde, Semáforo 1 está vermelho
  SEMAFORO2_AMARELO    // Semáforo 2 está amarelo, Semáforo 1 ainda está vermelho
};

// Variável para armazenar o estado atual
State estadoAtual = SEMAFORO1_VERDE;

// Tempos para cada estado (em milissegundos)
const unsigned long tempoVerde = 5000;    // 5 segundos para o verde
const unsigned long tempoAmarelo = 2000;  // 2 segundos para o amarelo
const unsigned long tempoVermelho = 5000; // 5 segundos para o vermelho

unsigned long tempoAnterior = 0; // Para controlar o tempo entre mudanças

void setup() {
  // Configurar os pinos dos LEDs do Semáforo 1 como saída
  pinMode(vermelho1Pin, OUTPUT);
  pinMode(amarelo1Pin, OUTPUT);
  pinMode(verde1Pin, OUTPUT);
  
  // Configurar os pinos dos LEDs do Semáforo 2 como saída
  pinMode(vermelho2Pin, OUTPUT);
  pinMode(amarelo2Pin, OUTPUT);
  pinMode(verde2Pin, OUTPUT);

  // Inicializar os semáforos
  tempoAnterior = millis(); // Inicializar o tempoAnterior com o tempo atual
}

void loop() {
  unsigned long tempoAtual = millis(); // Obter o tempo atual

  switch (estadoAtual) {
    case SEMAFORO1_VERDE:
      // Semáforo 1 verde, Semáforo 2 vermelho
      digitalWrite(verde1Pin, HIGH);
      digitalWrite(amarelo1Pin, LOW);
      digitalWrite(vermelho1Pin, LOW);

      digitalWrite(verde2Pin, LOW);
      digitalWrite(amarelo2Pin, LOW);
      digitalWrite(vermelho2Pin, HIGH);

      // Verificar se o tempo do estado verde já passou
      if (tempoAtual - tempoAnterior >= tempoVerde) {
        estadoAtual = SEMAFORO1_AMARELO; // Mudar para o amarelo do Semáforo 1
        tempoAnterior = tempoAtual; // Atualizar o tempo anterior
      }
      break;

    case SEMAFORO1_AMARELO:
      // Semáforo 1 amarelo, Semáforo 2 ainda vermelho
      digitalWrite(verde1Pin, LOW);
      digitalWrite(amarelo1Pin, HIGH);
      digitalWrite(vermelho1Pin, LOW);

      digitalWrite(verde2Pin, LOW);
      digitalWrite(amarelo2Pin, LOW);
      digitalWrite(vermelho2Pin, HIGH);

      // Verificar se o tempo do estado amarelo já passou
      if (tempoAtual - tempoAnterior >= tempoAmarelo) {
        estadoAtual = SEMAFORO2_VERDE; // Mudar para o verde do Semáforo 2
        tempoAnterior = tempoAtual;
      }
      break;

    case SEMAFORO2_VERDE:
      // Semáforo 1 vermelho, Semáforo 2 verde
      digitalWrite(verde1Pin, LOW);
      digitalWrite(amarelo1Pin, LOW);
      digitalWrite(vermelho1Pin, HIGH);

      digitalWrite(verde2Pin, HIGH);
      digitalWrite(amarelo2Pin, LOW);
      digitalWrite(vermelho2Pin, LOW);

      // Verificar se o tempo do estado verde já passou
      if (tempoAtual - tempoAnterior >= tempoVerde) {
        estadoAtual = SEMAFORO2_AMARELO; // Mudar para o amarelo do Semáforo 2
        tempoAnterior = tempoAtual;
      }
      break;

    case SEMAFORO2_AMARELO:
      // Semáforo 1 vermelho, Semáforo 2 amarelo
      digitalWrite(verde1Pin, LOW);
      digitalWrite(amarelo1Pin, LOW);
      digitalWrite(vermelho1Pin, HIGH);

      digitalWrite(verde2Pin, LOW);
      digitalWrite(amarelo2Pin, HIGH);
      digitalWrite(vermelho2Pin, LOW);

      // Verificar se o tempo do estado amarelo já passou
      if (tempoAtual - tempoAnterior >= tempoAmarelo) {
        estadoAtual = SEMAFORO1_VERDE; // Voltar ao verde do Semáforo 1
        tempoAnterior = tempoAtual;
      }
      break;
  }
}
