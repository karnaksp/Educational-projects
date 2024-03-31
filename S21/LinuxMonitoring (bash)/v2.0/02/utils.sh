function nameGen {
    i=$(($RANDOM % ${#1}))
    ch=$(echo $1 | cut -c $[ i+1 ])
    echo "${1:0:i}$ch${1:i}"
}

function memStop {
    mem=($(df -h / | grep "/"))
    mem_left=${mem[3]}
    mem_left=${mem_left%G}
    if [[ $mem_left =~ ^[0-9]+([,][0-9]+)?$ ]]; then
        echo 0
    else
        echo 1
    fi
}

date=_$(date +"%d%m%y")
