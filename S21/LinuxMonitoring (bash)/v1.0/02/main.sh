#!/bin/bash

function get_network_info {
  hostname="HOSTNAME = $HOSTNAME"
  timezone="TIMEZONE = $(cat /etc/timezone) UTC $(date +"%-Z")"
  user="USER = $USER"
  os="OS = $(cat /etc/os-release | grep "PRETTY" | awk -F'"' '{print $2}')"
  date="DATE = $(date +'%d %b %Y %T')"
  uptime="UPTIME = $(uptime -p)"
  uptimeSec="UPTIME_SEC = $(awk -F '.' '{print $1}' /proc/uptime)"
  ipAdress="IP = $(hostname -I | awk '{print $1}')"
  mask="MASK = $(ip -o -f inet addr show | awk '/scope global/ {print $4}')"
  gateway="GATEWAY = $(ip route | awk '/default/ {print $3}')"
  ramT=$(free -b | grep "Mem" | awk '{printf "%.3f GB\n", $2/1024/1024/1024}')
  ramU=$(free -b | grep "Mem" | awk '{printf "%.3f GB\n", $3/1024/1024/1024}')
  ramF=$(free -b | grep "Mem" | awk '{printf "%.3f GB\n", $4/1024/1024/1024}')
  ramTotal="RAM_TOTAL = $ramT"
  ramUsed="RAM_USED = $ramU"
  ramFree="RAM_FREE = $ramF"
  spaceRoot="SPACE_ROOT = $(df -BM --output=size / | awk 'NR==2{printf "%.2f MB", $1}')"
  spaceRootFree="SPACE_ROOT_FREE = $(df -BM --output=avail / | awk 'NR==2{printf "%.2f MB", $1}')"
  spaceRootUsed="SPACE_ROOT_USED = $(df -BM --output=used / | awk 'NR==2{printf "%.2f MB", $1}')"

  echo "$hostname"
  echo "$timezone"
  echo "$user"
  echo "$os"
  echo "$date"
  echo "$uptime"
  echo "$uptimeSec"
  echo "$ipAdress"
  echo "$mask"
  echo "$gateway"
  echo "$ramTotal"
  echo "$ramUsed"
  echo "$ramFree"
  echo "$spaceRoot"
  echo "$spaceRootUsed"
  echo "$spaceRootFree"
}

temp_file=$(mktemp)
get_network_info > "$temp_file"
cat "$temp_file"

echo 
while true; do
    read -p 'Save output to file? [Y/n] ' saveFile
    case $saveFile in
        [Yy]|[Yy][Ee][Ss])
            fileName=$(date +'%d_%m_%y_%H_%M_%S.status')
            cat "$temp_file" >> "$fileName"
            rm "$temp_file"
            break;;
        [Nn]|[Nn][Oo])
            rm "$temp_file"
            exit 0;;
        *) echo "Please enter Yes or No.";;
    esac
done