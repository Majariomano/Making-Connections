/* Buttons to USB MIDI Code

   You must select MIDI from the "Tools > USB Type" menu

   This Code is set up to play a C Major Scale over 8 connected buttons.
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 5);
Bounce button1 = Bounce(1, 5); 
Bounce button2 = Bounce(2, 5);  
Bounce button3 = Bounce(3, 5);  
Bounce button4 = Bounce(4, 5);
Bounce button5 = Bounce(5, 5); 
Bounce button6 = Bounce(6, 5); 
Bounce button7 = Bounce(7, 5); 

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP); 
  pinMode(7, INPUT_PULLUP);
}

// This loop function is always present in any code you will come across using Arduino IDE 
//The Loop function serves to repeat any messages you have set up within it.
//This loop function here will ensure that once the code runs it will allow us to 
// play the notes using the buttons over and over again.
void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();

  //This fallingEdge section of the code updates repetetively to make sure any button
  //that is pressed sends the correct note to be played.
  //The set up for the messages being send for each button are as follows
  // usbMIDI.sendNoteOn(MIDI Note Number, Velocity, Channel)
  //The MIDI Note Number is directly linked to a specific note that can be found
  //on the MIDI musical range. 
  //Here 48 = C, 50 = D, 52 = E, 53 = F, 55 = G, 57 = A, 59 = B and 60 = C
  //These notes make up the C Major Scale.
  
  if (button0.fallingEdge()) {
    usbMIDI.sendNoteOn(48, 99, channel);  // 48 = C3
  }
  if (button1.fallingEdge()) {
    usbMIDI.sendNoteOn(50, 99, channel);  // 50 = D3
  }
  if (button2.fallingEdge()) {
    usbMIDI.sendNoteOn(52, 99, channel);  // 52 = E3
  }
  if (button3.fallingEdge()) {
    usbMIDI.sendNoteOn(53, 99, channel);  // 53 = F3
  }
  if (button4.fallingEdge()) {
    usbMIDI.sendNoteOn(55, 99, channel);  // 55 = G3
  }
  if (button5.fallingEdge()) {
    usbMIDI.sendNoteOn(57, 99, channel);  // 57 = A3
  }
  if (button6.fallingEdge()) {
    usbMIDI.sendNoteOn(59, 99, channel);  // 59 = B3
  }
  if (button7.fallingEdge()) {
    usbMIDI.sendNoteOn(60, 99, channel);  // 60 = C4
  }
 
  //This risingEdge section of the code updates repetetively to make sure any button that had been pressed and triggered a note
  //also has a message to stop the note from playing after the button has been pressed. 
  //FOR EVERY fallingEdge MESSAGE WE NEED A risingEdge!!
  if (button0.risingEdge()) {
    usbMIDI.sendNoteOff(48, 99, channel);  // 48 = C3
  }
  if (button1.risingEdge()) {
    usbMIDI.sendNoteOff(50, 99, channel);  // 50 = D3
  }
  if (button2.risingEdge()) {
    usbMIDI.sendNoteOff(52, 99, channel);  // 52 = E3
  }
  if (button3.risingEdge()) {
    usbMIDI.sendNoteOff(53, 99, channel);  // 53 = F3
  }
  if (button4.risingEdge()) {
    usbMIDI.sendNoteOff(55, 99, channel);  // 55 = G3
  }
  if (button5.risingEdge()) {
    usbMIDI.sendNoteOff(57, 99, channel);  // 57 = A3
  }
  if (button6.risingEdge()) {
    usbMIDI.sendNoteOff(59, 99, channel);  // 59 = B3
  }
  if (button7.risingEdge()) {
    usbMIDI.sendNoteOff(60, 99, channel);  // 60 = C4
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}
