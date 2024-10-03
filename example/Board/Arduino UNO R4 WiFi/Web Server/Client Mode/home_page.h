const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>Braccio Robot Control</title>
  <style>
    body {
      background-color: #F39C11; /* Set background color to Arduino Education orange */
      font-family: Arial, sans-serif;
      margin: 20px;
      padding: 20px;
      text-align: center;
    }
    h1 {
      color: #333;
    }
    input[type="range"] {
      width: 100%;
    }
    .slider-container {
      margin: 10px 0;
    }
    .value-display {
      margin-top: 5px;
      font-weight: bold;
    }
    footer {
      margin-top: 20px;
      font-size: 12px;
      color: #fff; /* Optional: Change footer text color for better contrast */
    }
  </style>
</head>
<body>
  <h1>Braccio Robot Control</h1>

  <!-- Slider for each servo motor -->
  <div class="slider-container">
    <label for="base">Base (M1): </label>
    <input type="range" id="base" min="0" max="180" value="90" oninput="updateValue('base')">
    <div id="baseValue" class="value-display">90</div>
  </div>

  <div class="slider-container">
    <label for="shoulder">Shoulder (M2): </label>
    <input type="range" id="shoulder" min="15" max="165" value="45" oninput="updateValue('shoulder')">
    <div id="shoulderValue" class="value-display">45</div>
  </div>

  <div class="slider-container">
    <label for="elbow">Elbow (M3): </label>
    <input type="range" id="elbow" min="0" max="180" value="180" oninput="updateValue('elbow')">
    <div id="elbowValue" class="value-display">180</div>
  </div>

  <div class="slider-container">
    <label for="wristVer">Wrist Vertical (M4): </label>
    <input type="range" id="wristVer" min="0" max="180" value="180" oninput="updateValue('wristVer')">
    <div id="wristVerValue" class="value-display">180</div>
  </div>

  <div class="slider-container">
    <label for="wristRot">Wrist Rotation (M5): </label>
    <input type="range" id="wristRot" min="0" max="180" value="90" oninput="updateValue('wristRot')">
    <div id="wristRotValue" class="value-display">90</div>
  </div>

  <div class="slider-container">
    <label for="gripper">Gripper (M6): </label>
    <input type="range" id="gripper" min="10" max="73" value="10" oninput="updateValue('gripper')">
    <div id="gripperValue" class="value-display">10</div>
  </div>

  <!-- New Slider for Step Delay -->
  <div class="slider-container">
    <label for="stepDelay">Step Delay (ms): </label>
    <input type="range" id="stepDelay" min="10" max="30" value="20" oninput="updateValue('stepDelay')">
    <div id="stepDelayValue" class="value-display">20</div>
  </div>

  <!-- Buttons to control the servos -->
  <button onclick="sendServoValues()">Set Servos</button>
  <button onclick="resetServos()">Reset Servos</button>

  <footer>
    <p>Copyright (C) 2024 Teeraphat Kullanankanjana</p>
    <p>Contact:</p>
    <p>
      <a href="https://github.com/PerfecXX" style="color: #fff;">GitHub</a><br>
      <a href="https://www.facebook.com/PXTeeraphat/" style="color: #fff;">Facebook</a><br>
      <a href="mailto:ku.teeraphat@gmail.com" style="color: #fff;">ku.teeraphat@gmail.com</a>
    </p>
  </footer>

  <script>
    function updateValue(sliderId) {
      console.log("Updating value for: " + sliderId);
      var value = document.getElementById(sliderId).value;
      var displayElement = document.getElementById(sliderId + 'Value');
      if (displayElement) {
        displayElement.innerText = value;
      } else {
        console.error("Element not found for ID: " + (sliderId + 'Value'));
      }
    }

    function sendServoValues() {
      var base = document.getElementById('base').value;
      var shoulder = document.getElementById('shoulder').value;
      var elbow = document.getElementById('elbow').value;
      var wristVer = document.getElementById('wristVer').value;
      var wristRot = document.getElementById('wristRot').value;
      var gripper = document.getElementById('gripper').value;
      var stepDelay = document.getElementById('stepDelay').value;

      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", `/setServo?base=${base}&shoulder=${shoulder}&elbow=${elbow}&wristVer=${wristVer}&wristRot=${wristRot}&gripper=${gripper}&stepDelay=${stepDelay}`, true);
      xhttp.send();
    }

    function resetServos() {
      document.getElementById('base').value = 90;
      document.getElementById('shoulder').value = 45;
      document.getElementById('elbow').value = 180;
      document.getElementById('wristVer').value = 180;
      document.getElementById('wristRot').value = 90;
      document.getElementById('gripper').value = 10;
      document.getElementById('stepDelay').value = 20;

      updateValue('base');
      updateValue('shoulder');
      updateValue('elbow');
      updateValue('wristVer');
      updateValue('wristRot');
      updateValue('gripper');
      updateValue('stepDelay');

      sendServoValues();
    }
  </script>

</body>
</html>
)rawliteral";
