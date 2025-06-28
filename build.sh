#!/bin/bash
# vim: set ft=sh ts=4 sw=4 noexpandtab

QMK_FIRMWARE=/home/avasile/projects/qmk_firmware


# this is from this repo https://github.com/MechboardsLTD/qmk_firmware/tree/corne_max#
# on branch corne_max. by the time you're reading this this should have been upstreamed into qmk (hopefully)
QMK_FIRMWARE_MECHBOARDS=/home/avasile/projects/qmk_firmware_mechboards
QMK_USERDIR=/home/avasile/projects/qmk_userspace
TMP="/tmp/qmk_build"

CORNE_KB="mechboards/crkbd/rp2g"
SOFLE_KB=""

KM="andyterrify"

keyboard=""

errcho() {
	echo "$@" >&2
}

args="$@"

# Check if the directory exists
if [ -d "$TMP" ]; then
    echo "$TMP already present, reusing"
else
    cp -r $QMK_FIRMWARE_MECHBOARDS $TMP
fi

pushd "$TMP"

echo "Cleaning"
qmk clean --all

rm -rf keyboards
cp -r $QMK_USERDIR/keyboards ./keyboards

echo "qmk compile -kb $CORNE_KB -km $KM"
qmk compile -kb $CORNE_KB -km $KM

cp *.uf2 $QMK_USERDIR
