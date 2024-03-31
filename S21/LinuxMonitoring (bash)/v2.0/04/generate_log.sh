##!/bin/bash
source make_date.sh

n=$((100 + $RANDOM % 901))

time="00:00"
time_local=''
today=$(date --date="today -$1 day" "+%d/%b/%Y")
timezone=$(date "+%z")

remote_user='-'
body_bytes_sent=0

for ((i = 0 ; i < $n ; i++)); do
    remote_addr=$(bash make_ip.sh)
    status=$(bash make_status.sh)
    request=$(bash make_request.sh)
    makeDate
    http_referer=$(bash make_referer.sh)
    http_user_agent=$(bash make_agent.sh)

    echo $remote_addr - $remote_user [$time_local] \"$request\" \
    $status $body_bytes_sent \"$http_referer\" \"$http_user_agent\"
done
