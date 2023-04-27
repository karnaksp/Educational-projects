USE airportdb;
CREATE TABLE IF NOT EXISTS `airport_geo` (
  `airport_id` smallint NOT NULL,
  `name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `city` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `country` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `latitude` decimal(11,8) NOT NULL,
  `longitude` decimal(11,8) NOT NULL,
  `geolocation` point NOT NULL,
  PRIMARY KEY (`airport_id`),
  SPATIAL KEY `geolocation_spt` (`geolocation`),
  CONSTRAINT `airport_geo_ibfk_1` FOREIGN KEY (`airport_id`) REFERENCES `airport` (`airport_id`)
) ENGINE=InnoDB;
