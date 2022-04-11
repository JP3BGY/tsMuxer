#!/usr/bin/env bash

export MACOSX_DEPLOYMENT_TARGET=11.0
qtver=6

export QT_HOME="$HOME/Qt/6.2.4/macos"
export PATH="/opt/homebrew/bin:$QT_HOME/bin"
EXTRA_CMAKE_ARGS=("-DCMAKE_PREFIX_PATH=$QT_HOME/lib/cmake")

source macos_common_build.sh
