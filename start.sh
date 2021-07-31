#!/bin/sh

cd /opt/signstatus

git checkout main && git pull
pip3 install -r requirements.txt

python3 signstatus.py
