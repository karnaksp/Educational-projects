SELECT chop_name AS Shop, Product, CPU, GPU
FROM laptops 
      INNER JOIN shops ON laptops.id_shop = shops.shop_id
WHERE CPU NOT LIKE '%Intel%' OR GPU NOT LIKE '%AMD%'
INTERSECT
SELECT chop_name AS Shop, Product, CPU, GPU
FROM laptops 
      INNER JOIN shops ON laptops.id_shop = shops.shop_id
WHERE CPU NOT LIKE '%AMD%' OR GPU NOT LIKE '%Intel%';
