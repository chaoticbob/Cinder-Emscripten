Welcome to the very experimental and unofficial port of Cinder to Emscripten. This is a 'for messing around with' port. It should not be used for production. Use at your own risk. :) 

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
./build
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
./build
```

#### Running BasicApp
Lets use the SimpleHTTPServer that comes with Python:
```
cd ${YOUR_CINDER_DIR}/samples/BasicApp/emscripten/Debug/es2
python -m SimpleHTTPServer 8000
```
Now open up your browser and goto: ```http://localhost:8000``` or ```http://127.0.0.1:8000`.

### Cinder 0.9.1dev: [libcinder.org](http://libcinder.org)

<p align="center">
  <img src="https://libcinder.org/docs/_assets/images/cinder_logo.svg" alt="Cinder Logo" width="256" height="auto"/>
</p>

**Cinder is a peer-reviewed, free, open source C++ library for creative coding.**

Please note that Cinder depends on a few submodules. The simplest way to clone it is:<br />
```
git clone --recursive https://github.com/cinder/Cinder.git
```

To get started with Cinder from GitHub, please read this [git setup document](https://libcinder.org/docs/guides/git/index.html). You might also prefer one of our [pre-packaged downloads](https://libcinder.org/download).

Cinder supports OS X, Windows and iOS. It requires Xcode 5.1.1 or later for development on the Mac, and Visual C++ 2013 or later on Windows.

Cinder is released under the [Modified BSD License](docs/COPYING). Please visit [our website](https://libcinder.org) for more information.

Also be sure to check the [User Forum](http://forum.libcinder.org/#AllForums).
