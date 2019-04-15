/*
 * this section is made up of groups of variables. 
 * Variables store data and information that can be 
 * called back to later on in the code. 
 */
 
 /*
 * these variables set up the Pins in a more readable way, 
 * taking the Teensy Touch Pin numbers and putting them
 * in a more understandable order of 1 to 8 
 */
int touchRead_pin_1 = 0; 
int touchRead_pin_2 = 1; 
int touchRead_pin_3 = 3;
int touchRead_pin_4 = 4;
int touchRead_pin_5 = 15;
int touchRead_pin_6 = 16;
int touchRead_pin_7 = 17;
int touchRead_pin_8 = 18;

/*
 * This variable sets up a threshold for the Touch pins
 * The touch pins pick up data in a number form. 
 * The number the touch pin read may not always be at 0
 * if we set our own threshold for the data, the touch
 * sensor becomes more reliable and less likely to
 * activate a note when it isn't being played. 
 */
int thresh = 2200; 

/*
 * These variables are set up for each pin to make sure
 * that each pin has a way of being triggered
 */
int play_flag_1 = 0; 
int play_flag_2 = 0; 
int play_flag_3 = 0;
int play_flag_4 = 0; 
int play_flag_5 = 0; 
int play_flag_6 = 0;
int play_flag_7 = 0; 
int play_flag_8 = 0; 

/*
 * these variables will be used as a way for the 
 * threshold to be correctly read and ultimately to
 * allow the note to be activated. 
 */
int current_1; 
int current_2;
int current_3; 
int current_4;
int current_5; 
int current_6;
int current_7; 
int current_8;

/*
 * This 3 millisecond delay allows the code time to 
 * run and activate the note without noticably 
 * affecting the response
 */
int delay_time = 3; 

void setup() {

}

void loop() {
  //This line of code detects which is being interacted
  current_1 = touchRead(touchRead_pin_1); // 48 = C3
  
/*This section uses all of the variables we had created earlier to determine
what pin is being interacted with and checking if it has met the minimum threshold
we set earlier
the code here then sends the not information to play whatever MIDI note has been 
set up for each pin.
Ths MIDI not arguments are as follows;
usbMIDI.sendNoteOn(MIDI Note Number, Velocity, Channel)

The section here determines that this button will playa a C3 MIDI note
*/
  if(current_1 > thresh && play_flag_1 == 0) {
    play_flag_1 = 1;
    usbMIDI.sendNoteOn(48, 127, 1); 
    delay(delay_time); 
  }
/*
 * This section here stops the C3 MIDI note from continuring after the 
 * threshold drops below the minimum we set in the variables
 */
  if(current_1 < thresh && play_flag_1 == 1) {
    play_flag_1 = 0;
    usbMIDI.sendNoteOff(48, 0, 1); 
    delay(delay_time); 
  }
/*
 * Each pin has a NoteOn and NoteOff section as continues below until all 
 * 8 pins are set up to create the C_Major Scale
 */
  current_2 = touchRead(touchRead_pin_2); // 50 = D3

  if(current_2 > thresh && play_flag_2 == 0) {
    play_flag_2 = 1;
    usbMIDI.sendNoteOn(50, 127, 1); 
    delay(delay_time); 
  }

  if(current_2 < thresh && play_flag_2 == 1) {
    play_flag_2 = 0;
    usbMIDI.sendNoteOff(50, 0, 1); 
    delay(delay_time); 
  }

  current_3 = touchRead(touchRead_pin_3); // 52 = E3

  if(current_3 > thresh && play_flag_3 == 0) {
    play_flag_3 = 1;
    usbMIDI.sendNoteOn(52, 127, 1); 
    delay(delay_time); 
  }

  if(current_3 < thresh && play_flag_3 == 1) {
    play_flag_3 = 0;
    usbMIDI.sendNoteOff(52, 0, 1); 
    delay(delay_time); 
  }

    current_4 = touchRead(touchRead_pin_4); // 53 = F3

  if(current_4 > thresh && play_flag_4 == 0) {
    play_flag_4 = 1;
    usbMIDI.sendNoteOn(53, 127, 1); 
    delay(delay_time); 
  }

  if(current_4 < thresh && play_flag_4 == 1) {
    play_flag_4 = 0;
    usbMIDI.sendNoteOff(53, 0, 1); 
    delay(delay_time); 
  }
  
    current_5 = touchRead(touchRead_pin_5); // 55 = G3

  if(current_5 > thresh && play_flag_5 == 0) {
    play_flag_5 = 1;
    usbMIDI.sendNoteOn(55, 127, 1); 
    delay(delay_time); 
  }

  if(current_5 < thresh && play_flag_5 == 1) {
    play_flag_5 = 0;
    usbMIDI.sendNoteOff(55, 0, 1); 
    delay(delay_time); 
  }
     current_6 = touchRead(touchRead_pin_6); // 57 = A3

  if(current_6 > thresh && play_flag_6 == 0) {
    play_flag_6 = 1;
    usbMIDI.sendNoteOn(57, 127, 1); 
    delay(delay_time); 
  }

  if(current_6 < thresh && play_flag_6 == 1) {
    play_flag_6 = 0;
    usbMIDI.sendNoteOff(57, 0, 1); 
    delay(delay_time); 
  }
     current_7 = touchRead(touchRead_pin_7); // 59 = B3

  if(current_7 > thresh && play_flag_7 == 0) {
    play_flag_7 = 1;
    usbMIDI.sendNoteOn(59, 127, 1); 
    delay(delay_time); 
  }

  if(current_7 < thresh && play_flag_7 == 1) {
    play_flag_7 = 0;
    usbMIDI.sendNoteOff(59, 0, 1); 
    delay(delay_time); 
  }
     current_8 = touchRead(touchRead_pin_8); // 60 = C4

  if(current_8 > thresh && play_flag_8 == 0) {
    play_flag_8 = 1;
    usbMIDI.sendNoteOn(60, 127, 1); 
    delay(delay_time); 
  }
  
 if(current_8 < thresh && play_flag_8 == 1) {
    play_flag_8 = 0;
    usbMIDI.sendNoteOff(60, 0, 1); 
    delay(delay_time); 
  }
}
