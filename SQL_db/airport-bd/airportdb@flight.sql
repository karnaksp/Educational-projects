USE airportdb;
CREATE TABLE IF NOT EXISTS `flight` (
  `flight_id` int NOT NULL AUTO_INCREMENT,
  `flightno` char(8) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `from` smallint NOT NULL,
  `to` smallint NOT NULL,
  `departure` datetime NOT NULL,
  `arrival` datetime NOT NULL,
  `airline_id` smallint NOT NULL,
  `airplane_id` int NOT NULL,
  PRIMARY KEY (`flight_id`),
  KEY `from_idx` (`from`),
  KEY `to_idx` (`to`),
  KEY `departure_idx` (`departure`),
  KEY `arrivals_idx` (`arrival`),
  KEY `airline_idx` (`airline_id`),
  KEY `airplane_idx` (`airplane_id`),
  KEY `flightno` (`flightno`),
  CONSTRAINT `flight_ibfk_1` FOREIGN KEY (`from`) REFERENCES `airport` (`airport_id`),
  CONSTRAINT `flight_ibfk_2` FOREIGN KEY (`to`) REFERENCES `airport` (`airport_id`),
  CONSTRAINT `flight_ibfk_3` FOREIGN KEY (`airline_id`) REFERENCES `airline` (`airline_id`),
  CONSTRAINT `flight_ibfk_4` FOREIGN KEY (`airplane_id`) REFERENCES `airplane` (`airplane_id`),
  CONSTRAINT `flight_ibfk_5` FOREIGN KEY (`flightno`) REFERENCES `flightschedule` (`flightno`)
) ENGINE=InnoDB;
