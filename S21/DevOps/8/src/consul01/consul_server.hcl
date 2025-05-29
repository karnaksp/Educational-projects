datacenter = "dc1"
node_name = "consul"
server = true
bootstrap_expect = 1
ui=true
bind_addr = "0.0.0.0"
client_addr = "0.0.0.0"
advertise_addr = "SELECT_SERVER_IP"

data_dir = "/opt/consul"
log_level = "INFO"

connect {
    enabled = true
}
