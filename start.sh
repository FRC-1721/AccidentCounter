#!/bin/sh

cd /opt/signstatus

git checkout master && git pull
pip3 install -r requirements.txt

python3 signstatus.py
