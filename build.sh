#!/bin/bash
# vim: set ft=sh ts=4 sw=4 noexpandtab

QMK_USERDIR=/home/avasile/projects/qmk_userspace
QMK_FIRMWARE=/home/avasile/projects/qmk_firmware
keyboard=""

errcho() {
	echo "$@" >&2
}

USAGE="Usage: $0 <command>"

# Check preconditions
for arg; do
	if [ "$arg" = "--help" ]; then
		echo "$USAGE"
		exit 0
	fi
done

userspace_docker_args=""

if [ "$RUNTIME" = "docker" ]; then
	uid_arg="--user $(id -u):$(id -g)"
fi

# Run container and build firmware
docker run --rm -it \
	$uid_arg \
	-w /qmk_firmware \
	-v $QMK_FIRMWARE:/qmk_firmware:z \
    -v $QMK_USERDIR:/qmk_userspace:z \
    -e QMK_USERSPACE=/qmk_userspace \
	-e SKIP_GIT="true" \
	-e SKIP_VERSION="$SKIP_VERSION" \
	-e MAKEFLAGS="$MAKEFLAGS" \
	ghcr.io/qmk/qmk_cli \
	"$@"
