#!/bin/bash

# Сборка и сохранение всех необходимых образов
docker build -t akscent/hotel-service:1.0 -f src/services/hotel-service/Dockerfile.hotel src/services/hotel-service
docker save akscent/hotel-service:1.0 > src/images/hotel-service.tar

docker build -t akscent/payment-service:1.0 -f src/services/payment-service/Dockerfile.payment src/services/payment-service
docker save akscent/payment-service:1.0 > src/images/payment-service.tar

docker build -t akscent/loyalty-service:1.0 -f src/services/loyalty-service/Dockerfile.loyalty src/services/loyalty-service
docker save akscent/loyalty-service:1.0 > src/images/loyalty-service.tar

docker build -t akscent/report-service:1.0 -f src/services/report-service/Dockerfile.report src/services/report-service
docker save akscent/report-service:1.0 > src/images/report-service.tar

docker build -t akscent/booking-service:1.0 -f src/services/booking-service/Dockerfile.booking src/services/booking-service
docker save akscent/booking-service:1.0 > src/images/booking-service.tar

docker build -t akscent/session-service:1.0 -f src/services/session-service/Dockerfile.session src/services/session-service
docker save akscent/session-service:1.0 > src/images/session-service.tar

docker build -t akscent/gateway-service:1.0 -f src/services/gateway-service/Dockerfile.gateway src/services/gateway-service
docker save akscent/gateway-service:1.0 > src/images/gateway-service.tar