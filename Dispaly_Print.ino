void drawText1( String dispString ) {
  dmd.clearScreen( true );
  dmd.selectFont(Arial_Black_16);
  char newString[256];
  int sLength = dispString.length();
  dispString.toCharArray( newString, sLength + 1 );
  dmd.drawMarquee( newString ,sLength , ( 32 * DISPLAYS_ACROSS ) - 1 , 1);

  long start = millis();
  long timer = start;
  long timer2 = start;
  boolean ret = false;
  while ( !ret ) {
    if ( ( timer + timeScroll ) < millis() )
    {
      ret = dmd.stepMarquee( -1 , 0 );
      timer = millis();
    }
  }
}
