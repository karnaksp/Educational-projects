##!/bin/bash

refer=("http://google.com" "http://youtube.com" "http://facebook.com" "http://twitter.com" "http://instagram.com" \
"http://baidu.com" "http://wikipedia.org" "http://yandex.ru" "http://yahoo.com" "http://whatsapp.com")
echo ${refer[$((0 + $RANDOM % 10))]}
