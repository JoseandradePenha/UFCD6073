#include <WiFi.h>
#include <Preferences.h>  // Biblioteca para armazenamento não volátil no ESP32

// Definir o nome da rede WiFi (SSID)
const char* ssid = "NomeDaRede";

// Criação de um objeto para lidar com as preferências
Preferences preferences;

// Variável para armazenar a palavra-passe do WiFi
String wifiPassword;

// Função para conectar à rede WiFi
void connectToWiFi(String password) {
  WiFi.begin(ssid, password.c_str());
  Serial.print("A conectar ao WiFi");

  // Esperar até conectar
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 20) {
    delay(500);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConectado ao WiFi!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFalha ao conectar-se ao WiFi.");
  }
}

// Função para alterar e guardar a palavra-passe
void changePassword(String newPassword) {
  // Guardar a nova palavra-passe na memória
  preferences.putString("wifi_pass", newPassword);
  wifiPassword = newPassword;
  Serial.println("Nova palavra-passe guardada.");
}

// Função para ler a palavra-passe guardada
String getPasswordFromMemory() {
  return preferences.getString("wifi_pass", "defaultpassword"); // Palavra-passe por defeito
}

void setup() {
  Serial.begin(115200);

  // Iniciar as preferências
  preferences.begin("wifi_credentials", false);

  // Ler a palavra-passe guardada
  wifiPassword = getPasswordFromMemory();
  Serial.print("Palavra-passe recuperada: ");
  Serial.println(wifiPassword);

  // Tentar conectar ao WiFi
  connectToWiFi(wifiPassword);

  // Exemplo de alteração de palavra-passe (simulação)
  delay(10000); // Esperar 10 segundos
  String newPassword = "novaSenha123";
  changePassword(newPassword);

  // Reiniciar o ESP para simular falha de energia
  ESP.restart();
}

void loop() {
  // Verificar se o WiFi está conectado
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Tentando reconectar ao WiFi...");
    connectToWiFi(wifiPassword);
  }
  delay(10000);  // Esperar 10 segundos entre verificações
}
