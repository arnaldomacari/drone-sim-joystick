# 🎮 Drone Sim Joystick

Joystick desenvolvido para controle de drones em simuladores, usando microcontrolador e comandos personalizados.

O objetivo do projeto é criar uma interface física simples, barata e funcional para treinar pilotagem de drone em ambiente simulado.

---

## ✨ Funcionalidades

- Controle de aceleração, guinada, arfagem e rolagem
- Interface para simuladores de drone
- Leitura de potenciômetros/joysticks analógicos
- Comunicação BLE 
- Estrutura simples para expansão futura

---

## 🧠 Objetivo do projeto

Este projeto foi criado para estudar e testar controle manual de drones em simuladores, aproximando a experiência de pilotagem de um controle físico real.

Ele também serve como base para futuros projetos envolvendo:

- Controle remoto personalizado
- Drones educacionais
- Interfaces HID
- ESP32
- Simuladores de voo

---

## 🛠️ Tecnologias utilizadas

- Microcontrolador ESP32 / Arduino compatível
- Linguagem C/C++
- Arduino IDE ou ESP-IDF
- Entrada analógica por joystick/potenciômetros
- USB/Bluetooth HID, conforme a versão do projeto

Boards:

![boards](images/Boards.png)

https://github.com/espressif/arduino-esp32


ESP32 -C3 super mini 
![ESP32-C3 Super Mini Pinout](images/esp32_c3_super_mine.png)


Bibliotecas

![boards](images/bibliotecaTeclado.png)

https://github.com/HijelHub/HijelHID_BLEKeyboard

---

## 📷 Imagens do projeto

![Protoboards](images/protoboard.jpeg)


## 📁 Estrutura do projeto
```
drone-sim-joystick/
├── firmware/
│   └── código principal
├── hardware/
│   └── esquemas e ligações
├── images/
│   └── fotos do projeto
└── README.md
```


## 🚀 Como usar
Clone o repositório:
git clone https://github.com/SEU_USUARIO/drone-sim-joystick.git
Abra o firmware na Arduino IDE ou no VS Code.
Compile e grave no microcontrolador.
Conecte o joystick ao computador.
Configure os eixos no simulador de drone.



## 🔌 Ligações básicas
<!--Função	Pino
Eixo X	GPIO XX
Eixo Y	GPIO XX
Acelerador	GPIO XX
Botão 1	GPIO XX
Botão 2	GPIO XX -->
![Foto do joystick](images/esquema.png)


# 🧪 Status do projeto



## 🚧 Em desenvolvimento

 Leitura dos eixos analógicos
 Comunicação HID
 Calibração dos comandos
 Teste em simulador
 Gabinete impresso em 3D



## 📌 Próximos passos

Criar rotina de calibração
Adicionar botão de armar/desarmar
Criar modo iniciante
Melhorar gabinete
Documentar compatibilidade com simuladores



## 👨‍🔬 Autor
**Arnaldo José Macari**
Engenheiro de Alimentos e Desenvolvedor de Sistemas Embarcados
São José do Rio Preto – SP, Brasil

Projeto criado para estudo, prototipagem e treinamento com simuladores de drone.

## 📄 Licença

Este projeto está disponível para fins educacionais e experimentais.