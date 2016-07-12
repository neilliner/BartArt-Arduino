# BartArt + Arduino

## Overview
Inspired by Camille Utterback’s art work, Entangled, and Alan Rath’s Four Eyes, this is an experimental web app project integrating with Bart API and Arduino board. In browser there is a full screen canvas displaying pop art components. The real time data of Bart system will trig- ger the flying crows. Therefore, when Bart is coming, the crow starts flying. Also, there is ZX sensor that triggers hand flipping and scene changing. So when audience’s hand gets closer, the scene zooms in until the clock and the beating heart appears.

## Technology

HTML, CSS, JavaScript, P5.js, Node.js, Arduino, BART API

## Instructions
1. Download everything from this Repo.
2. Wire the breadboard to Arduino UNO as pictured.
3. Connect the board to your computer.
4. Install the firmware using the .ino file provided.
5. In the project folder, run the app.js file by type `$ node app.js` in the terminal(assumed you have node.js installed).
6. Open your browser and type `localhost:3000` then hit return.
7. Enjoy!

## Screenshots

![BartArt](http://www.neilsite.com/bandpay/sites/default/files/bartart1.jpg "BartArt")

![BartArt](http://www.neilsite.com/bandpay/sites/default/files/bartart2.jpg "BartArt")

![BartArt](http://www.neilsite.com/bandpay/sites/default/files/bartart3.jpg "BartArt")

## Wiring

![Board wiring](https://github.com/neilliner/BartArt-Arduino/blob/master/arduino_firmware_and_wiring/bartart-wiring.jpg "Board wiring")

## No Arduino Version
To make it easier to experience the project, I made a version that doesn't need to connect to Arduino. Check it out.
[No Arduino Version](https://github.com/neilliner/BartArt-NoBoard)

### Special Thanks
[Mark Hellar](https://github.com/mhellar)
