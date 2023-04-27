USE airportdb;
CREATE TABLE IF NOT EXISTS `airplane` (
  `airplane_id` int NOT NULL AUTO_INCREMENT,
  `capacity` mediumint unsigned NOT NULL,
  `type_id` int NOT NULL,
  `airline_id` int NOT NULL,
  PRIMARY KEY (`airplane_id`),
  KEY `type_id` (`type_id`),
  CONSTRAINT `airplane_ibfk_1` FOREIGN KEY (`type_id`) REFERENCES `airplane_type` (`type_id`)
) ENGINE=InnoDB;
