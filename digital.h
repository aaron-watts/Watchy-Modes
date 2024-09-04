void WatchyBrain::drawDigital(float batt) {
  int16_t x1, y1;
  uint16_t w, h;
  String textstring;
  
  //background
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&NotoSans_Thin50pt7b);

  //draw hours
  textstring = (currentTime.Hour < 10) ? "0" : "";
  textstring += currentTime.Hour; 
  display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
  display.setCursor(0, 100 - ((100 - h) / 2));
  display.print(textstring);

  //draw minutes
  textstring = (currentTime.Minute < 10) ? "0" : "";
  textstring +=currentTime.Minute;
  display.setCursor(0, 200 - ((100 - h) / 2));
  display.print(textstring);

  //draw day
  display.setFont(&NotoSans_Light20pt7b);
  textstring = dayShortStr(currentTime.Wday);
  display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
  display.setCursor(190 - w, 185);
  display.print(textstring);

  //draw date
  textstring = (currentTime.Day < 10) ? "0" : "";
  textstring += currentTime.Day;
  display.getTextBounds(textstring, 0, 0, &x1, &y1, &w, &h);
  display.setCursor(190 - w, 200 - (h*2));
  display.print(textstring);

  //draw battery
  display.fillRoundRect(156, 16, 34, 12, 4, GxEPD_BLACK);
  display.fillRoundRect(189, 20, 3, 4, 2, GxEPD_BLACK);
  display.fillRoundRect(158, 18, 30, 8, 3, GxEPD_WHITE);
  if (batt > 0) {
    display.fillRoundRect(160, 20, 26 * batt, 4, 2, GxEPD_BLACK);
  }
}
