USE airportdb;
CREATE TABLE IF NOT EXISTS `airline` (
  `airline_id` smallint NOT NULL AUTO_INCREMENT,
  `iata` char(2) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `airlinename` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `base_airport` smallint NOT NULL,
  PRIMARY KEY (`airline_id`),
  UNIQUE KEY `iata_unq` (`iata`),
  KEY `base_airport_idx` (`base_airport`),
  CONSTRAINT `airline_ibfk_1` FOREIGN KEY (`base_airport`) REFERENCES `airport` (`airport_id`)
) ENGINE=InnoDB;