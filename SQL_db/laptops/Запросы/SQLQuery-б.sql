SELECT * 
INTO #Memory_SSD
FROM laptops WHERE Memory LIKE '%SSD%'
;

SELECT DISTINCT Product
FROM laptops WHERE Memory LIKE '%HDD%'
;