const String page PROGMEM = R"(
    <head>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
          <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js'></script>
          <script src='jscript.js'></script>
          <link href='https://fonts.googleapis.com/css2?family=Roboto:wght@300&display=swap' rel='stylesheet'>
          <style>
              body{
                 font-family: 'Roboto', sans-serif;
              }

              h1{
                background: black;
                color: white;
                text-align: center;
              }
         
              #tmm-logo{
                 width:50%;
              }
          </style>
     </head>
     <body>
          <h1>ESP32 Pressure Sensor</h1>
          <p>Uses a ESP32 and MPS20N004D Pressure Sensor</p>
          <p><a href='https://www.teachmemicro.com/esp32-pressure-sensor'>Full tutorial</a></p>
          <label for='pressure-value'>Pressure (kPa):</label> <input type='text' id='pressure-value'></p>
          <table><tr><td><div id='pressure'></div></td></tr>
                 <tr><td style='text-align:right;'><img id='tmm-logo' src='https://i.imgur.com/G80eVhL.png' /></td></tr>
          </table>
     </body>
 )";
