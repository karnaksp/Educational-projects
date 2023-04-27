-- MySQLShell dump 1.0.2  Distrib Ver 8.0.25 for Linux on x86_64 - for MySQL 8.0.25 (MySQL Community Server (GPL)), for Linux (x86_64)
--
-- Host: 10.0.1.81    Database: airportdb    Table: flight_log
-- ------------------------------------------------------
-- Server version	8.0.26

--
USE airportdb;
CREATE TABLE IF NOT EXISTS `flight_log` (
  `flight_log_id` int unsigned NOT NULL AUTO_INCREMENT,
  `log_date` datetime NOT NULL,
  `user` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `flight_id` int NOT NULL,
  `flightno_old` char(8) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `flightno_new` char(8) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `from_old` smallint NOT NULL,
  `to_old` smallint NOT NULL,
  `from_new` smallint NOT NULL,
  `to_new` smallint NOT NULL,
  `departure_old` datetime NOT NULL,
  `arrival_old` datetime NOT NULL,
  `departure_new` datetime NOT NULL,
  `arrival_new` datetime NOT NULL,
  `airplane_id_old` int NOT NULL,
  `airplane_id_new` int NOT NULL,
  `airline_id_old` smallint NOT NULL,
  `airline_id_new` smallint NOT NULL,
  `comment` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`flight_log_id`),
  KEY `flight_log_ibfk_1` (`flight_id`),
  CONSTRAINT `flight_log_ibfk_1` FOREIGN KEY (`flight_id`) REFERENCES `flight` (`flight_id`)
) ENGINE=InnoDB;
