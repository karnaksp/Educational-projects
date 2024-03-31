function makeDate {
    time="$(date --date="$time +minute" "+%H:%M")"
    time_local="$today:$time:$((10 + $RANDOM % 50)) $timezone"
}
