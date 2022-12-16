[![Display Hardware](https://github.com/FRC-1721/DoomsdayClock/actions/workflows/hardware_workflow.yml/badge.svg)](https://github.com/FRC-1721/DoomsdayClock/actions/workflows/hardware_workflow.yml)
[![Firmware Workflow](https://github.com/FRC-1721/DoomsdayClock/actions/workflows/firmware_workflow.yml/badge.svg)](https://github.com/FRC-1721/DoomsdayClock/actions/workflows/firmware_workflow.yml)


![The sign installed in the build space](Static/installed.jpg)

# Welcome!

This repo contains all the firmware and hardware for Tidal Force's Doomsday Clock!

If you're looking for the latest docs/builds, see our [Releases Page](https://github.com/FRC-1721/DoomsdayClock/releases).

# Getting Started

First, clone this repo (and optionally checkout a branch)

```shell
git clone https://github.com/FRC-1721/DoomsdayClock.git
cd DoomsdayClock
git checkout new_board
```

# Init Submodules

Some libraries and resources are included as submodules, run the following
command to initialize them before opening the main sch

(If you get a missing library error, make sure to do this)

```shell
git submodule update --init --recursive
```
