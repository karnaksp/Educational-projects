#!/bin/bash

function chooseTextColor {
  local color
  case "$1" in
      1) color=$textWhite;;
      2) color=$textRed;;
      3) color=$textGreen;;
      4) color=$textBlue;;
      5) color=$textPurple;;
      6) color=$textBlack;;
  esac
  echo "$color"
}

function chooseBgColor {
  local color
  case "$1" in
      1) color=$bgWhite;;
      2) color=$bgRed;;
      3) color=$bgGreen;;
      4) color=$bgBlue;;
      5) color=$bgPurple;;
      6) color=$bgBlack;;
  esac
  echo "$color"
}


function get_network_info {
  hostname=$HOSTNAME
  timezone="$(cat /etc/timezone) UTC $(date +"%-Z")"
  user="$USER"
  os="$(cat /etc/os-release | grep "PRETTY" | awk -F'"' '{print $2}')"
  date="$(date +'%d %b %Y %T')"
  uptime="$(uptime -p)"
  uptimeSec="$(awk -F '.' '{print $1}' /proc/uptime)"
  ipAdress="$(hostname -I | awk '{print $1}')"
  mask="$(ip -o -f inet addr show | awk '/scope global/ {print $4}')"
  gateway="$(ip route | awk '/default/ {print $3}')"
  ramTotal=$(free -b | grep "Mem" | awk '{printf "%.3f GB\n", $2/1024/1024/1024}')
  ramUsed=$(free -b | grep "Mem" | awk '{printf "%.3f GB\n", $3/1024/1024/1024}')
  ramFree=$(free -b | grep "Mem" | awk '{printf "%.3f GB\n", $4/1024/1024/1024}')
  spaceRoot="$(df -BM --output=size / | awk 'NR==2{printf "%.2f MB", $1}')"
  spaceRootFree="$(df -BM --output=avail / | awk 'NR==2{printf "%.2f MB", $1}')"
  spaceRootUsed="$(df -BM --output=used / | awk 'NR==2{printf "%.2f MB", $1}')"

  echo -e "${1}${2}HOSTNAME = ${default}${default}${3}${4}$hostname${default}${default}"
  echo -e "${1}${2}TIMEZONE = ${default}${default}${3}${4}$timezone${default}${default}"
  echo -e "${1}${2}USER = ${default}${default}${3}${4}$user${default}${default}"
  echo -e "${1}${2}OS = ${default}${default}${3}${4}$os${default}${default}"
  echo -e "${1}${2}DATE = ${default}${default}${3}${4}$date${default}${default}"
  echo -e "${1}${2}UPTIME = ${default}${default}${3}${4}$uptime${default}${default}"
  echo -e "${1}${2}UPTIME_SEC = ${default}${default}${3}${4}$uptimeSec${default}${default}"
  echo -e "${1}${2}IP = ${default}${default}${3}${4}$ipAdress${default}${default}"
  echo -e "${1}${2}MASK = ${default}${default}${3}${4}$mask${default}${default}"
  echo -e "${1}${2}GATEWAY = ${default}${default}${3}${4}$gateway${default}${default}"
  echo -e "${1}${2}RAM_TOTAL = ${default}${default}${3}${4}$ramTotal${default}${default}"
  echo -e "${1}${2}RAM_USED = ${default}${default}${3}${4}$ramUsed${default}${default}"
  echo -e "${1}${2}RAM_FREE = ${default}${default}${3}${4}$ramFree${default}${default}"
  echo -e "${1}${2}SPACE_ROOT = ${default}${default}${3}${4}$spaceRoot${default}${default}"
  echo -e "${1}${2}SPACE_ROOT_FREE = ${default}${default}${3}${4}$spaceRootFree${default}${default}"
  echo -e "${1}${2}SPACE_ROOT_USED = ${default}${default}${3}${4}$spaceRootUsed${default}${default}"
}
