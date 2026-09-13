Arduino - Semáforo Veicular e Pedestre

Projeto de semáforo veicular e pedestre utilizando Arduino, LEDs e push button.

📋 Descrição

O projeto simula o funcionamento de um semáforo de veículos com sinalização para pedestres.

O sistema inicia com o sinal verde para os veículos e vermelho para os pedestres. Quando o botão é pressionado, o sistema executa a sequência de mudança dos sinais até liberar a travessia do pedestre.

🧰 Componentes

- Arduino
- 3 LEDs para os veículos
  - Verde
  - Amarelo
  - Vermelho
- 2 LEDs para pedestres
  - Verde
  - Vermelho
- Push button
- Resistores para os LEDs
- Protoboard e fios jumper

🔌 Ligações dos componentes

Semáforo dos veículos

Componente| Pino Arduino
LED verde| 2
LED amarelo| 4
LED vermelho| 6

Cada LED deve ser ligado em série com um resistor:

Pino Arduino → Resistor → LED → GND

Semáforo dos pedestres

Componente| Pino Arduino
LED vermelho| 8
LED verde| 10

Ligação:

Pino Arduino → Resistor → LED → GND

Push button

O botão utiliza o "INPUT_PULLUP".

Pino 12 ───────┐
               │
           ┌───┴───┐
           │ BOTÃO │
           └───┬───┘
               │
              GND

Quando o botão é pressionado, o Arduino recebe "LOW".

Não é necessário utilizar um resistor externo para o botão, pois o código utiliza o resistor interno "INPUT_PULLUP".

📐 Esquema visual geral

                         ARDUINO
                    ┌───────────────┐
                    │               │
Pino 2  ──[R]──► 🟢 LED veículos ──┐
Pino 4  ──[R]──► 🟡 LED veículos ──┤
Pino 6  ──[R]──► 🔴 LED veículos ──┤
                                    │
Pino 8  ──[R]──► 🔴 LED pedestre ───┤
Pino 10 ──[R]──► 🟢 LED pedestre ───┤
                                    │
GND ────────────────────────────────┘


Pino 12 ──────────┐
                  │
              ┌───┴───┐
              │ BOTÃO │
              └───┬───┘
                  │
                 GND

Legenda:

- "[R]" = resistor em série com o LED.
- "🟢" = LED verde.
- "🟡" = LED amarelo.
- "🔴" = LED vermelho.
- Todos os LEDs possuem ligação ao GND.
- O botão está conectado entre o pino 12 e o GND.

⚙️ Funcionamento

1. O semáforo inicia com o verde dos veículos ligado.
2. O vermelho dos pedestres permanece ligado.
3. O sistema aguarda o acionamento do botão.
4. Após pressionar o botão, o verde dos veículos permanece ligado por 5 segundos.
5. O vermelho dos veículos pisca 3 vezes.
6. O amarelo dos veículos pisca 4 vezes.
7. O vermelho dos veículos e o verde dos pedestres são acionados.
8. O pedestre possui 5 segundos para realizar a travessia.
9. O sistema retorna ao estado inicial.

💻 Código

O código do projeto está disponível em:

"Arduino/semaforo.ino"

📚 Bibliotecas

O projeto não utiliza bibliotecas externas.

São utilizadas apenas funções disponíveis no ambiente Arduino, como:

- "pinMode()"
- "digitalWrite()"
- "digitalRead()"
- "delay()"

🎯 Objetivo

Projeto desenvolvido durante os estudos de Arduino e sistemas embarcados, com foco na utilização de entradas, saídas digitais, LEDs, botão e lógica de controle.
