#!/bin/bash

# sudo nano /etc/nginx/nginx.conf
# http://localhost:9110/metrics

# sudo cp ./my_metrics.service /etc/systemd/system/my_metrics.service
# sudo systemctl start my_metrics.service

source ./names.sh

while true; do
	echo "# HELP part9_cpu_used_in_percent The total CPU used as percent value" > $metrics
	echo "# TYPE part9_cpu_used_in_percent gauge" >> $metrics
	cpu=$(mpstat | awk 'NR==4 {print $12}')
	cpu=$(echo "100 - ${cpu/","/"."}" | bc | awk '{printf "%.2f", $0}')
	echo "part9_cpu_used_in_percent $cpu" >> $metrics

	echo "# HELP part9_disk_used_in_percent The total number of bytes free in home directory" >> $metrics
	echo "# TYPE part9_disk_used_in_percent gauge" >> $metrics
	disk=$(df / | awk 'NR==2 {print $5}')
	echo "part9_disk_used_in_percent ${disk%"%"}" >> $metrics

	echo "# HELP part9_mem_used_in_percent RAM used as percent value" >> $metrics
	echo "# TYPE part9_mem_used_in_percent gauge" >> $metrics
	mem=$(bc <<< "scale=2; $(free | awk 'NR==2 {print $3}') / $(free | awk 'NR==2 {print $2}') * 100")
	echo "part9_mem_used_in_percent $mem" >> $metrics

	cp ./$metrics /data/www/metrics/index.html

	sleep 5
done
