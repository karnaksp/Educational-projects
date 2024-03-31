##!/bin/bash
source ./utils.sh

echo "Please enter deletion mode."
echo "1 - log file"
echo "2 - date"
echo "3 - name"
read mode

if ! [[ $mode =~ [123] ]]; then
    echo "Incorrect mode."
else
    echo "NEW SESSION $(date +"%F %T")" >> del.log
    list=''; log="../02/gen.log"

    if [ $mode == "1" ]; then
        enterLog
        echo "Deleting files from $log ..."
        list=$(awk '{print $4}' $log | grep /)

    elif [ $mode == "2" ]; then
        from=$(date --date='now -15 minutes' +"%F %T")
        to=$(date +"%F %T")
        from_sec=$(date -d "$from" +%s)
        to_sec=$(date -d "$to" +%s)

        enterDate

        echo "SAFE MODE is on. Files must be [changed in timespan && they are in log]."
        enterLog

        #for file in $(find /*); do  # UNSAFE MODE
        for file in $(awk '{print $4}' $log | grep /); do

            line=$(stat $file 2>/dev/null | grep Access | tail -n1); line=${line%.*}; date=${line#* }
            #date=${line%.*}
            echo $date
            date_sec=$(date -d "$date" +%s)
            if [ $date_sec -ge $from_sec ] && [ $date_sec -le $to_sec ]; then
                list="$list $file"
            fi
        done

    elif [ $mode == "3" ]; then
        mask=''
        enterMask
        letters=${mask%%_*}; letters=$(echo $letters | sed 's/.\{1\}/&+/g')
        extra=_${mask##*_}
        list=$(find / -regextype posix-extended -regex ".*$letters$extra")
    fi

    del_flag=0
    for path in $list; do
        rm -rf $path && if [ $(cat del.log 2>/dev/null | grep -c $path) -eq 0 ]; then
            echo "DELETED $(date +"%F %T") $path" >> del.log; del_flag=1; fi
        rm -rf ${path%/*}
    done

    echo "END OF SESSION $(date +"%F %T")" >> del.log
    if [ $del_flag -eq 1 ]; then
        echo "Deletion is complete. See details in del.log."
    elif [ $del_flag -eq 0 ]; then
        echo "Seems nothing to delete."
    fi
fi
