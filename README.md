### Cinder 0.9.1dev: [libcinder.org](http://libcinder.org)

<p align="center">
  <img src="https://libcinder.org/docs/_assets/images/cinder_logo.svg" alt="Cinder Logo" width="256" height="auto"/>
</p>

<br/>
<br/>

Welcome to the very experimental and unofficial port of Cinder to Emscripten. This is a 'for messing around with' port. It should not be used for production. Use at your own risk. :) 

You can find some demos that have been built with Cinder Emscripten here: [http://chaoticbob.github.io/Cinder-Emscripten](http://chaoticbob.github.io/Cinder-Emscripten).

You are welcome to report any issues here - on this repo. You are also welcome to make any Pull Requests against this repo. 
#### Installing Emscripten
This requires the ``incoming`` version of Emscripten and CMake 3.1. It does not work with ``latest`` as far as I know. So grab the Emscripten portable SDK [from here](https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html). Linux or OS X is hightly recommended! This has not been tested on Windows. Once you have it installed and are ready to go:
```
cd ${YOUR_EMSCRIPTEN_DIR}
./emsdk update
./emsdk install --build=Release sdk-incoming-64bit
./emsdk activate --build=Release sdk-incoming-64bit
```

#### Building Cinder
Source the emsdk_env.sh before you do anything:
```
source ${YOUR_EMSCRIPTEN_DIR}/emsdk_env.sh
```
Once that is done, you're ready to build:
```
cd ${YOUR_CINDER_DIR}/emscripten
./cibuild
```
This should fire off the build process using Clang 3.8 (or later).

#### Building BasicApp
Source the emsdk_env.sh before you do anything:
```
source ${YOUR_EMSCRIPTEN_DIR}/emsdk_env.sh
```
Once that is done, you're ready to build:
```
cd ${YOUR_CINDER_DIR}/samples/BasicApp/emscripten
./cibuild
```

#### Running BasicApp
Lets use the SimpleHTTPServer that comes with Python:
```
cd ${YOUR_CINDER_DIR}/samples/BasicApp/emscripten/Debug/es2
python -m SimpleHTTPServer 8000
```
Now open up your browser and goto: ```http://localhost:8000``` or ```http://127.0.0.1:8000``. Click on the ``BasicApp.html`` file. You should see BasicApp in your browser.

#### Building _opengl/Cube
Source the emsdk_env.sh before you do anything:
```
source ${YOUR_EMSCRIPTEN_DIR}/emsdk_env.sh
```
Once that is done, you're ready to build:
```
cd ${YOUR_CINDER_DIR}/samples/_opengl/Cube/emscripten
./cibuild
```

#### Running _opengl/Cube
Lets use the SimpleHTTPServer that comes with Python:
```
cd ${YOUR_CINDER_DIR}/samples/_opengl/Cube/emscripten/Debug/es2
python -m SimpleHTTPServer 8000
```
Now open up your browser and goto: ```http://localhost:8000``` or ```http://127.0.0.1:8000``. Click on the ``Cube.html`` file. You should see a spinning Cube in your browser.

<br/>
<br/>

#### FAQ
* Which samples currently work?
 *  Samples that can render using ES2 and do not have any direct hardware dependency.
* Noticed that ``es`` is in the path for the samples - do any of the ES3 samples work?
 *  Yes. You'll need to use FireFox nightly or Chrome Canary with WebGL2 enabled. 
* Does audio work?
 *  Not yet. Feel free to make a PR.
* Does video playback work?
 *  Not yet. Feel free to make a PR.
* What about all the stuff from the HTML5 api?
 *  These will get added as time allows. Feel free to make a PR.
  
<br/>
<br/>
<br/>

Also be sure to check the [User Forum](http://discourse.libcinder.org).
