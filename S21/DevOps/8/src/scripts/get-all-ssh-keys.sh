mkdir -p /home/vagrant/.ssh
ssh-keyscan -H 192.168.50.10 >> /home/vagrant/.ssh/known_hosts
ssh-keyscan -H 192.168.50.11 >> /home/vagrant/.ssh/known_hosts
ssh-keyscan -H 192.168.50.12 >> /home/vagrant/.ssh/known_hosts
ssh-keyscan -H 192.168.50.13 >> /home/vagrant/.ssh/known_hosts
