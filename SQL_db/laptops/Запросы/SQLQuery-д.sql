
SELECT chop_name AS Shop, Price_euros 
FROM laptops 
      INNER JOIN shops ON laptops.id_shop = shops.shop_id
WHERE Price_euros < ALL (SELECT AVG(Price_euros) AS Price_euros
FROM laptops)
ORDER BY Price_euros;

