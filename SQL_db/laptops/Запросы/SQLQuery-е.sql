SELECT chop_name AS Shop, COUNT(DISTINCT Product) AS Poructs_number
FROM laptops 
      INNER JOIN shops ON laptops.id_shop = shops.shop_id
GROUP BY chop_name
ORDER BY Poructs_number DESC;