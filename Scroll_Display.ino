void scrolling_date() {
  dmd.clearScreen(true);
  delay(0);


  String Date = String(_day) + "" + String(month_name[_month - 1]) + "-" + String(_year);
  char dt[50];
  Date.toCharArray(dt, 50);
  int i = 32 + 10;
  int j = strlen(dt) + (strlen(dt) * 5);
  //  String(nameoftheday[_dtw]) + ", " +

  dmd.selectFont(SystemFont5x7U);

  while (1) {

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis; //-> save the last time


      str_hr_24 = String(_hour24);
      str_hr_24.toCharArray(hr_24, 3);

      if (_hour24 < 10) {
        dmd.drawString(2, 0, "0", 1, GRAPHICS_NORMAL);
        dmd.drawString(8, 0, hr_24, 1, GRAPHICS_NORMAL);
      }
      else {
        dmd.drawString(2, 0, hr_24, 2, GRAPHICS_NORMAL);
      }



      GetDateTime(); //-> Retrieve time and date data from DS1307
      if (_second % 2 == 0) {
        dmd.drawString(14, 0, ":", 2, GRAPHICS_OR);
      }
      else {
        dmd.drawString(14, 0, ":", 2, GRAPHICS_NOR);
      }



      str_mn = String(_minute);
      str_mn.toCharArray(mn, 3);

      if (_minute < 10) {
        dmd.drawString(19, 0, "0", 1, GRAPHICS_NORMAL);
        dmd.drawString(25, 0, mn, 1, GRAPHICS_NORMAL);
      }
      else {
        dmd.drawString(19, 0, mn, 2, GRAPHICS_NORMAL);
      }

    }



    unsigned long currentMillis_for_date = millis();
    if (currentMillis_for_date - previousMillis_for_date >= interval_for_date) {
      previousMillis_for_date = currentMillis_for_date; //-> save the last time

      i--;
      dmd.drawString(i, 9, dt, strlen(dt), GRAPHICS_NORMAL);
      if (i <= ~j) {
        dmd.clearScreen(true);
        delay(100);
        return;
      }
    }

  }
}
