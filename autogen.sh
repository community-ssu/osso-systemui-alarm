#!/bin/sh

set -ex
touch ChangeLog NEWS README
mkdir m4
autoreconf --install --force 
