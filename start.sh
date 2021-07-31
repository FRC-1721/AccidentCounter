#!/bin/sh

cd /opt/dstatus

git checkout master && git pull
pip3 install -r requirements.txt

python3 signstatus.py
