void WatchyBrain::drawAnalog() {
  //background
  display.drawBitmap(0, 0, clockFace_square2, 200, 200, GxEPD_WHITE);
  display.fillCircle(100,100,3,GxEPD_BLACK);

  // draw logo
  display.setTextColor(GxEPD_BLACK);
  display.setCursor(72, 40);
  display.setFont(&FreeSerifBoldItalic9pt7b);
  display.print("Watchy");
  display.setCursor(52, 60);
  display.setFont(&FreeSerifItalic9pt7b);
  display.print("Chronometrie");

  // draw battery
  display.drawCircleHelper(45, 100, 20, 2, GxEPD_BLACK);
  display.drawCircleHelper(45, 100, 20, 4, GxEPD_BLACK);
  display.drawPixel(65, 100, GxEPD_BLACK);
  display.drawFastVLine(45, 79, 4, GxEPD_BLACK);
  display.drawFastHLine(63, 100, 4, GxEPD_BLACK);
  display.drawFastVLine(45, 118, 4, GxEPD_BLACK);
  display.fillCircle(45, 100, 2, GxEPD_BLACK);
  double batteryCurrent = (getBatteryVoltage() - 3.3) / 0.9;
  double batteryAngle = batteryCurrent * 180;
  double radBattery = ((batteryAngle) * 71) / 4068.0;
  double bx1 = 45 + (sin(radBattery) * 16);
  double by1 = 100 + (cos(radBattery) * 16);
  display.drawLine(45, 100, (int)bx1, (int)by1, GxEPD_BLACK);

  //minute pointer
  int currentMinute = currentTime.Minute;
  int minuteAngle = currentMinute * 6;
  double radMinute = ((minuteAngle + 180) * 71) / 4068.0;
  double mx1 = 100 - (sin(radMinute) * 85);
  double my1 = 100 + (cos(radMinute) * 85);
  display.drawLine(100, 100, (int)mx1, (int)my1, GxEPD_BLACK);

  //hour pointer
  int currentHour= currentTime.Hour;
  double hourAngle = (currentHour * 30) + currentMinute * 0.5;
  double radHour = ((hourAngle + 180) * 71) / 4068.0;
  double hx1 = 100 - (sin(radHour) * 45);
  double hy1 = 100 + (cos(radHour) * 45);
  display.drawLine(100, 100, (int)hx1, (int)hy1, GxEPD_BLACK);
}
