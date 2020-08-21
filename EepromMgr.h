#include <EEPROM.h>

#define EEPROM_MIDI_CH 0
#define EEPROM_KEY_TRACKING 1
#define EEPROM_PITCHBEND 2
#define EEPROM_MODWHEEL_DEPTH 3
#define EEPROM_ENCODER_DIR 4
#define EEPROM_BASSENHANCE_ENABLE 5
#define EEPROM_PICKUP_ENABLE 6

int getMIDIChannel() {
  byte midiChannel = EEPROM.read(EEPROM_MIDI_CH);
  if (midiChannel < 0 || midiChannel > 16) midiChannel = MIDI_CHANNEL_OMNI;//If EEPROM has no MIDI channel stored
  return midiChannel;
}

void storeMidiChannel(byte channel)
{
  EEPROM.update(EEPROM_MIDI_CH, channel);
}

float getKeyTracking() {
  byte keyTracking = EEPROM.read(EEPROM_KEY_TRACKING);
  if (keyTracking == 0) return 0;
  if (keyTracking == 1) return 0.5;
  if (keyTracking == 2) return 1.0;
  return keytrackingAmount; //If EEPROM has no key tracking stored
}

void storeKeyTracking(float keyTracking)
{
  byte keyTrackingByte = keyTracking * 2;//Key tracking is only 0, 0.5, 1.0 at present
  EEPROM.update(EEPROM_KEY_TRACKING, keyTrackingByte);
}

int getPitchBendRange() {
  byte pitchbend = EEPROM.read(EEPROM_PITCHBEND);
  if (pitchbend < 1 || pitchbend > 12) return pitchBendRange; //If EEPROM has no pitchbend stored
  return pitchbend;
}

void storePitchBendRange(byte pitchbend)
{
  EEPROM.update(EEPROM_PITCHBEND, pitchbend);
}

float getModWheelDepth() {
  byte mw = EEPROM.read(EEPROM_MODWHEEL_DEPTH);
  if (mw < 1 || mw > 10) return modWheelDepth; //If EEPROM has no mod wheel depth stored
  return mw / 10.0f;
}

void storeModWheelDepth(float mwDepth)
{
  byte mw =  mwDepth * 10;
  EEPROM.update(EEPROM_MODWHEEL_DEPTH, mw);
}

boolean getEncoderDir() {
  byte ed = EEPROM.read(EEPROM_ENCODER_DIR);
  if (ed < 0 || ed > 1)return true; //If EEPROM has no encoder direction stored
  return ed == 1 ? true : false;
}

void storeEncoderDir(byte encoderDir)
{
  EEPROM.update(EEPROM_ENCODER_DIR, encoderDir);
}

boolean getPickupEnable() {
  byte pu = EEPROM.read(EEPROM_PICKUP_ENABLE); 
  if (pu < 0 || pu > 1)return false; //If EEPROM has no pickup enable stored
  return pu == 1 ? true : false;
}

void storePickupEnable(byte pickupEnable){
  EEPROM.update(EEPROM_PICKUP_ENABLE, pickupEnable);
}


boolean getBassEnhanceEnable() {
  byte eh = EEPROM.read(EEPROM_BASSENHANCE_ENABLE);
  if (eh < 0 || eh > 1)return false; //If EEPROM has no bass enhance enable stored
  return eh == 1 ? true : false;
}

void storeBassEnhanceEnable(byte bassEnhanceEnable) {
  EEPROM.update(EEPROM_BASSENHANCE_ENABLE, bassEnhanceEnable);
}
