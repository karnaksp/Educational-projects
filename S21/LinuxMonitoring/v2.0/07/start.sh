##!/bin/bash

#sudo cp ./services/prometheus.service /etc/systemd/system/prometheus.service
#sudo cp ./services/node_exporter.service /etc/systemd/system/node_exporter.service

#sudo systemctl daemon-reload
sudo systemctl start prometheus
sudo systemctl start node_exporter
sudo snap start grafana
