#!/bin/bash

export WAYLAND_DISPLAY=wayland-99

pipenv install -r requirements.txt
pipenv run python -m dstatus --platform wayland
