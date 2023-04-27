
CREATE TABLE `passenger_details` (
  `passenger_id` int NOT NULL,
  `birthdate` date DEFAULT NULL,
  `sex` char(1) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `city` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `country` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `passportno` char(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  UNIQUE KEY `pass_unq` (`passportno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
INSERT INTO `passenger_details` (`passenger_id`)
SELECT
	`passenger_id` AS `passenger_id`
FROM
	`passengers`;
ALTER TABLE `passenger_details`
ADD PRIMARY KEY (`passenger_id`),
ADD CONSTRAINT `passenger_details_ibfk_1` FOREIGN KEY (`passenger_id`) REFERENCES `passengers` (`passenger_id`) ON DELETE CASCADE;
SET SQL_SAFE_UPDATES=0;
UPDATE `passenger_details` SET `passportno` = FLOOR(RAND()*(9999999999-1000000000+1))+1000000000;
UPDATE `passenger_details` SET `birthdate` = DATE_ADD('2005-11-02', INTERVAL ROUND(-1*RAND()*10000,0) DAY);
UPDATE `passenger_details` SET `sex` = CASE WHEN ROUND(RAND()) = 0
                  THEN 'М'
                  ELSE 'Ж' END;
SET SQL_SAFE_UPDATES=1;
