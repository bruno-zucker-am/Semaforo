#define LED_VERDE 2
#define LED_AMARELO 4
#define LED_VERMELHO 6

#define LED_P_VERDE 10
#define LED_P_VERMELHO 8

#define BOTAO 12

void setup()
{
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_P_VERMELHO, OUTPUT);
  pinMode(LED_P_VERDE, OUTPUT);

  pinMode(BOTAO, INPUT_PULLUP);
}

void loop()
{
  // Estado normal
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_P_VERMELHO, HIGH);

  // Espera o botão ser pressionado
  if (digitalRead(BOTAO) == LOW)
  {
    delay(50); // debounce simples

    // Confirma se o botão continua pressionado
    if (digitalRead(BOTAO) == LOW)
    {
      // Mantém o verde dos carros durante 5 segundos
      delay(5000);

      // Apaga o verde
      digitalWrite(LED_VERDE, LOW);

      // Vermelho dos carros piscando
      for (int i = 0; i < 3; i++)
      {
        digitalWrite(LED_VERMELHO, HIGH);
        delay(500);
        digitalWrite(LED_VERMELHO, LOW);
        delay(500);
      }

      // Amarelo piscando
      for (int i = 0; i < 4; i++)
      {
        digitalWrite(LED_AMARELO, HIGH);
        delay(500);
        digitalWrite(LED_AMARELO, LOW);
        delay(500);
      }

      // Carros vermelho / pedestre verde
      digitalWrite(LED_VERMELHO, HIGH);
      digitalWrite(LED_P_VERDE, HIGH);
      digitalWrite(LED_P_VERMELHO, LOW);

      // Tempo para o pedestre atravessar
      delay(5000);

      // Finaliza a travessia
      digitalWrite(LED_P_VERDE, LOW);
      digitalWrite(LED_VERMELHO, LOW);
    }
  }
}