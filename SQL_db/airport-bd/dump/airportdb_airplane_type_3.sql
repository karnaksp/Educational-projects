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
-- Table structure for table `airplane_type`
--

DROP TABLE IF EXISTS `airplane_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `airplane_type` (
  `type_id` int NOT NULL AUTO_INCREMENT,
  `identifier` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`type_id`),
  FULLTEXT KEY `description_full` (`identifier`)
) ENGINE=InnoDB AUTO_INCREMENT=343 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `airplane_type`
--

LOCK TABLES `airplane_type` WRITE;
/*!40000 ALTER TABLE `airplane_type` DISABLE KEYS */;
INSERT INTO `airplane_type` VALUES (1,'Concorde'),(2,'Tupolew Tu-144'),(3,'Ultraleichtflugzeug'),(4,'Flugboot'),(5,'Dornier Do X'),(6,'Airbus A380'),(7,'Airbus A310'),(8,'Bristol Brabazon'),(9,'Boeing B-377'),(10,'Antonow An-225'),(11,'Antonow An-124'),(12,'ATR 42'),(13,'ATR 72'),(14,'Douglas DC-3'),(15,'Saab 340'),(16,'Saab 2000'),(17,'Junkers F 13'),(18,'Airbus A330'),(19,'Fokker 50'),(20,'Airbus A340'),(21,'Boeing 747'),(22,'Iljuschin Il-86'),(23,'Boeing 787'),(24,'Junkers W 33'),(25,'Boeing B-307'),(26,'Junkers W 34'),(27,'Junkers G 38'),(28,'Junkers Ju 46'),(29,'Junkers J 15'),(30,'Junkers A 20'),(31,'Lockheed L-188'),(32,'Junkers S 36'),(33,'Junkers Ju 52/3m'),(34,'Lockheed L-1011'),(35,'Antonow An-2'),(36,'Cessna 172'),(37,'Boeing 757'),(38,'Boeing 767'),(39,'Boeing 717'),(40,'Fokker 70'),(41,'Fokker 100'),(42,'Learjet 31'),(43,'Learjet 40'),(44,'Dornier 328'),(45,'Tupolew Tu-154'),(46,'HFB 320'),(47,'Embraer EMB 120'),(48,'Douglas DC-9'),(49,'Learjet'),(50,'Learjet 23'),(51,'Learjet 24'),(52,'Learjet 25'),(53,'Learjet 28'),(54,'Learjet 29'),(55,'Learjet 35'),(56,'Learjet 36'),(57,'De Havilland D.H.88'),(58,'Cessna 170'),(59,'Boeing 707'),(60,'McDonnell Douglas DC-10'),(61,'Learjet 45'),(62,'VFW 614'),(63,'SAI KZ I'),(64,'Piper PA-42'),(65,'Adam A700'),(66,'Boeing 727'),(67,'Bohemia B-5'),(68,'Blackburn B-2'),(69,'DG-800'),(70,'Douglas DC-8'),(71,'Rolladen Schneider LS8'),(72,'Douglas DC-4'),(73,'Antonow An-22'),(74,'Tupolew Tu-104'),(75,'Bombardier Q Series'),(76,'Cessna 140'),(77,'Heinkel He 70'),(78,'Short S.23'),(79,'Himmelslaus'),(80,'Dornier Wal'),(81,'Dornier Do 26'),(82,'Douglas DC-6'),(83,'A.B.C. Robin'),(84,'McDonnell Douglas MD-11'),(85,'Convair CV 110'),(86,'Convair CV 240'),(87,'Piper J-3'),(88,'Convair CV 340'),(89,'Gulfstream IV'),(90,'Avro Canada C-102'),(91,'Piper PA-28'),(92,'Boeing 2707'),(93,'Douglas DC-1'),(94,'Douglas DC-2'),(95,'Iljuschin Il-62'),(96,'Martin JRM'),(97,'Lissunow Li-2'),(98,'Antonow An-70'),(99,'Antonow An-38'),(100,'Ayres LM200 Loadmaster'),(101,'Gulfstream V'),(102,'Schleicher K 7'),(103,'Schempp-Hirth Discus'),(104,'Airbus A350'),(105,'Douglas DC-5'),(106,'Scheibe SF 25'),(107,'Dornier Do 27'),(108,'Avro 510'),(109,'Avro 514'),(110,'Antonow An-24'),(111,'Antonow An-3'),(112,'DG-200'),(113,'Antonow An-4'),(114,'Antonow An-6'),(115,'Lockheed Super Constellation'),(116,'Focke-Wulf Fw 200'),(117,'Avro Curtiss-type'),(118,'Burga Monoplane'),(119,'Antonow An-14'),(120,'Dassault Mercure'),(121,'Jakowlew Jak-16'),(122,'Douglas DC-7'),(123,'DFS Kranich'),(124,'Jakowlew Jak-12'),(125,'Tupolew Tu-114'),(126,'Iljuschin Il-96'),(127,'Antonow An-30'),(128,'Antonow An-32'),(129,'Antonow An-72'),(130,'Antonow An-140'),(131,'Antonow An-148'),(132,'Moller Skycar'),(133,'ChAI-1'),(134,'Tupolew Tu-334'),(135,'Lockheed Starliner'),(136,'Lockheed Modell 10'),(137,'Putilow Stal-2'),(138,'Hawker Siddeley HS-125'),(139,'BAC 1-11'),(140,'Vickers Viscount'),(141,'ChAI-3'),(142,'DFS Habicht'),(143,'CriCri'),(144,'Short 360'),(145,'Vickers Vanguard'),(146,'Tupolew Tu-124'),(147,'Vickers VC.1'),(148,'Pilatus PC-12'),(149,'Eclipse 500'),(150,'DG-100'),(151,'Boeing 314'),(152,'High Altitude and Long Range Research Aircraft'),(153,'DG-300'),(154,'Schleicher ASW 28'),(155,'Aviation Traders ATL-98'),(156,'Convair CV 880'),(157,'Suchoi Superjet 100'),(158,'De Havilland D.H.91'),(159,'Let L-610'),(160,'Boeing 367-80'),(161,'Fairchild F-27'),(162,'Cessna Skymaster'),(163,'Boeing 7J7'),(164,'Mjassischtschew M-17'),(165,'Avro Type F'),(166,'Avro 748'),(167,'Beechcraft Bonanza'),(168,'NAMC YS-11'),(169,'Avro 539'),(170,'Avro 536'),(171,'Avro 547'),(172,'Avro 534'),(173,'Avro 548'),(174,'BAe 146'),(175,'Beechcraft Model 77'),(176,'IAI 1124'),(177,'Avro 558'),(178,'Bristol Boxkite'),(179,'Dornier Seastar'),(180,'Avro 576'),(181,'Avro 581'),(182,'Avro 594'),(183,'DG-400'),(184,'Avro 618'),(185,'Avro 619'),(186,'Grigorowitsch M-1'),(187,'Grigorowitsch M-2'),(188,'Avro 642'),(189,'PZL Bielsko SZD-9'),(190,'PZL Bielsko SZD-36'),(191,'Lo 100'),(192,'Schleicher ASW 27'),(193,'Grigorowitsch DG-55'),(194,'PZL-106'),(195,'Learjet 60'),(196,'SG 38'),(197,'Fokker F.VII'),(198,'Aermacchi SF-260'),(199,'Reims-Cessna F406'),(200,'Grob G 109'),(201,'Sopwith Tabloid'),(202,'Grob G 103'),(203,'ChAI-17'),(204,'Heinkel HD 24'),(205,'Epic Aircraft Epic LT'),(206,'Cessna 185'),(207,'Cessna L-19'),(208,'Convair CV 990'),(209,'DG-1000'),(210,'Schleicher ASW 24'),(211,'Raytheon Hawker 800'),(212,'Stemme S 10'),(213,'Wright Flyer III'),(214,'Benoist XIV'),(215,'Embraer EMB 200'),(216,'Curtiss F'),(217,'Cirrus SR22'),(218,'Antoinette VII'),(219,'Farman F.402'),(220,'Cessna 182'),(221,'Aviation Traders ATL-90'),(222,'Channelwing'),(223,'Russki Witjas'),(224,'Arado Ar 79'),(225,'Farman F.60'),(226,'ChAI-33'),(227,'ChAI-35'),(228,'Airbus-A320-Familie'),(229,'Comac ARJ21'),(230,'Pitts Special'),(231,'Bombardier Canadair Regional Jet'),(232,'Embraer-ERJ-145-Familie'),(233,'Dornier Do 12'),(234,'Farman III'),(235,'DG-500'),(236,'Extra 300L'),(237,'Schleicher ASK 23'),(238,'Zlin Z-326'),(239,'Dornier Do A'),(240,'Schleicher ASW 20'),(241,'Klemm Kl 151'),(242,'Schleicher ASH 26'),(243,'Schleicher ASG 29'),(244,'Grunau 9'),(245,'Dassault Falcon 900'),(246,'Zivko Edge 540'),(247,'Avia BH-1'),(248,'Savoia-Marchetti SM.75'),(249,'Entwicklungsgeschichte von der Douglas DC-9 bis zu'),(250,'Caudron C.440'),(251,'Dassault Falcon 20'),(252,'Extra 300'),(253,'Siebert Sie 3'),(254,'Saunders ST-27'),(255,'PZL Bielsko SZD-45'),(256,'Tupolew Tu-107'),(257,'Piaggio PD.808'),(258,'Martin 4-0-4'),(259,'Macchi M.33'),(260,'Supermarine S.6'),(261,'Fieseler Fi 97'),(262,'Emivest Aerospace SJ30'),(263,'Cap 232'),(264,'Cessna 310'),(265,'Caproni Ca.97'),(266,'Caproni Ca.73'),(267,'Handley Page Jetstream'),(268,'Cessna Citation II'),(269,'Cessna Citation III'),(270,'Cessna Citation X'),(271,'Extra EA-400'),(272,'Atlas C4M'),(273,'Barkley-Grow T8P-1'),(274,'Lockheed Modell 12'),(275,'Eclipse 400'),(276,'Zlin Z-526'),(277,'Cessna 421'),(278,'Cessna 425'),(279,'Focke-Wulf Fw 47'),(280,'Cessna 401'),(281,'Canadair North Star'),(282,'Doppelraab'),(283,'Fieseler F 5'),(284,'Armstrong Whitworth A.W.27'),(285,'Gulfstream III'),(286,'Vickers Vulcan'),(287,'Canadair CL-44'),(288,'Embraer EMB 121'),(289,'Embraer EMB 111'),(290,'VEF Irbitis I-12'),(291,'Hawker 4000'),(292,'Wedell-Williams 44'),(293,'Extra 260'),(294,'Bristol Type 62'),(295,'Bristol Tourer'),(296,'Hughes H-1'),(297,'Piper Apache'),(298,'Supermarine S.4'),(299,'Stinson Reliant'),(300,'Fokker F.VIII'),(301,'Boeing 777'),(302,'Cessna CitationJet'),(303,'North American T-39'),(304,'Learjet 85'),(305,'Potez 62'),(306,'Potez 840'),(307,'Cessna 206'),(308,'Sud-Est SE.2010'),(309,'CASA C-207'),(310,'CASA C-202'),(311,'SNCAC NC.211'),(312,'CASA C-201'),(313,'Fokker F.XXXVI'),(314,'Airbus A300'),(315,'Martin 2-0-2'),(316,'Boeing 737'),(317,'Savoia-Marchetti SM.95'),(318,'Vultee V-1'),(319,'Bloch MB.120'),(320,'Curtiss T-32'),(321,'Bloch MB.300'),(322,'Dufaux 4'),(323,'Dufaux 5'),(324,'Mitsubishi Regional Jet'),(325,'Fieseler F 4'),(326,'Fokker F.IX'),(327,'Fokker F.XI'),(328,'Cessna 180'),(329,'Lancair IV'),(330,'Kalinin K-2'),(331,'Kalinin K-3'),(332,'Heinkel HE 12'),(333,'Comac C919'),(334,'Zieldarstellungsdrohne'),(335,'Air Tractor AT-802'),(336,'CSA SportCruiser'),(337,'DFS Weihe'),(338,'British Aircraft Swallow'),(339,'Aero Boero AB-115'),(340,'Aero Boero AB-180'),(341,'British Aircraft Double Eagle'),(342,'Epic Victory');
/*!40000 ALTER TABLE `airplane_type` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-12-12 14:04:55
