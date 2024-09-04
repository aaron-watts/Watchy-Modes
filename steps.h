void WatchyBrain::drawSteps(float batt) {
  int16_t x1, y1;
  uint16_t w, h;
  String textstring;
  
  //background
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&NotoSans_ExtraLight28pt7b);

  //draw steps
  display.drawBitmap(100 - 24, 45, steps, 48, 48, GxEPD_BLACK);
  if (currentTime.Hour == 0 && currentTime.Minute == 0){
    sensor.resetStepCounter();  
  }
  textstring = sensor.getCounter();
  display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
  display.setCursor(100 - (w/2), 150);
  display.println(textstring);

  //draw battery
  display.fillRoundRect(156, 16, 34, 12, 4, GxEPD_BLACK);
  display.fillRoundRect(189, 20, 3, 4, 2, GxEPD_BLACK);
  display.fillRoundRect(158, 18, 30, 8, 3, GxEPD_WHITE);
  if (batt > 0) {
    display.fillRoundRect(160, 20, 26 * batt, 4, 2, GxEPD_BLACK);
  }
}
