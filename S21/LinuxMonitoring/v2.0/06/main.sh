##!/bin/bash

logs="../04/logs"
if ! [ -d $logs ]; then
    echo "No logs to work with. Run ../04/main.sh first."
    exit 1
fi

goaccess -f ../04/logs/nginx_* --log-format=COMBINED > report_all.html
goaccess -f ../04/logs/nginx_* --ignore-status=201 --ignore-status=200 --log-format=COMBINED > report_errors.html
