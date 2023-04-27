USE airportdb;
CREATE TABLE IF NOT EXISTS `airport_reachable` (
  `airport_id` smallint NOT NULL,
  `hops` int DEFAULT NULL,
  PRIMARY KEY (`airport_id`),
  CONSTRAINT `airport_reachable_ibfk_1` FOREIGN KEY (`airport_id`) REFERENCES `airport` (`airport_id`)
) ENGINE=InnoDB;
