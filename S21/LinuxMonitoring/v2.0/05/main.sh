##!/bin/bash

logs="../04/logs"
if ! [ -d $logs ]; then
    echo "No logs to work with. Run ../04/main.sh first."
    exit 1
fi

echo "Choose option:"
echo "1 - All entries sorted by response code"
echo "2 - All unique IPs found in the entries"
echo "3 - All requests with errors (response code - 4xx or 5xxx)"
echo "4 - All unique IPs found among the erroneous requests"

read option

if ! [[ $option =~ [1-4] ]]; then
    echo "Incorrect option."
else
    if [ ! -d "./logs" ]; then mkdir "./logs"; fi
    case "$option" in
    1)
        path="./logs/sorted_by_code.log"
        awk '{print $0|"sort -nk7"}' $logs/* > $path
    ;;
    2)
        path="./logs/unique_ip.log"
        awk '{ a[$1]++ } END { for (b in a) { print b } }' $logs/* | sort > $path
    ;;
    3)
        path="./logs/error_requests.log"
        awk '/[45][0-9][0-9]/{ print $0 }' $logs/* > $path
    ;;
    *)
        path="./logs/error_requests_ip.log"
        awk '/[45][0-9][0-9]/{ a[$1]++ } END { for (b in a) { print b } }' $logs/* | sort > $path
    ;;
    esac
fi
