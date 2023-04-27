-- MySQL dump 10.13  Distrib 8.0.31, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: airportdb
-- ------------------------------------------------------
-- Server version	8.0.31

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `airline`
--

DROP TABLE IF EXISTS `airline`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `airline` (
  `airline_id` smallint NOT NULL AUTO_INCREMENT,
  `iata` char(2) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `airlinename` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `base_airport` smallint NOT NULL,
  PRIMARY KEY (`airline_id`),
  UNIQUE KEY `iata_unq` (`iata`),
  KEY `base_airport_idx` (`base_airport`),
  CONSTRAINT `airline_ibfk_1` FOREIGN KEY (`base_airport`) REFERENCES `airport` (`airport_id`)
) ENGINE=InnoDB AUTO_INCREMENT=114 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `airline`
--

LOCK TABLES `airline` WRITE;
/*!40000 ALTER TABLE `airline` DISABLE KEYS */;
INSERT INTO `airline` VALUES (1,'AF','Afghanistan Airlines',850),(4,'AN','Angola Airlines',190),(5,'AR','Argentina Airlines',285),(6,'AU','Australia Airlines',73),(7,'AZ','Azerbaijan Airlines',1216),(8,'BA','Bahamas Airlines',405),(11,'BO','Bolivia Airlines',466),(12,'BR','Brazil Airlines',93),(16,'CH','Chad Airlines',27),(17,'CO','Colombia Airlines',118),(19,'CU','Cuba Airlines',28),(20,'CY','Cyprus Airlines',168),(23,'DE','Denmark Airlines',7),(24,'DJ','Djibouti Airlines',343),(27,'EG','Egypt Airlines',46),(29,'EQ','Equatorial Guinea Ai',965),(30,'ER','Eritrea Airlines',613),(32,'ET','Ethiopia Airlines',4),(35,'FR','France Airlines',146),(36,'GA','Gabon Airlines',1257),(40,'GR','Greece Airlines',111),(41,'GU','Guadeloupe Airlines',794),(44,'HU','Hungary Airlines',815),(45,'IC','Iceland Airlines',174),(46,'IN','India Airlines',103),(47,'IR','Iran Airlines',15),(49,'IT','Italy Airlines',197),(50,'IV','Ivory Coast Airlines',29),(54,'KA','Kazakhstan Airlines',169),(55,'KE','Kenya Airlines',342),(57,'KO','Korea Airlines',5),(60,'LA','Laos Airlines',661),(61,'LE','Lebanon Airlines',1051),(66,'MI','Micronesia Airlines',730),(68,'MY','Myanmar Airlines',771),(69,'NA','Namibia Airlines',488),(70,'NE','Nepal Airlines',775),(71,'NI','Nicaragua Airlines',1307),(74,'PA','Pakistan Airlines',261),(75,'PE','Peru Airlines',218),(76,'PH','Philippines Airlines',744),(77,'PO','Poland Airlines',732),(81,'RO','Romania Airlines',480),(82,'RU','Russia Airlines',17),(85,'SE','Senegal Airlines',804),(86,'SI','Sierra Leone Airline',1314),(89,'SP','Spain Airlines',1),(90,'SR','Sri Lanka Airlines',363),(92,'SU','Sudan Airlines',634),(94,'SY','Syria Airlines',220),(96,'TH','Thailand Airlines',873),(100,'UG','Uganda Airlines',580),(102,'UN','United Arab Emirates',45),(103,'UR','Uruguay Airlines',576),(105,'VA','Vanuatu Airlines',987),(106,'VE','Venezuela Airlines',202),(110,'YE','Yemen Airlines',25),(111,'YU','Yugoslavia Airlines',1062);
/*!40000 ALTER TABLE `airline` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-12-12 14:04:56
