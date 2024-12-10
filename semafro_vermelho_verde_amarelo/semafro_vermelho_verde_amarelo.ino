// Definir os pinos dos LEDs
const int vermelhoPin = 13;
const int amareloPin = 12;
const int verdePin = 11;

// Enumeração para os estados do semáforo
enum State {
  VERMELHO,
  AMARELO,
  VERDE
};

// Variável para armazenar o estado atual
State estadoAtual = VERMELHO;

// Tempos para cada estado (em milissegundos)
const unsigned long tempoVermelho = 5000; // 5 segundos
const unsigned long tempoAmarelo = 2000;  // 2 segundos
const unsigned long tempoVerde = 5000;    // 5 segundos

unsigned long tempoAnterior = 0; // Para controlar o tempo entre mudanças

void setup() {
  // Configurar os pinos dos LEDs como saída
  pinMode(vermelhoPin, OUTPUT);
  pinMode(amareloPin, OUTPUT);
  pinMode(verdePin, OUTPUT);

  // Inicializa o estado inicial
  tempoAnterior = millis(); // Inicializar tempoAnterior com o tempo atual
}

void loop() {
  unsigned long tempoAtual = millis(); // Obter o tempo atual

  switch (estadoAtual) {
    case VERMELHO:
      // Ligar LED vermelho e desligar os outros
      digitalWrite(vermelhoPin, HIGH);
      digitalWrite(amareloPin, LOW);
      digitalWrite(verdePin, LOW);

      // Verificar se o tempo do estado vermelho já passou
      if (tempoAtual - tempoAnterior >= tempoVermelho) {
        estadoAtual = VERDE; // Mudar para o próximo estado
        tempoAnterior = tempoAtual; // Atualizar o tempo anterior
      }
      break;

    case VERDE:
      // Ligar LED verde e desligar os outros
      digitalWrite(vermelhoPin, LOW);
      digitalWrite(amareloPin, LOW);
      digitalWrite(verdePin, HIGH);

      // Verificar se o tempo do estado verde já passou
      if (tempoAtual - tempoAnterior >= tempoVerde) {
        estadoAtual = AMARELO; // Mudar para o próximo estado
        tempoAnterior = tempoAtual; // Atualizar o tempo anterior
      }
      break;

    case AMARELO:
      // Ligar LED amarelo e desligar os outros
      digitalWrite(vermelhoPin, LOW);
      digitalWrite(amareloPin, HIGH);
      digitalWrite(verdePin, LOW);

      // Verificar se o tempo do estado amarelo já passou
      if (tempoAtual - tempoAnterior >= tempoAmarelo) {
        estadoAtual = VERMELHO; // Mudar para o próximo estado
        tempoAnterior = tempoAtual; // Atualizar o tempo anterior
      }
      break;
  }
}
