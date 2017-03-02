unsigned int keys[] = { KEY_A, KEY_B, KEY_C, KEY_D, KEY_E,
                        KEY_F, KEY_G, KEY_H, KEY_I, KEY_J,
                        KEY_K, KEY_L, KEY_M, KEY_N, KEY_O,
                        KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T,
                        KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, 
                        KEY_Z,
                      };

bool pressed[26];
                      
void setup() {
  Keyboard.begin();

  for (int i = 0; i < 24; i++){ pinMode(i, INPUT_PULLUP); }
  delay(1000);

  for (unsigned int i = 0; i < sizeof(pressed); i++){ pressed[i] = false; }
}

//void SendKey(int key) {
//    Keyboard.set_key1(key);
//    Keyboard.send_now();
//    Keyboard.set_key1(0);
//    Keyboard.send_now();
//    delay(180);
//}

void loop() {
  for (int i = 0; i < 24; i++){
    if ((digitalRead(i) == LOW) && (pressed[i] == false)) {
      Keyboard.set_key1(keys[i]);
      Keyboard.send_now();
      delay(20);  // Debounce
      pressed[i] = true;
    }
    if ((digitalRead(i) == HIGH) && (pressed[i] == true)) {
      Keyboard.set_key1(0);
      Keyboard.send_now();
      pressed[i] = false;
    }
  }
}
