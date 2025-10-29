#include "M5Cardputer.h"

M5Canvas canvas(&M5Cardputer.Display);


const int8_t GRID_SIZE = 4;

int8_t snake[256][2];
int8_t snakeDirection = 0;
int16_t snakeSpeed = 90;
int16_t snakeLength = 1;

int8_t appleX;
int8_t appleY;

void setup() {
  Serial.begin(9600);
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);  // enableKeyboard

  //Init Display canvas
  uint8_t displayWidth = M5Cardputer.Display.width();
  uint8_t displayHeight = M5Cardputer.Display.height();

  canvas.createSprite(displayWidth, displayHeight);
  Serial.println(displayWidth);
  Serial.println(displayHeight);

  snake[0][0] = 2;
  snake[0][1] = 2;

  spawnApple();
}

void loop() {
  M5Cardputer.update();
  tick();
  render();
}

void tick() {

  if (M5Cardputer.Keyboard.isKeyPressed(';') && snakeDirection != 2) {
    snakeDirection = 0;
  } else if (M5Cardputer.Keyboard.isKeyPressed('/') && snakeDirection != 3) {
    snakeDirection = 1;
  } else if (M5Cardputer.Keyboard.isKeyPressed('.') && snakeDirection != 0) {
    snakeDirection = 2;
  } else if (M5Cardputer.Keyboard.isKeyPressed(',') && snakeDirection != 1) {
    snakeDirection = 3;
  }

  snakeSpeed++;
  if (snakeSpeed >= 100) {

    for (int i = snakeLength; i > 0; i--) {
      snake[i][0] = snake[i - 1][0];
      snake[i][1] = snake[i - 1][1];
    }
    switch (snakeDirection) {
      case 0:
        snake[0][1]--;
        if (snake[0][1] == -1) {
          snake[0][1] = 33;
        }
        break;
      case 1:
        snake[0][0]++;
        if (snake[0][0] == 60) {
          snake[0][0] = 0;
        }
        break;
      case 2:
        snake[0][1]++;
        if (snake[0][1] == 34) {
          snake[0][1] = 0;
        }
        break;
      case 3:
        snake[0][0]--;
        if (snake[0][0] == -1) {
          snake[0][0] = 59;
        }
        break;
    }
    if (snake[0][0] == appleX && snake[0][1] == appleY) {
      // grow snake by one (prevent exceeding buffer)
      if (snakeLength < 255) {
        snakeLength++;
      }
      spawnApple();
    }

    snakeSpeed = 90;
  }
}

void spawnApple() {
  do {
    appleX = random(0, 60);
    appleY = random(0, 34);
    Serial.println(appleX);
    Serial.println(appleY);
  } while (checkApple());
}

bool checkApple() {
  bool foundError = false;
  for (int i = 0; i < snakeLength; i++) {
    if (snake[0][0] == appleX && snake[0][1] == appleY) {
      foundError = true;
    }
  }
  return foundError;
}


void render() {
  canvas.fillScreen(BLACK);
  for (int i = 0; i < snakeLength; i++) {
    canvas.fillRect(snake[i][0] * GRID_SIZE, snake[i][1] * GRID_SIZE, 4, 4, WHITE);
  }
  canvas.fillRect(appleX * GRID_SIZE, appleY * GRID_SIZE, 4, 4, RED);
  canvas.pushSprite(0, 0);
}