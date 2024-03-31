##!/bin/bash

sudo cp ./services/prometheus.service /etc/systemd/system/prometheus.service
sudo cp ./services/node_exporter.service /etc/systemd/system/node_exporter.service
sudo cp ./node_rules.yaml /etc/prometheus/node_rules.yaml
sudo cp ./node_alerts.yaml /etc/prometheus/node_alerts.yaml

sudo systemctl daemon-reload
sudo systemctl start prometheus
sudo systemctl start node_exporter
sudo snap start grafana
