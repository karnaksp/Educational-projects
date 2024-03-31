function enterLog {
    echo "The default log path is $log."
    echo "Enter 1 if you wish to use another log."
    read answer
    if [ ! -z $answer ] && [ $answer == "1" ]; then
        log=''
        while [ -z $log ] || [ ! -f $log ]; do
            echo -n "Log file path: "
            read log
            if ! [ -f $log ]; then
                echo "There's no such file. Try again."
            fi
        done
    else
        echo "Default settings are used."
    fi
}

function enterDate {
    echo "The default timespan to delete is the last 15 minutes."
    echo "Enter 1 if you wish to input date by yourself."
    read answer
    if [[ ! -z $answer ]] && [[ $answer == "1" ]]; then
        err=1
        while ! [[ $err -eq 0 ]]; do
            echo -n "FROM "; read from
            echo -n "TO   "; read to
            if ! [[ -z $from || -z $to ]]; then
                err=$(date -d "$from" 2>/dev/null >/dev/null; echo $?)
                err=$(( $err + $(date -d "$to" 2>/dev/null >/dev/null; echo $?) ))
            fi
            if [[ $err -eq 1 ]]; then
                echo "Incorrect time format. Try again."
                echo "You can use yyyy-mm-dd HH:MM format."
            else
                from_sec=$(date -d "$from" +%s 2>/dev/null)
                err=$?
                to_sec=$(date -d "$to" +%s 2>/dev/null)
                err=$(( $err + $? ))
                if ! [[ $err -eq 0 ]]; then
                    echo "There's no such date. Try again."
                elif [[ $from_sec -gt $to_sec ]]; then
                    err=2
                    echo "The first argument must be less than second. Try again."
                fi
            fi
        done
    else
        echo "Default settings are used."
    fi
}

function enterMask {
    echo "Please enter filename mask for files to be deletd."
    format="^[a-zA-Z]{1,7}_[0-9]{6}.?[a-zA-Z]{0,3}$"
    while ! [[ $mask =~ $format ]]; do
        echo "Format is <letters>_<date> or <letters>_<date>.<extension> if there is an extension"
        echo "(The mask 'boka_060606.a' will delete boookaa_060606.a, bbboka_060606.a, boka_060606.a, etc.)"
        read mask
        if ! [[ $mask =~ $format ]]; then
            echo "Incorrect mask. Try again."
        fi
    done
}
