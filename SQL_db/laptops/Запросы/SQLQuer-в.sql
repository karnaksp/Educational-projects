
SELECT Product, Memory 
INTO #Memory_tp
FROM laptops WHERE Ram IN 
    (SELECT Ram FROM laptops GROUP BY Ram HAVING COUNT(Ram)>1) 
ORDER BY Ram
;

SELECT DISTINCT Product
FROM laptops WHERE Memory IN 
    (SELECT Memory FROM laptops GROUP BY Memory HAVING COUNT(Memory)>1) 
ORDER BY Product
;