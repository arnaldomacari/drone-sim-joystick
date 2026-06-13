#include <HijelHID_BLEKeyboard.h>

HijelHID_BLEKeyboard keyboard("Controle Drone");

// Joyssdtick esquerdo - WASD
const int JOY_L_X = 4;
const int JOY_L_Y = 3;

// Joystick direito - setas
const int JOY_R_X = 0;
const int JOY_R_Y = 1;

// Ajuste conforme suas leituras reais
const int CENTRO = 2048;
const int ZONA_MORTA = 700;

bool wPress = false;
bool sPress = false;
bool aPress = false;
bool dPress = false;

bool upPress = false;
bool downPress = false;
bool leftPress = false;
bool rightPress = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Controle BLE com dois joysticks");

  pinMode(JOY_L_X, INPUT);
  pinMode(JOY_L_Y, INPUT);
  pinMode(JOY_R_X, INPUT);
  pinMode(JOY_R_Y, INPUT);

  keyboard.setLogLevel(HIDLogLevel::Normal);
  keyboard.begin();

  Serial.println("Pareie o ESP32 via Bluetooth.");
}

void loop() {
  if (!keyboard.isPaired()) {
    static unsigned long lastPrint = 0;
    if (millis() - lastPrint > 3000) {
      Serial.println("Aguardando conexao Bluetooth...");
      lastPrint = millis();
    }
    return;
  }

  int lx = analogRead(JOY_L_X);
  int ly = analogRead(JOY_L_Y);

  int rx = analogRead(JOY_R_X);
  int ry = analogRead(JOY_R_Y);

  // Debug opcional
  Serial.print("LX: ");
  Serial.print(lx);
  Serial.print(" LY: ");
  Serial.print(ly);
  Serial.print(" RX: ");
  Serial.print(rx);
  Serial.print(" RY: ");
  Serial.println(ry);

  // Joystick esquerdo: WASD
  controlaTecla(ly > CENTRO + ZONA_MORTA, KEY_W, wPress);
  controlaTecla(ly < CENTRO - ZONA_MORTA, KEY_S, sPress);
  controlaTecla(lx < CENTRO - ZONA_MORTA, KEY_A, aPress);
  controlaTecla(lx > CENTRO + ZONA_MORTA, KEY_D, dPress);

  // Joystick direito: setas
  controlaTecla(ry > CENTRO + ZONA_MORTA, KEY_DOWN, downPress);
  controlaTecla(ry < CENTRO - ZONA_MORTA, KEY_UP, upPress);
  controlaTecla(rx < CENTRO - ZONA_MORTA, KEY_LEFT, leftPress);
  controlaTecla(rx > CENTRO + ZONA_MORTA, KEY_RIGHT, rightPress);

  delay(20);
}

void controlaTecla(bool condicao, uint8_t tecla, bool &estado) {
  if (condicao && !estado) {
    keyboard.press(tecla);
    estado = true;
  }

  if (!condicao && estado) {
    keyboard.releaseAll();
    estado = false;

    // Reenvia as outras teclas que ainda deveriam estar pressionadas
    reaplicaTeclas();
  }
}

void reaplicaTeclas() {
  if (wPress) keyboard.press(KEY_W);
  if (sPress) keyboard.press(KEY_S);
  if (aPress) keyboard.press(KEY_A);
  if (dPress) keyboard.press(KEY_D);

  if (upPress) keyboard.press(KEY_UP);
  if (downPress) keyboard.press(KEY_DOWN);
  if (leftPress) keyboard.press(KEY_LEFT);
  if (rightPress) keyboard.press(KEY_RIGHT);
}
