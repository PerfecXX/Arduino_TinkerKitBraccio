#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = "replace_your_ssid";    // Network SSID (name)
const char PASS[]     = "replace_your_password";    // Network password (use for WPA, or use as key for WEP)

void onBaseAngleChange();
void onElbowAngleChange();
void onGripperAngleChange();
void onShoulderAngleChange();
void onStepDelayChange();
void onWristRotAngleChange();
void onWristVerAngleChange();
void onResetStateChange();

int base_angle;
int elbow_angle;
int gripper_angle;
int shoulder_angle;
int step_delay;
int wrist_rot_angle;
int wrist_ver_angle;
bool reset_state;

void initProperties(){

  ArduinoCloud.addProperty(base_angle, READWRITE, ON_CHANGE, onBaseAngleChange);
  ArduinoCloud.addProperty(elbow_angle, READWRITE, ON_CHANGE, onElbowAngleChange);
  ArduinoCloud.addProperty(gripper_angle, READWRITE, ON_CHANGE, onGripperAngleChange);
  ArduinoCloud.addProperty(shoulder_angle, READWRITE, ON_CHANGE, onShoulderAngleChange);
  ArduinoCloud.addProperty(step_delay, READWRITE, ON_CHANGE, onStepDelayChange);
  ArduinoCloud.addProperty(wrist_rot_angle, READWRITE, ON_CHANGE, onWristRotAngleChange);
  ArduinoCloud.addProperty(wrist_ver_angle, READWRITE, ON_CHANGE, onWristVerAngleChange);
  ArduinoCloud.addProperty(reset_state, READWRITE, ON_CHANGE, onResetStateChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
