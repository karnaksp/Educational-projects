#!/bin/bash

sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install jq ca-certificates python3 -y
sudo update-ca-certificates
echo "export TERM=xterm-256color" >> /home/vagrant/.bashrc