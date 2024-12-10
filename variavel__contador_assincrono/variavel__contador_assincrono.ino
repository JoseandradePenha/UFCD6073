// Definir a pinagem do botão
const int botaoPin = 2;  // Pino digital ligado ao botão
volatile int contador = 0;  // Contador assíncrono (precisa ser 'volatile' por causa da interrupção)

// Função que será chamada pela interrupção
void incrementarContador() {
  contador++;  // Incrementa o contador sempre que a interrupção for ativada
}

void setup() {
  // Iniciar comunicação Serial para debug
  Serial.begin(9600);
  
  // Configurar o pino do botão como entrada
  pinMode(botaoPin, INPUT_PULLUP);  // Utilizamos o resistor pull-up interno do Arduino

  // Configurar a interrupção: ativa na borda descendente (quando o botão é pressionado)
  attachInterrupt(digitalPinToInterrupt(botaoPin), incrementarContador, FALLING);

  Serial.println("Sistema Iniciado");
}

void loop() {
  // Exibir o valor atual do contador
  Serial.print("Contador: ");
  Serial.println(contador);

  // Simular outras tarefas
  delay(1000);  // Espera 1 segundo antes de atualizar o contador
}
