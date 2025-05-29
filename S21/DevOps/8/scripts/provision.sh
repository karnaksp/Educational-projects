#!/bin/bash

sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install jq -y
echo "export TERM=xterm-256color" >> /home/vagrant/.bashrc
echo "192.168.50.10 manager" >> /etc/hosts
echo "192.168.50.11 consul_server" >> /etc/hosts
echo "192.168.50.12 api" >> /etc/hosts
echo "192.168.50.13 db" >> /etc/hosts
