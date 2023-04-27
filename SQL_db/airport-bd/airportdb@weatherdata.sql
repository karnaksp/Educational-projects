USE airportdb;
CREATE TABLE IF NOT EXISTS `weatherdata` (
  `log_date` date NOT NULL,
  `time` time NOT NULL,
  `station` int NOT NULL,
  `temp` decimal(3,1) NOT NULL,
  `humidity` decimal(4,1) NOT NULL,
  `airpressure` decimal(10,2) NOT NULL,
  `wind` decimal(5,2) NOT NULL,
  `weather` enum('Туман-снегопад','Снегопад','Дождь','Дождь-снегопад','Туман-дождь','Туман-дождь-гроза','Гроза','Nebel','Дождь-гроза') CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `winddirection` smallint NOT NULL,
  PRIMARY KEY (`log_date`,`time`,`station`)
) ENGINE=InnoDB;
