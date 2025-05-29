datacenter = "dc1"
node_name = "SELECT_HOSTNAME"
server = false
advertise_addr = "SELECT_CLIENT_IP"

retry_join = ["SELECT_SERVER_IP"]


ports {
  grpc = 8502
}

data_dir = "/opt/consul"
bind_addr = "0.0.0.0"
log_level = "INFO"

connect {
    enabled = true
}
