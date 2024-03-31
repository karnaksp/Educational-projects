#cp ./node_rules.yaml /etc/prometheus/node_rules.yaml
stress -c 2 -i 1 -m 1 --vm-bytes 32M -t 10s

# ws  10.10.0.20
# ws2 10.10.0.10

# iperf3 -s
# iperf3 -c [адрес сервера]