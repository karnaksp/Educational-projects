#!/bin/bash
/usr/bin/consul connect envoy -sidecar-for $(cat /etc/consul.d/*.json | awk '/name/{print $2}' | sed 's/\,//g' | sed 's/\"//g' | head -n1) --ignore-envoy-compatibility

